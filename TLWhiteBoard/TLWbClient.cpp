#include "TLWbClient.h"
#include<QDebug>
#include<QHostAddress>
#include<QJsonArray>
#include<QJsonDocument>
#include<QJsonObject>
#include<QJsonValue>

TLWbClient::TLWbClient(QObject *parent) : QTcpSocket(parent)
{
    connect(this,SIGNAL(connected()),this,SLOT(slotConnected()));
    connect(this,SIGNAL(readyRead()),this,SLOT(slotReadyRead()));
    connect(this,SIGNAL(disconnected()),this,SLOT(deleteLater()));
    connect(this,SIGNAL(error(QAbstractSocket::SocketError)),this,SLOT(slotError(QAbstractSocket::SocketError)));
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

void TLWbClient::join(QString name,QString host,int port)
{
    m_name = name;
    connectToHost(host,port);
}

void TLWbClient::left()
{
    const char leftMsg[] = "{\"type\":\"left\"}";
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

void TLWbClient::slotReadyRead()
{
    QByteArray data = readAll();
    data.chop(1);

    QJsonParseError JsonError;
    QJsonDocument doc = QJsonDocument::fromJson(data);
    if(JsonError.error == QJsonParseError::NoError)
    {
        QJsonObject obj = doc.object();
        QString type = obj.value("type").toString();
        if(type == "join_reply")
        {
            m_id = obj.value("id").toInt();
            emit sigJoined(m_name,m_id);
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

void TLWbClient::slotConnected()
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

void TLWbClient::slotError(QAbstractSocket::SocketError err)
{

}
