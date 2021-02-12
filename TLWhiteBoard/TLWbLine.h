#ifndef TLWBLINE_H
#define TLWBLINE_H

#include"TLWbShape.h"
#include<QPen>
class TLWbLine : public TLWbShape
{
public:
    TLWbLine();
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    virtual void setStartPoint(const QPointF &pos);
    virtual void setEndPoint(const QPointF &pos);
    virtual void setStrokeWidth(const float w);
    virtual void setStrokeColor(const QColor &clr);
    virtual bool isValid();
protected:
    QPointF m_startPosScene;
    QPointF m_endPosScene;
    QLineF  m_line;
    QRectF  m_rcBounding;
    QPen    m_pen;
};

#endif // TLWBLINE_H
