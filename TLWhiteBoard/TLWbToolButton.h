#ifndef TLWBTOOLBUTTON_H
#define TLWBTOOLBUTTON_H

#include <QPushButton>

class TLWbToolButton : public QPushButton
{
    Q_OBJECT
public:
    explicit TLWbToolButton(QWidget *parent = nullptr);
signals:

public slots:
protected:
    QString m_strStyle;
};

#endif // TLWBTOOLBUTTON_H
