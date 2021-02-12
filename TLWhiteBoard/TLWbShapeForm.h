#ifndef TLWBSHAPEFORM_H
#define TLWBSHAPEFORM_H

#include <QWidget>

namespace Ui {
class TLWbShapeForm;
}

class TLWbShapeForm : public QWidget
{
    Q_OBJECT

public:
    explicit TLWbShapeForm(QWidget *parent = 0);
    ~TLWbShapeForm();

private:
    Ui::TLWbShapeForm *ui;
};

#endif // TLWBSHAPEFORM_H
