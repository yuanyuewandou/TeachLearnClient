#ifndef TLWBTEXTFORM_H
#define TLWBTEXTFORM_H

#include <QWidget>

namespace Ui {
class TLWbTextForm;
}

class TLWbTextForm : public QWidget
{
    Q_OBJECT

public:
    explicit TLWbTextForm(QWidget *parent = 0);
    ~TLWbTextForm();

private:
    Ui::TLWbTextForm *ui;
};

#endif // TLWBTEXTFORM_H
