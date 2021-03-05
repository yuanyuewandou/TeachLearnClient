#ifndef TLWBCLIENT_H
#define TLWBCLIENT_H

#include <QObject>
#include <QTcpSocket>

class TLWbClientConnection : public QTcpSocket
{
    Q_OBJECT
public:
    explicit TLWbClientConnection(QObject *parent = nullptr);
    ~TLWbClientConnection();
public:
    QString info();
    QString getName();
    int getId();
    void resetState();
private:
    void initData();
    void initConnect();
    static int generateUserId();
    static int generateFigureId();
signals:
    void sigUserJoined(const QString& name,const int id);
    void sigUserLeft(const QString& name,const int id);
    void sigFiguredAddReq(const QJsonObject&);
    void sigFiguredDeleteReq(const int globalId);
public slots:
    void slotReadyRead();
protected:
    QString m_name;
    int m_id;
    static int m_userIdBase;
    static int m_figureIdBase;
};

#endif // TLWBCLIENT_H
