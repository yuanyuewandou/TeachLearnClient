#ifndef TLWBCOLORBUTTON_H
#define TLWBCOLORBUTTON_H

#include "TLWbToolButton.h"

class TLWbColorButton : public TLWbToolButton
{
    Q_OBJECT
public:
    explicit TLWbColorButton(QWidget *parent = nullptr);
    void setColor(const QColor& color);
    QColor getColor() const;
signals:
public slots:
private:
    QColor m_color;
};

#endif // TLWBCOLORBUTTON_H
