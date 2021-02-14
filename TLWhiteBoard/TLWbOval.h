#ifndef TLWBOVAL_H
#define TLWBOVAL_H

#include "TLWbRectangle.h"
class TLWbOval :public TLWbRectangle
{
public:
    TLWbOval(int type = TOOL_OVAL);
    TLWbOval(const TLWbOval& oval);
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    virtual TLWbShape* clone();
};

#endif // TLWBOVAL_H
