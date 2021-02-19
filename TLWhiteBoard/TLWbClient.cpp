#include "TLWbClient.h"
#include<QHostAddress>

TLWbClient::TLWbClient(QObject *parent) : QTcpSocket(parent)
{
    connect(this,SIGNAL(readyRead()),this,SLOT(slotReadyRead()));
    connect(this,SIGNAL(disconnected()),this,SLOT(deleteLater()));
}

TLWbClient::~TLWbClient()
{

}

QString TLWbClient::info()
{
    QString strInfo = QString("%1 : %2").arg(peerAddress().toString())
            .arg(peerPort());
    return strInfo;
}

void TLWbClient::slotReadyRead()
{
    QByteArray data = readAll();
    data.append('\n');
    write(data);
}
