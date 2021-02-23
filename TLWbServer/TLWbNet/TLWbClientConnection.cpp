#include "TLWbClientConnection.h"
#include<QDebug>
#include<QHostAddress>
#include<QJsonArray>
#include<QJsonDocument>
#include<QJsonObject>
#include<QJsonValue>

int TLWbClientConnection::m_idBase = 0;

int TLWbClientConnection::generateUserId()
{
    return ++m_idBase;
}

TLWbClientConnection::TLWbClientConnection(QObject *parent) : QTcpSocket(parent)
{
    initData();
    initConnect();
}

TLWbClientConnection::~TLWbClientConnection()
{
    if(m_id > 0)
    {
        emit sigUserLeft(m_name,m_id);
    }
}

QString TLWbClientConnection::info()
{
    QString strInfo = QString("%1 : %2").arg(peerAddress().toString())
            .arg(peerPort());
    return strInfo;
}

void TLWbClientConnection::join(QString name,QString host,int port)
{
    m_name = name;
    connectToHost(host,port);
}

void TLWbClientConnection::left()
{
    QJsonDocument doc;
    QJsonObject obj;
    obj.insert("type",QJsonValue("left"));
    doc.setObject(obj);
    QByteArray leftMsg = doc.toJson(QJsonDocument::Compact);
    leftMsg.append('\n');
    write(leftMsg);
}

QString TLWbClientConnection::getName()
{
    return m_name;
}

int TLWbClientConnection::getId()
{
    return m_id;
}

void TLWbClientConnection::resetState()
{
    m_id = -1;
}



void TLWbClientConnection::initData()
{
    m_id = -1;
    m_name = "";
}

void TLWbClientConnection::initConnect()
{
    connect(this,SIGNAL(connected()),this,SLOT(slotConnected()));
    connect(this,SIGNAL(readyRead()),this,SLOT(slotReadyRead()));
    connect(this,SIGNAL(disconnected()),this,SLOT(deleteLater()));
    connect(this,SIGNAL(error(QAbstractSocket::SocketError)),this,SLOT(slotError(QAbstractSocket::SocketError)));
}

void TLWbClientConnection::slotReadyRead()
{
    while(canReadLine())
    {
        QByteArray data = readAll();
        data.chop(1);
        qDebug() << "msg: " << data.data();
        QJsonParseError error;
        QJsonDocument doc = QJsonDocument::fromJson(data, &error);
        if(error.error == QJsonParseError::NoError)
        {
           QJsonObject rootObj = doc.object();
           QString type = rootObj.value("type").toString();
           if(type == "user_join")
           {
               if(m_id < 0)
               {
                   m_id = generateUserId();
                   QString name = rootObj["name"].toString();
                   m_name = name.toUtf8();
                   qDebug() << name << " join, id - " << m_id << " from " << info();
                   emit sigJoined(m_name, m_id);
               }
           }
           else if(type == "left")
           {
               if(m_id > 0)
               {
                   qDebug() << m_name << " left, id - " << m_id << " from " << info();
                   emit sigUserLeft(m_name, m_id);
               }
           }
           else
           {
               qDebug() << __FUNCTION__ << " got unknown message ,type - " << type;
           }
        }
        else
        {
            qDebug() << "ClientConnection::onReadyRead, json error - " << error.errorString();
        }
    }
}

void TLWbClientConnection::slotConnected()
{
    qDebug() <<__FUNCTION__;
    QJsonDocument doc;
    QJsonObject obj;
    obj.insert("type",QJsonValue("join"));
    obj.insert("name",QJsonValue(m_name));
    doc.setObject(obj);
    QByteArray joinMsg = doc.toJson(QJsonDocument::Compact);
    joinMsg.append('\n');
    write(joinMsg);
}

void TLWbClientConnection::slotError(QAbstractSocket::SocketError err)
{

}
