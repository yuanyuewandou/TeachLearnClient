#ifndef TLWBGRAFFITI_H
#define TLWBGRAFFITI_H
#include "TLWbShape.h"
#include<QPen>
class TLWbGraffiti :public TLWbShape
{
public:
    TLWbGraffiti(int type = TOOL_GRAFFITI);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    virtual void setStartPoint(const QPointF &pos);
    virtual void setEndPoint(const QPointF &pos);
    virtual void setStrokeWidth(const float w);
    virtual void setStrokeColor(const QColor &clr);
    virtual void setJsonObj(QJsonObject &obj);
protected:
    QPointF m_startPosScene;
    QPointF m_endPosScene;
    QRectF  m_rcBounding;
    QPen    m_pen;
    QPainterPath m_path;
    QPointF m_topLeftInScene;
};

#endif // TLWBGRAFFITI_H
