#include "TLWbGraffiti.h"
#include<QPainter>

TLWbGraffiti::TLWbGraffiti(int type) :TLWbShape(type)
{
    m_rcBounding = QRectF(0,0,0,0);
}

void TLWbGraffiti::setStartPoint(const QPointF &pos)
{
    setPos(pos);
    m_startPosScene = pos;
    m_path.moveTo(pos);
}

void TLWbGraffiti::setEndPoint(const QPointF &pos)
{
    m_path.lineTo(pos);
    m_rcBounding = m_path.boundingRect();
    m_topLeftInScene = m_rcBounding.topLeft();
    setPos(m_topLeftInScene);
    m_rcBounding.moveTo(0,0);
}

void TLWbGraffiti::setStrokeWidth(const float w)
{
    m_strokeWidth = w;
    m_pen.setWidthF(w);
}

void TLWbGraffiti::setStrokeColor(const QColor &clr)
{
    m_strokeColor = clr;
    m_pen.setColor(clr);
}

QRectF TLWbGraffiti::boundingRect() const
{
    return m_rcBounding;
}

void TLWbGraffiti::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->save();
    painter->setPen(m_pen);
    QPainterPath path = m_path.translated(-m_topLeftInScene);
    painter->drawPath(path);
    painter->restore();
}

void TLWbGraffiti::setJsonObj(QJsonObject &obj)
{
    obj.insert("type",m_type);
    QJsonObject data;
    data.insert("color",QJsonValue((qint64)(m_strokeColor.rgba())));
    data.insert("fill_color",QJsonValue((qint64)(m_fillColor.rgba())));
    data.insert("line_width",QJsonValue(m_strokeWidth));
    QJsonArray points;
    int ptCount = m_path.elementCount();
    QPainterPath::Element e;
    for(int i = 0; i < ptCount; i++)
    {
        e = m_path.elementAt(i);
        points.append(QJsonValue(e.x));
        points.append(QJsonValue(e.y));
    }
    data.insert("points",QJsonValue(points));
    obj.insert("data",QJsonValue(data));
}

