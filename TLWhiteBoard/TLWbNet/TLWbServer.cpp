#include "TLWbServer.h"
#include "TLWbClient.h"
#include "TLLog.h"
#include<QHostAddress>
#include<QJsonArray>
#include<QJsonDocument>
#include<QJsonObject>
#include<QJsonValue>
#include<algorithm>

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
    connect(client,SIGNAL(sigJoined(QString,int)),this,SLOT(slotUserJoined(QString,int)));
    connect(client,SIGNAL(sigUserLeft(QString,int)),this,SLOT(slotUserLeft(QString,int)));

    qDebug() << client->info();
}

void TLWbServer::slotUserJoined(QString name,int id)
{
    auto it = std::find_if(m_clients.begin(),m_clients.end(),
                           [=](TLWbClient*& client)
                           {
                                return id == client->getId();
                            });

    if(it != m_clients.end())
    {
        QJsonDocument doc;
        QJsonObject rootObj;
        rootObj.insert("type",QJsonValue("join_type"));
        rootObj.insert("id",QJsonValue(id));
        //history figures
        if(m_figures.size() > 0)
        {
            rootObj.insert("figures",QJsonValue(m_figures));
        }

        doc.setObject(rootObj);
        QByteArray jsonStr = doc.toJson(QJsonDocument::Compact);
        jsonStr.append('\n');
        (*it)->write(jsonStr);

        QJsonDocument joinDoc;
        QJsonObject joinObj;
        joinObj.insert("type",QJsonValue("user_joined"));
        joinObj.insert("name",QJsonValue(name));
        joinDoc.setObject(joinObj);
        QByteArray joinStr = joinDoc.toJson(QJsonDocument::Compact);
        joinStr.append('\n');
        for(auto c: m_clients)
        {
            if(c->getId() != id)
            {
                c->write(joinStr);
            }
        }
    }
}


void TLWbServer::slotUserLeft(QString name,int id)
{
    QJsonDocument doc;
    QJsonObject rootObj;
    rootObj.insert("type",QJsonValue("user_left"));
    rootObj.insert("id",QJsonValue(id));
    rootObj.insert("name",QJsonValue(name));
    QByteArray leftStr = doc.toJson(QJsonDocument::Compact);
    leftStr.append('\n');

    bool removed = false;
    m_clients.remove_if([=,&removed](TLWbClient*& client)
    {
        if(id == client->getId())
        {
            removed = true;
            client->write(leftStr);
            client->resetState();
            return true;
        }
        return false;
    });

    if(!removed)
        return;

    for(auto c: m_clients)
    {
        if(c->getId() != id)
        {
            c->write(leftStr);
        }
    }
}
