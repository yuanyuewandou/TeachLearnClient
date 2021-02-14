#ifndef TLWHITEBOARDMAINWINDOW_H
#define TLWHITEBOARDMAINWINDOW_H

#include <QMainWindow>
#include <QJsonObject>
class TLWbScene;
class TLWbToolForm;
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
    void slotAddFigure(QJsonObject);
private:
    Ui::TLWhiteBoardMainWindow *ui;
    TLWbScene* m_scene;
    TLWbToolForm* m_toolForm;
};

#endif // TLWHITEBOARDMAINWINDOW_H
