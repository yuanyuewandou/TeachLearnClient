#ifndef TLWBSERVER_H
#define TLWBSERVER_H

#include <QObject>
#include <QTcpServer>

class TLWbServer : public QTcpServer
{
    Q_OBJECT
public:
    explicit TLWbServer(QObject *parent = nullptr);

signals:

public slots:
};

#endif // TLWBSERVER_H
