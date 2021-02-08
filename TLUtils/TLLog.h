#ifndef TLLOG_H
#define TLLOG_H
#include <QObject>
#include <QDebug>
class TLLog : public QObject
{
    Q_OBJECT
public:
    explicit TLLog(QObject *parent = nullptr);

signals:

public slots:
private:
    void initLog();
};

#endif // TLLOG_H
