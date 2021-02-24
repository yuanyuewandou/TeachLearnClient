#include "TLWbClient.h"
#include<QDebug>
#include<QHostAddress>
#include<QJsonArray>
#include<QJsonDocument>
#include<QJsonObject>
#include<QJsonValue>

int TLWbClient::m_idBase = 0;

int TLWbClient::generateUserId()
{
    return ++m_idBase;
}

TLWbClient::TLWbClient(QObject *parent) : QTcpSocket(parent)
{
    initData();
    initConnect();
}

TLWbClient::~TLWbClient()
{
    if(m_id > 0)
    {
        emit sigUserLeft(m_name,m_id);
    }
}

void TLWbClient::initData()
{
    m_id = -1;
    m_name = "";
}

void TLWbClient::initConnect()
{
    connect(this,SIGNAL(connected()),this,SLOT(slotConnected()));
    connect(this,SIGNAL(readyRead()),this,SLOT(slotReadyRead()));
    connect(this,SIGNAL(disconnected()),this,SLOT(deleteLater()));
    connect(this,SIGNAL(error(QAbstractSocket::SocketError)),this,SLOT(slotError(QAbstractSocket::SocketError)));
}

QString TLWbClient::info()
{
    QString strInfo = QString("%1 : %2").arg(peerAddress().toString())
            .arg(peerPort());
    return strInfo;
}

void TLWbClient::join(QString name,QString host,int port)
{
    m_name = name;
    connectToHost(host,port);
}

void TLWbClient::left()
{
    QJsonDocument doc;
    QJsonObject obj;
    obj.insert("type",QJsonValue("user_left"));
    doc.setObject(obj);
    QByteArray leftMsg = doc.toJson(QJsonDocument::Compact);
    leftMsg.append('\n');
    write(leftMsg);
}

QString TLWbClient::getName()
{
    return m_name;
}

int TLWbClient::getId()
{
    return m_id;
}

void TLWbClient::resetState()
{
    m_id = -1;
}

void TLWbClient::slotReadyRead()
{
    while(canReadLine())
    {
        QByteArray data = readAll();
        data.chop(1);
        qDebug() << "msg: " << data.data();
        QJsonParseError JsonError;
        QJsonDocument doc = QJsonDocument::fromJson(data,&JsonError);
        if(JsonError.error == QJsonParseError::NoError)
        {
            QJsonObject obj = doc.object();
            QString type = obj.value("type").toString();
            if(type == "join_reply")
            {
                m_id = obj.value("id").toInt();
                emit sigJoinReply(m_name,m_id);
            }

            else if(type == "user_joined")
            {
                QString name = obj.value("name").toString();
                int id = obj.value("id").toInt();
                emit sigJoined(name,id);
            }

            else if(type == "user_left")
            {
                QString name = obj.value("name").toString();
                int id = obj.value("id").toInt();
                emit sigUserLeft(name,id);
            }
            else
            {
                qDebug() << "ready read";
            }
        }
    }
}

void TLWbClient::slotConnected()
{
    qDebug() <<__FUNCTION__;
    QJsonDocument doc;
    QJsonObject obj;
    obj.insert("type",QJsonValue("user_join"));
    obj.insert("name",QJsonValue(m_name));
    doc.setObject(obj);
    QByteArray joinMsg = doc.toJson(QJsonDocument::Compact);
    joinMsg.append('\n');
    write(joinMsg);
}

void TLWbClient::slotError(QAbstractSocket::SocketError err)
{

}
