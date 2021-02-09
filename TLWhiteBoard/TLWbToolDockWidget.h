#ifndef TLWBTOOLDOCKWIDGET_H
#define TLWBTOOLDOCKWIDGET_H

#include <QDockWidget>
#include "TLWidget.h"
namespace Ui {
class TLWbToolDockWidget;
}

class TLWbToolDockWidget : public QDockWidget
{
    Q_OBJECT

public:
    explicit TLWbToolDockWidget(QWidget *parent = 0);
    ~TLWbToolDockWidget();
private:
    void translateUi();
    void initUi();
    void initData();
    void initConnect();
private:
    Ui::TLWbToolDockWidget *ui;
};

#endif // TLWBTOOLDOCKWIDGET_H
