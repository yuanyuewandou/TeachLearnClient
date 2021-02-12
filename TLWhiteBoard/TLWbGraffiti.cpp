#include "TLWbGraffiti.h"
#include<QPainter>

TLWbGraffiti::TLWbGraffiti(int type) :TLWbShape(type)
{
    m_rcBounding = QRectF(0,0,0,0);
}

void TLWbGraffiti::setStartPoint(const QPointF &pos)
{
    setPos(pos);
    m_startPosScene = pos;
    m_path.moveTo(pos);
}

void TLWbGraffiti::setEndPoint(const QPointF &pos)
{
    m_path.lineTo(pos);
    m_rcBounding = m_path.boundingRect();
    m_topLeftInScene = m_rcBounding.topLeft();
    setPos(m_topLeftInScene);
    m_rcBounding.moveTo(0,0);
}

void TLWbGraffiti::setStrokeWidth(const float w)
{
    m_strokeWidth = w;
    m_pen.setWidthF(w);
}

void TLWbGraffiti::setStrokeColor(const QColor &clr)
{
    m_strokeColor = clr;
    m_pen.setColor(clr);
}

QRectF TLWbGraffiti::boundingRect() const
{
    return m_rcBounding;
}

void TLWbGraffiti::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->save();
    painter->setPen(m_pen);
    QPainterPath path = m_path.translated(-m_topLeftInScene);
    painter->drawPath(path);
    painter->restore();
}

