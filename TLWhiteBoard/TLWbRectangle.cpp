#include "TLWbRectangle.h"
#include<QPainter>

TLWbRectangle::TLWbRectangle(int type):TLWbShape(type)
{
}

TLWbRectangle::TLWbRectangle(const TLWbRectangle& rect)
    :TLWbShape(rect)
{

}

QRectF TLWbRectangle::boundingRect() const
{
    return m_rcBounding;
}

void TLWbRectangle::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->save();
    if(m_strokeWidth > 0.1)
    {
        painter->setPen(m_pen);
    }
    else
    {
        painter->setPen(Qt::NoPen);
    }

    if(m_fillColor == Qt::transparent)
    {
        painter->setBrush(Qt::NoBrush);
    }
    else
    {
        painter->setBrush(m_fillColor);
    }
    painter->drawRect(m_rcBounding);
    painter->restore();
}

void TLWbRectangle::setStartPoint(const QPointF &pos)
{
    setPos(pos);
    m_startPosScene = pos;
}

void TLWbRectangle::setEndPoint(const QPointF &pos)
{
    m_endPosScene = pos;
    qreal endX = m_endPosScene.x();
    qreal endY = m_endPosScene.y();
    qreal startX = m_startPosScene.x();
    qreal startY = m_startPosScene.y();

    m_rcBounding.setWidth(qAbs(endX-startX));
    m_rcBounding.setHeight(qAbs(endY-startY));

    QPointF startPoint;
    QPointF endPoint;

    if(endX < startX)
    {
        startX = endX;
        startPoint.setX(m_rcBounding.width());
        endPoint.setX(0);
    }
    else
    {
        startPoint.setX(0);
        endPoint.setX(m_rcBounding.width());
    }

    if(endY < startY)
    {
        startY = endY;
        startPoint.setY(m_rcBounding.height());
        endPoint.setY(0);
    }
    else
    {
        startPoint.setY(0);
        endPoint.setY(m_rcBounding.height());
    }
    setPos(startX,startY);
}

bool TLWbRectangle::isValid()
{
    return m_rcBounding.height() >= 1  && m_rcBounding.width() >= 1;
}

TLWbShape* TLWbRectangle::clone()
{
    TLWbShape* rect = new TLWbRectangle(*this);
    return rect;
}




