#ifndef TLWBSHAPE_H
#define TLWBSHAPE_H

#include <QGraphicsItem>
#include<QJsonObject>
#include<QJsonArray>
#include<QPen>

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
    TLWbShape(const TLWbShape& line);
    virtual ~TLWbShape();
    virtual TLWbShape* clone() = 0;
    virtual bool isValid();
    virtual void setStartPoint(const QPointF &pos) = 0;
    virtual void setEndPoint(const QPointF &pos) = 0;
    virtual void setStrokeWidth(const float w);
    virtual void setStrokeColor(const QColor &clr);
    virtual void setFillColor(const QColor &clr);
    virtual void setJsonObj(QJsonObject& obj);
    static int generateLocalId();
    void setUserId(int id);
    int getUserId();
    void setGlobalId(int id);
    int getGlobalId();
    void setLocalId(int id);
    int getLocalId();
signals:
public slots:
protected:
    int m_type;
    float m_strokeWidth;
    QColor m_strokeColor;
    QColor m_fillColor;

    QPointF m_startPosScene;
    QPointF m_endPosScene;
    QRectF  m_rcBounding;
    QPen    m_pen;

    int m_creatorUserId;
    int m_globalId;
    int m_localId;

    static int m_localStartId;
};

#endif // TLWBSHAPE_H
