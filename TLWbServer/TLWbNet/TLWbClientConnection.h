#ifndef TLWBCLIENT_H
#define TLWBCLIENT_H

#include <QObject>
#include <QTcpSocket>

class TLWbClientConnection : public QTcpSocket
{
    Q_OBJECT
public:
    explicit TLWbClientConnection(QObject *parent = nullptr);
    ~TLWbClientConnection();
public:
    QString info();
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
    void slotReadyRead();
protected:
    QString m_name;
    int m_id;
    static int m_idBase;
};

#endif // TLWBCLIENT_H
