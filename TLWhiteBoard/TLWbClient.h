#ifndef TLWBCLIENT_H
#define TLWBCLIENT_H

#include <QObject>
#include <QTcpSocket>

class TLWbClient : public QTcpSocket
{
    Q_OBJECT
public:
    explicit TLWbClient(QObject *parent = nullptr);

signals:

public slots:
};

#endif // TLWBCLIENT_H
