#ifndef TLWBCOLORBUTTON_H
#define TLWBCOLORBUTTON_H

#include <QPushButton>

class TLWbColorButton : public QPushButton
{
    Q_OBJECT
public:
    explicit TLWbColorButton(QWidget *parent = nullptr);
    void setColor(const QColor& color);
signals:
public slots:
};

#endif // TLWBCOLORBUTTON_H
