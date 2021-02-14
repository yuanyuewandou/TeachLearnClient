#ifndef TLWBLINE_H
#define TLWBLINE_H

#include"TLWbShape.h"

class TLWbLine : public TLWbShape
{
public:
    TLWbLine();
    TLWbLine(const TLWbLine& line);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    virtual void setStartPoint(const QPointF &pos);
    virtual void setEndPoint(const QPointF &pos);
    virtual void setStrokeWidth(const float w);
    virtual void setStrokeColor(const QColor &clr);
    virtual bool isValid();
    virtual TLWbShape* clone();
protected:
    QLineF  m_line;
};

#endif // TLWBLINE_H
