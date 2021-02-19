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
signals:

public slots:
    void slotReadyRead();
};

#endif // TLWBCLIENT_H
