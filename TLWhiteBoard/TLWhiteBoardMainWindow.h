#ifndef TLWHITEBOARDMAINWINDOW_H
#define TLWHITEBOARDMAINWINDOW_H

#include <QMainWindow>
#include <QJsonObject>
#include "TLWbClient.h"

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
    void join(QString name);
private:
    void translateUi();
    void initUi();
    void initData();
    void initConnect();
private slots:
    void slotAddFigure(QJsonObject);
    void slotJoined(QString,int);
    void slotUserLeft(QString,int);
private:
    Ui::TLWhiteBoardMainWindow *ui;
    TLWbScene* m_scene;
    TLWbToolForm* m_toolForm;
    TLWbClient m_client;
};

#endif // TLWHITEBOARDMAINWINDOW_H
