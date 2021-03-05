#ifndef TLWBTOOLFORM_H
#define TLWBTOOLFORM_H

#include <QWidget>

namespace Ui {
class TLWbToolForm;
}
class TLWbShape;

class TLWbToolForm : public QWidget
{
    Q_OBJECT

public:
    explicit TLWbToolForm(QWidget *parent = 0);
    ~TLWbToolForm();
public:
    TLWbShape* getCurrentShape();
private:
    void translateUi();
    void initUi();
    void initData();
    void initConnect();
    void setHeight(int row);
private slots:
    void slotShapePushButtonClicked();
    void slotTextPushButtonClicked();
    void slotPenPushButtonClicked();
    void slotErasePushButtonClicked();
    void slotSelectPushButtonClicked();
signals:
    void sigErase();
private:
    Ui::TLWbToolForm *ui;
};

#endif // TLWBTOOLFORM_H
