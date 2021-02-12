#ifndef TLWBSHAPE_H
#define TLWBSHAPE_H

#include <QGraphicsItem>
enum EN_WB_ToolType
{
    TOOL_LINE = 1,
    TOOL_GRAFFITI,
    TOOL_RECTANGLE,
    TOOL_OVAL,
    TOOL_TRIANGLE
};

class TLWbShape : public QGraphicsItem
{
public:
    explicit TLWbShape(int type);
    virtual ~TLWbShape();
signals:
    virtual void setStartPoint(const QPointF &pos) = 0;
    virtual void setEndPoint(const QPointF &pos) = 0;
    virtual void setStrokeWidth(const float w);
    virtual void setStrokeColor(const QColor &clr);
    virtual void setFillColor(const QColor &clr);
    virtual bool isValid();
public slots:
protected:
    int m_type;
    float m_strokeWidth;
    QColor m_strokeColor;
    QColor m_fillColor;
};

#endif // TLWBSHAPE_H
