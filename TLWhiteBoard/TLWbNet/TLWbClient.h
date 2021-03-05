#ifndef TLWBCLIENT_H
#define TLWBCLIENT_H

#include <QObject>
#include <QTcpSocket>

class TLWbClient : public QTcpSocket
{
    Q_OBJECT
public:
    explicit TLWbClient(QObject *parent = nullptr);
    ~TLWbClient();
    QString info();
    void join(const QString& name,const QString& host,const int& port);
    void left();
    QString getName();
    int getId();
    void sendAddFigureMsg(const QJsonObject& figure);
    void sendDeleteFigureMsg(const int globalId);
private:
    void initData();
    void initConnect();
signals:
    void sigJoinReply(QString name,int id);
    void sigJoined(QString name,int id);
    void sigUserLeft(QString name,int id);
    void sigError(const QString& strError);
    void sigFigureAdded(const QJsonObject& figure);
    void sigFigureDeleted(const int id);
    void sigFigureCleared(const int ownerId);
public slots:
    void slotConnected();
    void slotReadyRead();
    void slotError(QAbstractSocket::SocketError err);
protected:
    QString m_name;
    int m_id;
};

#endif // TLWBCLIENT_H
