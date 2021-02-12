#include "TLWbColorButton.h"

TLWbColorButton::TLWbColorButton(QWidget *parent) : QPushButton(parent)
{
}

void TLWbColorButton::setColor(const QColor& color)
{
    QString style = QString("background-color:rgb(%1,%2,%3);").arg(color.red()).arg(color.green()).arg(color.blue());
    setStyleSheet(style);
}
