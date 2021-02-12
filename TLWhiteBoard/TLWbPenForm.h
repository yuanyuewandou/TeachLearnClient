#ifndef TLWBPENFORM_H
#define TLWBPENFORM_H

#include <QWidget>

namespace Ui {
class TLWbPenForm;
}

class TLWbPenForm : public QWidget
{
    Q_OBJECT

public:
    explicit TLWbPenForm(QWidget *parent = 0);
    ~TLWbPenForm();

private:
    Ui::TLWbPenForm *ui;
};

#endif // TLWBPENFORM_H
