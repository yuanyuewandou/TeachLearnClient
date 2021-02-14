#include "TLWbOval.h"
#include<QPainter>

TLWbOval::TLWbOval(int type):TLWbRectangle(type)
{

}

TLWbOval::TLWbOval(const TLWbOval& oval):TLWbRectangle(oval)
{

}

void TLWbOval::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
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
    painter->drawEllipse(m_rcBounding);
    painter->restore();
}

TLWbShape* TLWbOval::clone()
{
    TLWbShape* oval = new TLWbOval(*this);
    return oval;
}
