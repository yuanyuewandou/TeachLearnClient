#ifndef TLMAINWIDGET_H
#define TLMAINWIDGET_H

#include "TLWidget.h"

namespace Ui {
class TLMainWidget;
}

class TLMainWidget : public TLWidget
{
    Q_OBJECT
public:
    explicit TLMainWidget(QWidget *parent = 0);
    ~TLMainWidget();
private:
    void translateUi();
    void initUi();
    void initData();
    void initConnect();
private slots:
    void slotLanguageSwitch(bool);
private:
    Ui::TLMainWidget *ui;
};

#endif // TLMAINWIDGET_H
