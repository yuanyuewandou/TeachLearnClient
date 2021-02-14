#include "TLWbColorButton.h"

TLWbColorButton::TLWbColorButton(QWidget *parent) : TLWbToolButton(parent)
{
}

void TLWbColorButton::setColor(const QColor& color)
{
    m_color = color;
    QString style = m_strStyle.arg(color.red()).arg(color.green()).arg(color.blue());
    setStyleSheet(style);
}

QColor TLWbColorButton::getColor() const
{
    return m_color;
}
