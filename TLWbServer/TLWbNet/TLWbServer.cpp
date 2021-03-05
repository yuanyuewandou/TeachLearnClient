#include "TLWbServer.h"
#include "TLWbClientConnection.h"
#include<QHostAddress>
#include<QJsonArray>
#include<QJsonDocument>
#include<QJsonObject>
#include<QJsonValue>
#include<algorithm>

TLWbServer::TLWbServer(QObject *parent) : QTcpServer(parent)
{
    qDebug() << "tl wb server";
}

TLWbServer::~TLWbServer()
{

}

void TLWbServer::incomingConnection(qintptr sock)
{
    TLWbClientConnection* clientConnection = new TLWbClientConnection(this);
    clientConnection->setSocketDescriptor(sock);
    m_clients.push_back(clientConnection);
    connect(clientConnection,SIGNAL(sigUserJoined(const QString&,const int)),this,SLOT(slotUserJoined(const QString&,const int)));
    connect(clientConnection,SIGNAL(sigUserLeft(const QString&,const int)),this,SLOT(slotUserLeft(const QString&,const int)));
    connect(clientConnection,SIGNAL(sigFiguredAddReq(const QJsonObject&)),this,SLOT(slotFigureAddReq(const QJsonObject&)));
    connect(clientConnection,SIGNAL(sigFiguredDeleteReq(const int)),this,SLOT(slotFigureDeleteReq(const int)));

    qDebug() << clientConnection->info();
}

void TLWbServer::slotUserJoined(const QString& name,const int id)
{
    auto it = std::find_if(m_clients.begin(),m_clients.end(),
                           [=](TLWbClientConnection*& client)
                           {
                                return id == client->getId();
                            });

    if(it != m_clients.end())
    {
        QJsonDocument doc;
        QJsonObject rootObj;
        rootObj.insert("type",QJsonValue("join_reply"));
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
        qDebug() << "send msg: " << jsonStr;

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
                qDebug() << "send msg: " << joinStr;
            }
        }
    }
}

void TLWbServer::slotUserLeft(const QString& name,const int id)
{
    QJsonDocument doc;
    QJsonObject rootObj;
    rootObj.insert("type",QJsonValue("user_left"));
    rootObj.insert("id",QJsonValue(id));
    rootObj.insert("name",QJsonValue(name));
    doc.setObject(rootObj);
    QByteArray leftStr = doc.toJson(QJsonDocument::Compact);
    leftStr.append('\n');

    bool removed = false;
    m_clients.remove_if([=,&removed](TLWbClientConnection*& client)
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

void TLWbServer::slotFigureAddReq(const QJsonObject& figure)
{
    m_figures.append(QJsonValue(figure));
    QJsonDocument doc;
    QJsonObject obj;
    obj.insert("type",QJsonValue("figure_added"));
    obj.insert("figure",QJsonValue(figure));
    doc.setObject(obj);
    QByteArray msg = doc.toJson(QJsonDocument::Compact);
    msg.append("\n");
    for(auto c:m_clients)
    {
        c->write(msg);
    }
    qDebug() << "send figure added msg:" << msg;
}

void TLWbServer::slotFigureDeleteReq(const int globalId)
{
    auto it = m_figures.begin();
    while(it != m_figures.end())
    {
        if(globalId == it->toObject().value("global_id").toInt())
        {
            qDebug() << "delete fiture globalId:" << globalId;
            m_figures.erase(it);
            break;
        }
        it++;
    }

    QJsonDocument doc;
    QJsonObject obj;
    obj.insert("type",QJsonValue("figure_delete"));
    obj.insert("global_id",QJsonValue(globalId));
    doc.setObject(obj);
    QByteArray msg = doc.toJson(QJsonDocument::Compact);
    msg.append("\n");

    for(auto c:m_clients)
    {
        c->write(msg);
    }
    qDebug() << "send msg:" << msg;
}




