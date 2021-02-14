#include "TLWbLine.h"
#include<QPainter>

TLWbLine::TLWbLine():TLWbShape(TOOL_LINE)
{

}

TLWbLine::TLWbLine(const TLWbLine& line) :
    TLWbShape(line)
{
    m_line = line.m_line;
}

void TLWbLine::setStartPoint(const QPointF &pos)
{
    setPos(pos);
    m_startPosScene = pos;
}

void TLWbLine::setEndPoint(const QPointF &pos)
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

    m_line.setPoints(startPoint,endPoint);
    setPos(startX,startY);
}

void TLWbLine::setStrokeWidth(const float w)
{
    m_strokeWidth = w;
    m_pen.setWidthF(w);
}

void TLWbLine::setStrokeColor(const QColor &clr)
{
    m_strokeColor = clr;
    m_pen.setColor(clr);
}

bool TLWbLine::isValid()
{
    return true;
}


QRectF TLWbLine::boundingRect() const
{
    return m_rcBounding;
}

void TLWbLine::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->save();
    m_pen.setWidthF(m_strokeWidth);
    painter->setPen(m_pen);
    painter->drawLine(m_line);
    painter->restore();
}

TLWbShape* TLWbLine::clone()
{
    TLWbShape* line = new TLWbLine(*this);
    return line;
}


