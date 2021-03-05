#include "TLWbClientConnection.h"
#include<QDebug>
#include<QHostAddress>
#include<QJsonArray>
#include<QJsonDocument>
#include<QJsonObject>
#include<QJsonValue>

int TLWbClientConnection::m_userIdBase = 0;
int TLWbClientConnection::generateUserId()
{
    return ++m_userIdBase;
}

int TLWbClientConnection::m_figureIdBase = 0;
int TLWbClientConnection::generateFigureId()
{
    return ++m_figureIdBase;
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
    connect(this,SIGNAL(readyRead()),this,SLOT(slotReadyRead()));
    connect(this,SIGNAL(disconnected()),this,SLOT(deleteLater()));
}

void TLWbClientConnection::slotReadyRead()
{
    while(canReadLine())
    {
        QByteArray data = readAll();
        data.chop(1);
        qDebug() << "recv msg: " << data.data();
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
                   emit sigUserJoined(m_name, m_id);
               }
           }
           else if(type == "user_left")
           {
               if(m_id > 0)
               {
                   qDebug() << m_name << " left, id - " << m_id << " from " << info();
                   emit sigUserLeft(m_name, m_id);
               }
           }
           else if(type == "figure_add")
           {
               QJsonObject figure = rootObj.value("figure").toObject();
               figure.insert("global_id",QJsonValue(generateFigureId()));
               emit sigFiguredAddReq(figure);
           }

           else if(type == "figure_delete")
           {
               int globalId = rootObj.value("global_id").toInt();
               emit sigFiguredDeleteReq(globalId);
           }
        }
        else
        {
            qDebug() << "ClientConnection::onReadyRead, json error - " << error.errorString();
        }
    }
}
