#include<QGraphicsSceneMouseEvent>
#include<QJsonObject>
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
    if(!event->isAccepted() && !m_currentShape)
    {
        if(m_currentShape->isValid())
        {
            m_shapeList.push_back(m_currentShape);
            QJsonObject figure;
            m_currentShape->setJsonObj(figure);
            figure.insert("creator",m_id);
            emit sigAddFigureReq(figure);
        }
        else
        {
            removeItem(m_currentShape);
            delete m_currentShape;
        }
        m_currentShape = nullptr;
    }
}
