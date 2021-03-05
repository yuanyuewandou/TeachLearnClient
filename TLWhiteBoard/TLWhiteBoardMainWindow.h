#ifndef TLWHITEBOARDMAINWINDOW_H
#define TLWHITEBOARDMAINWINDOW_H

#include <QMainWindow>
#include <QJsonObject>

class TLWbScene;
class TLWbToolForm;
class TLWbClient;

namespace Ui {
class TLWhiteBoardMainWindow;
}

class TLWhiteBoardMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit TLWhiteBoardMainWindow(QWidget *parent = 0);
    ~TLWhiteBoardMainWindow();
    void join(const QString& name,const QString & strIp,const int & port);
    void left();
private:
    void translateUi();
    void initUi();
    void initData();
    void initConnect();
private slots:
    void slotJoined(QString,int);
    void slotJoinReply(QString,int);
    void slotUserLeft(QString,int);
    void slotSendAddFigureMsg(const QJsonObject& figure);
    void slotSendDeleteFigureMsg(const int globalId);
    void slotFigureCleared(const int ownerId);
    void slotFigureDeleted(const int globalId);
    void slotFigureAdded(const QJsonObject& figure);
    void slotFigureUndo();
private:
    Ui::TLWhiteBoardMainWindow *ui;
    TLWbScene* m_scene;
    TLWbToolForm* m_toolForm;
    TLWbClient* m_client;
};

#endif // TLWHITEBOARDMAINWINDOW_H
