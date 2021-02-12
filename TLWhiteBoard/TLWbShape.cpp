#include "TLWbShape.h"

TLWbShape::TLWbShape(int type)
{
    m_type = type;
    m_strokeWidth = 2.0f;
    m_strokeColor = Qt::black;
    m_fillColor = Qt::transparent;
}

TLWbShape::~TLWbShape()
{

}

void TLWbShape::setStrokeWidth(const float w)
{
    m_strokeWidth = w;
}

void TLWbShape::setStrokeColor(const QColor &clr)
{
    m_strokeColor = clr;
}

void TLWbShape::setFillColor(const QColor &clr)
{
    m_fillColor = clr;
}

bool TLWbShape::isValid()
{
    return true;
}
