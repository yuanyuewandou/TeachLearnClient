#ifndef TLWBSERVER_H
#define TLWBSERVER_H

#include <QTcpServer>
#include <list>
class TLWbClient;

class TLWbServer : public QTcpServer
{
    Q_OBJECT
public:
    explicit TLWbServer(QObject *parent = nullptr);
    ~TLWbServer();
protected:
    void incomingConnection(qintptr handle);
signals:

public slots:
protected:
    std::list<TLWbClient*> m_clients;
};

#endif // TLWBSERVER_H
