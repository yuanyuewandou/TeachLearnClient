#include "TLWbServer.h"
#include "TLWbClient.h"
#include "TLLog.h"

TLWbServer::TLWbServer(QObject *parent) : QTcpServer(parent)
{

}

TLWbServer::~TLWbServer()
{

}

void TLWbServer::incomingConnection(qintptr sock)
{
    TLWbClient* client = new TLWbClient(this);
    client->setSocketDescriptor(sock);
    m_clients.push_back(client);
    qDebug() << client->info();
}
