#ifndef TLWBLINEWIDTHFORM_H
#define TLWBLINEWIDTHFORM_H

#include <QWidget>

namespace Ui {
class TLWbLineWidthForm;
}

class TLWbLineWidthForm : public QWidget
{
    Q_OBJECT

public:
    explicit TLWbLineWidthForm(QWidget *parent = 0);
    ~TLWbLineWidthForm();

private:
    Ui::TLWbLineWidthForm *ui;
};

#endif // TLWBLINEWIDTHFORM_H
