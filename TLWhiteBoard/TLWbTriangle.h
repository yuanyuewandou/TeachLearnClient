#ifndef TLWBTRIANGLE_H
#define TLWBTRIANGLE_H

#include "TLWbRectangle.h"
class TLWbTriangle :public TLWbRectangle
{
public:
    TLWbTriangle(int type = TOOL_TRIANGLE);
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
};

#endif // TLWBTRIANGLE_H
