#include<QGraphicsSceneMouseEvent>
#include<QJsonObject>
#include <QDebug>
#include "TLWbScene.h"
#include "TLWbShape.h"
#include "TLWbLine.h"
#include "TLWbRectangle.h"
#include "TLWbOval.h"
#include "TLWbTriangle.h"
#include "TLWbGraffiti.h"
#include "TLWbToolForm.h"

TLWbScene::TLWbScene(QObject *parent) : QGraphicsScene(parent)
{
    m_toolType = TOOL_LINE;
    m_currentShape = nullptr;
    m_toolForm = nullptr;
    m_id = -1;
}

TLWbScene:: ~TLWbScene()
{

}

void TLWbScene::setTooLFrom(TLWbToolForm* toolForm)
{
    m_toolForm = toolForm;
}

void TLWbScene::setUserId(int id)
{
    m_id = id;
}

void TLWbScene::addFigure(const QJsonObject& figure)
{
    TLWbShape *shape = nullptr;
    QJsonObject data = figure.value("data").toObject();
    QJsonArray points = data.value("points").toArray();
    int type = figure.value("figure_type").toInt();

    int creatorId = figure.value("creator_id").toInt();
    int localId = figure.value("local_id").toInt();
    int globalId = figure.value("global_id").toInt();

    if(creatorId == m_id)
    {
        auto it = std::find_if(m_shapeList.rbegin(),m_shapeList.rend(),
                               [=](TLWbShape* s)
        {
           return (s->getUserId() == creatorId && s->getLocalId() == localId);
        });
        if(it != m_shapeList.rend())
        {
            qDebug() << "update figure global id" << globalId;
            (*it)->setGlobalId(globalId);
            int k = 0;
            return;
        }
    }

    if(type == TOOL_LINE)
    {
        shape = new TLWbLine();
        setShapePos(shape,points);
    }

    else if(type == TOOL_RECTANGLE)
    {
        shape = new TLWbRectangle();
        setShapePos(shape,points);
    }

    else if(type == TOOL_OVAL)
    {
        shape = new TLWbOval();
        setShapePos(shape,points);
    }

    else if(type == TOOL_TRIANGLE)
    {
        shape = new TLWbTriangle();
        setShapePos(shape,points);
    }

    else if(type == TOOL_GRAFFITI)
    {
        TLWbGraffiti* gra = new TLWbGraffiti();
        shape = gra;
        QPainterPath path;
        int size = points.size();
        if(size > 2)
        {
            path.moveTo(points[0].toInt(),points[1].toInt());
            for(int i = 2; i < size; i+= 2)
            {
                path.lineTo(points[i].toInt(),points[i+1].toInt());
            }
        }
        gra->setPath(path);
    }

    else
    {
        qDebug() << "unknown figure type!";
    }

    shape->setUserId(creatorId);
    shape->setGlobalId(globalId);
    shape->setLocalId(localId);
    shape->setStrokeWidth(data.value("line_width").toInt());
    shape->setStrokeColor(QColor::fromRgba((unsigned int)data.value("color").toDouble()));
    shape->setFillColor(QColor::fromRgba((unsigned int)data.value("fill_color").toDouble()));

    addItem(shape);
    m_shapeList.push_back(shape);
    update();
}

void TLWbScene::deleteFigure(const int globalId)
{
    auto it = std::find_if(m_shapeList.begin(),m_shapeList.end(),
                           [=](TLWbShape* shape)
    {
        return shape->getGlobalId() == globalId;
    });

    if(it != m_shapeList.end())
    {
        qDebug() << "delete figure global id :" << globalId;
        removeItem(*it);
        delete *it;
        m_shapeList.erase(it);
        update();
    }
}

void TLWbScene::undo()
{
    if(m_shapeList.size())
    {
        TLWbShape* lastShape = m_shapeList.back();
        int globalId = lastShape->getGlobalId();
        emit sigSendDeleteFigureMsg(globalId);
#if 0
        removeItem(lastShape);
        delete lastShape;
        m_shapeList.pop_back();
        update();
#endif
    }
}

bool TLWbScene::setShapePos(TLWbShape* shape,const QJsonArray& points)
{
    if(points.size() < 4)
        return false;
    QPointF startPos(points[0].toInt(),points[1].toInt());
    QPointF endPos(points[2].toInt(),points[3].toInt());
    shape->setStartPoint(startPos);
    shape->setEndPoint(endPos);
}

void TLWbScene::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    QGraphicsScene::mousePressEvent(event);
    if(event->button() != Qt::LeftButton)
        return;

    if(m_currentShape != nullptr)
    {
        if(!m_currentShape->isValid())
        {
            delete m_currentShape;
            m_currentShape = nullptr;
        }
    }

    if(!event->isAccepted() && m_toolForm)
    {
        m_currentShape = m_toolForm->getCurrentShape();
    }

    if(m_currentShape == nullptr)
        return;

    addItem(m_currentShape);
    m_currentShape->setUserId(m_id);
    m_currentShape->setStartPoint(event->scenePos());
}

void TLWbScene::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    QGraphicsScene::mouseMoveEvent(event);
    if(!event->isAccepted() && m_currentShape)
    {
        m_currentShape->setEndPoint(event->scenePos());
        update();
    }
}

void TLWbScene::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    QGraphicsScene::mouseReleaseEvent(event);
    if(event->button() != Qt::LeftButton)
        return;
    if(!event->isAccepted() && m_currentShape)
    {
        if(m_currentShape->isValid())
        {
            m_shapeList.push_back(m_currentShape);
            QJsonObject figure;
            m_currentShape->setJsonObj(figure);
            figure.insert("creator_id",m_id);
            figure.insert("local_id",m_currentShape->getLocalId());
            emit sigSendAddFigureMsg(figure);
        }
        else
        {
            removeItem(m_currentShape);
            delete m_currentShape;
        }
        m_currentShape = nullptr;
    }
}
