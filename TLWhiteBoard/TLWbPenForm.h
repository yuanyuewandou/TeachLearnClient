#ifndef TLWBPENFORM_H
#define TLWBPENFORM_H

#include <QWidget>

class TLWbShape;
namespace Ui {
class TLWbPenForm;
}

class TLWbPenForm : public QWidget
{
    Q_OBJECT

public:
    TLWbShape* getCurrentShape();
    explicit TLWbPenForm(QWidget *parent = 0);
    ~TLWbPenForm();

private:
    Ui::TLWbPenForm *ui;
    TLWbShape* m_shape;
};

#endif // TLWBPENFORM_H
