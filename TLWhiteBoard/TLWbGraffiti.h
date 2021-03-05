#ifndef TLWBGRAFFITI_H
#define TLWBGRAFFITI_H
#include "TLWbShape.h"
#include<QPen>
class TLWbGraffiti :public TLWbShape
{
public:
    TLWbGraffiti(int type = TOOL_GRAFFITI);
    TLWbGraffiti(const TLWbGraffiti& gra);
public:
    QRectF boundingRect() const;
    virtual TLWbShape* clone();
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    virtual void setStartPoint(const QPointF &pos);
    virtual void setEndPoint(const QPointF &pos);
    virtual void setJsonObj(QJsonObject &obj);
    virtual bool isValid();
    void setPath(const QPainterPath& path);
protected:
    QPainterPath m_path;
    QPointF m_topLeftInScene;
};

#endif // TLWBGRAFFITI_H
