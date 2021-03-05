#include "TLWbShape.h"

int TLWbShape::m_localStartId = 0;
int TLWbShape::generateLocalId()
{
    return ++m_localStartId;
}

TLWbShape::TLWbShape(int type)
{
    m_type = type;
    m_strokeWidth = 2.0f;
    m_strokeColor = Qt::black;
    m_fillColor = Qt::transparent;
    m_rcBounding = QRectF(0,0,0,0);
    m_startPosScene = QPointF(0,0);
    m_endPosScene = QPointF(0,0);

    m_creatorUserId = -1;
    m_globalId = -1;
    m_localId = generateLocalId();
}

TLWbShape::TLWbShape(const TLWbShape& shape)
{
    m_type = shape.m_type;
    m_strokeWidth = shape.m_strokeWidth;
    m_strokeColor = shape.m_strokeColor;
    m_fillColor = shape.m_fillColor;

    m_startPosScene = shape.m_startPosScene;
    m_endPosScene = shape.m_endPosScene;
    m_rcBounding = shape.m_rcBounding;
    m_pen = shape.m_pen;

    m_creatorUserId = shape.m_creatorUserId;
    m_globalId = shape.m_globalId;
    m_localId = shape.m_localId;
}

TLWbShape::~TLWbShape()
{

}

void TLWbShape::setStrokeWidth(const float w)
{
    m_strokeWidth = w;
    m_pen.setWidthF(w);
}

void TLWbShape::setStrokeColor(const QColor &clr)
{
    m_strokeColor = clr;
    m_pen.setColor(clr);
}

void TLWbShape::setFillColor(const QColor &clr)
{
    m_fillColor = clr;
}

bool TLWbShape::isValid()
{
    if(m_startPosScene == m_endPosScene)
    {
        return false;
    }
    return true;
}

void TLWbShape::setJsonObj(QJsonObject& obj)
{
    obj.insert("figure_type",m_type);
    QJsonObject data;
    data.insert("color",QJsonValue((qint64)(m_strokeColor.rgba())));
    data.insert("fill_color",QJsonValue((qint64)(m_fillColor.rgba())));
    data.insert("line_width",QJsonValue(m_strokeWidth));
    QJsonArray points;
    points.append(QJsonValue(m_startPosScene.x()));
    points.append(QJsonValue(m_startPosScene.y()));
    points.append(QJsonValue(m_endPosScene.x()));
    points.append(QJsonValue(m_endPosScene.y()));
    data.insert("points",QJsonValue(points));
    obj.insert("data",QJsonValue(data));
}

void TLWbShape::setUserId(int id)
{
    m_creatorUserId = id;
}

int TLWbShape::getUserId()
{
    return m_creatorUserId;
}

void TLWbShape::setGlobalId(int id)
{
    m_globalId = id;
}

int TLWbShape::getGlobalId()
{
    return m_globalId;
}

void TLWbShape::setLocalId(int id)
{
    m_localId = id;
}

int TLWbShape::getLocalId()
{
    return m_localId;
}
