#include<QGraphicsSceneMouseEvent>
#include "TLWbScene.h"
#include "TLWbShape.h"
#include "TLWbLine.h"
#include "TLWbRectangle.h"
#include "TLWbOval.h"
#include "TLWbTriangle.h"
#include "TLWbGraffiti.h"

TLWbScene::TLWbScene(QObject *parent) : QGraphicsScene(parent)
{
    m_toolType = TOOL_LINE;
    m_currentShape = nullptr;
}

TLWbScene:: ~TLWbScene()
{

}

void TLWbScene::setToolType(int type)
{
    m_toolType = type;
    if(m_currentShape != nullptr)
    {
        if(!m_currentShape->isValid())
        {
            delete m_currentShape;
            m_currentShape = nullptr;
        }
    }
    else
    {

    }
}

void TLWbScene::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    QGraphicsScene::mousePressEvent(event);
    if(event->button() != Qt::LeftButton)
        return;
    if(!event->isAccepted())
    {
        switch(m_toolType)
        {
        case TOOL_LINE:
            m_currentShape = new TLWbLine();
            break;
        case TOOL_RECTANGLE:
            m_currentShape = new TLWbRectangle();
            break;
        case TOOL_OVAL:
            m_currentShape = new TLWbOval();
            break;
        case TOOL_TRIANGLE:
            m_currentShape = new TLWbTriangle();
            break;
        case TOOL_GRAFFITI:
            m_currentShape = new TLWbGraffiti();
            break;
        default:
            break;
        }
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
        if(!m_currentShape->isValid())
        {
            removeItem(m_currentShape);
            delete m_currentShape;
        }
        m_currentShape = nullptr;
    }
}
