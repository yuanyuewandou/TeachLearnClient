#ifndef TLWBTOOLFORM_H
#define TLWBTOOLFORM_H

#include <QWidget>

namespace Ui {
class TLWbToolForm;
}

class TLWbToolForm : public QWidget
{
    Q_OBJECT

public:
    explicit TLWbToolForm(QWidget *parent = 0);
    ~TLWbToolForm();
public:
    int getType();
private:
    void translateUi();
    void initUi();
    void initData();
    void initConnect();
private slots:
    void slotLinePushButtonClicked();
private:
    Ui::TLWbToolForm *ui;
    int m_type;
};

#endif // TLWBTOOLFORM_H
