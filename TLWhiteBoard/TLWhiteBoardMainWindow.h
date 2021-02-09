#ifndef TLWHITEBOARDMAINWINDOW_H
#define TLWHITEBOARDMAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class TLWhiteBoardMainWindow;
}

class TLWhiteBoardMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit TLWhiteBoardMainWindow(QWidget *parent = 0);
    ~TLWhiteBoardMainWindow();
private:
    void translateUi();
    void initUi();
    void initData();
    void initConnect();
private slots:

private:
    Ui::TLWhiteBoardMainWindow *ui;
};

#endif // TLWHITEBOARDMAINWINDOW_H
