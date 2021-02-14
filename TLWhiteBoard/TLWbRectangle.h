#ifndef TLWBRECTANGLE_H
#define TLWBRECTANGLE_H

#include"TLWbShape.h"

class TLWbRectangle : public TLWbShape
{
public:
    TLWbRectangle(int type = TOOL_RECTANGLE);
    TLWbRectangle(const TLWbRectangle& rect);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    virtual void setStartPoint(const QPointF &pos);
    virtual void setEndPoint(const QPointF &pos);
    virtual TLWbShape* clone();
};

#endif // TLWBRECTANGLE_H
