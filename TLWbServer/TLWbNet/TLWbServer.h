#ifndef TLWBSERVER_H
#define TLWBSERVER_H

#include <QTcpServer>
#include <list>
#include <QJsonArray>

class TLWbClientConnection;

class TLWbServer : public QTcpServer
{
    Q_OBJECT
public:
    explicit TLWbServer(QObject *parent = nullptr);
    ~TLWbServer();
protected:
    void incomingConnection(qintptr handle);
signals:

protected slots:
    void slotUserJoined(const QString& name,const int id);
    void slotUserLeft(const QString& name,const int id);
    void slotFigureAddReq(const QJsonObject&);
    void slotFigureDeleteReq(const int globalId);
protected:
    std::list<TLWbClientConnection*> m_clients;
    QJsonArray m_figures;
};

#endif // TLWBSERVER_H
