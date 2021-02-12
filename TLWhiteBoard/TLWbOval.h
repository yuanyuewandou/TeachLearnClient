#ifndef TLWBOVAL_H
#define TLWBOVAL_H

#include "TLWbRectangle.h"
class TLWbOval :public TLWbRectangle
{
public:
    TLWbOval(int type = TOOL_OVAL);
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
};

#endif // TLWBOVAL_H
