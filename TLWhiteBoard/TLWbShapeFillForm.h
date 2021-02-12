#ifndef TLWBSHAPEFILLFORM_H
#define TLWBSHAPEFILLFORM_H

#include <QWidget>

namespace Ui {
class TLWbShapeFillForm;
}

class TLWbShapeFillForm : public QWidget
{
    Q_OBJECT

public:
    explicit TLWbShapeFillForm(QWidget *parent = 0);
    ~TLWbShapeFillForm();

private:
    Ui::TLWbShapeFillForm *ui;
};

#endif // TLWBSHAPEFILLFORM_H
