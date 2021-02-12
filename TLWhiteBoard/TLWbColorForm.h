#ifndef TLWBCOLORFORM_H
#define TLWBCOLORFORM_H

#include <QWidget>

namespace Ui {
class TLWbColorForm;
}

class TLWbColorForm : public QWidget
{
    Q_OBJECT

public:
    explicit TLWbColorForm(QWidget *parent = 0);
    ~TLWbColorForm();

private:
    Ui::TLWbColorForm *ui;
};

#endif // TLWBCOLORFORM_H
