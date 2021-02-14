#include "TLWbTriangle.h"
#include<QPainter>

TLWbTriangle::TLWbTriangle(int type):TLWbRectangle(type)
{

}

TLWbTriangle::TLWbTriangle(const TLWbTriangle& triangle):TLWbRectangle(triangle)
{

}

void TLWbTriangle::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
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
    QPointF points[3] ={
        m_rcBounding.bottomLeft(),
        m_rcBounding.bottomRight(),
        QPointF(m_rcBounding.width()/2,0)
    };
    painter->drawPolygon(points,3);
    painter->restore();
}

TLWbShape* TLWbTriangle::clone()
{
    TLWbShape* triangle = new TLWbTriangle(*this);
    return triangle;
}
