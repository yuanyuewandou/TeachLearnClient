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
    void join(QString name,QString host,int port);
    void left();
    QString getName();
    int getId();
    void resetState();
    static int generateUserId();
private:
    void initData();
    void initConnect();
signals:
    void sigJoined(QString name,int id);
    void sigUserLeft(QString name,int id);
    void sigMsg(QByteArray data);
public slots:
    void slotConnected();
    void slotReadyRead();
    void slotError(QAbstractSocket::SocketError err);
protected:
    QString m_name;
    int m_id;
    static int m_idBase;
};

#endif // TLWBCLIENT_H
