#ifndef TLWBTRIANGLE_H
#define TLWBTRIANGLE_H

#include "TLWbRectangle.h"
class TLWbTriangle :public TLWbRectangle
{
public:
    TLWbTriangle(int type = TOOL_TRIANGLE);
    TLWbTriangle(const TLWbTriangle& triangle);
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    virtual TLWbShape* clone();
};

#endif // TLWBTRIANGLE_H
