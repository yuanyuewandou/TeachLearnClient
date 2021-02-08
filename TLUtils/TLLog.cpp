#include "TLLog.h"
#include<QMutex>
#include<QFile>
#include<QDateTime>
#include<QTextStream>
TLLog::TLLog(QObject *parent) : QObject(parent)
{
    initLog();
}

void MessageOutput(QtMsgType type,const QMessageLogContext &context,const QString &msg)
{
    //加锁：避免对文件的同时读写
    static QMutex mutex;
    mutex.lock();
    QByteArray localMsg = msg.toLocal8Bit();
    QString strOutStream = "";
    switch (type)
    {
        case QtDebugMsg:
              strOutStream = QString("%1 %2 %3 %4 [Debug] %5 \n").arg(QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss")).arg(QString(context.file)).arg(context.line).arg(QString(context.function)).arg(QString(localMsg));
          break;
        case QtInfoMsg:
              strOutStream = QString("%1 %2 %3 %4 [Info]: %5 \n").arg(QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss")).arg(QString(context.file)).arg(context.line).arg(QString(context.function)).arg(QString(localMsg));
          break;
        case QtWarningMsg:
              strOutStream = QString("%1 %2 %3 %4 [Warning]: %5 \n").arg(QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss")).arg(QString(context.file)).arg(context.line).arg(QString(context.function)).arg(QString(localMsg));
          break;
        case QtCriticalMsg:
              strOutStream = QString("%1 %2 %3 %4 [Critical]: %5 \n").arg(QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss")).arg(QString(context.file)).arg(context.line).arg(QString(context.function)).arg(QString(localMsg));
          break;
        case QtFatalMsg:
              strOutStream = QString("%1 %2 %3 %4 [Fatal]: %5 \n").arg(QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss")).arg(QString(context.file)).arg(context.line).arg(QString(context.function)).arg(QString(localMsg));
          abort();
    }
     QString strFileName = QString("%1.txt").arg(QDateTime::currentDateTime().date().toString("yyyyMMdd"));
     QFile logfile(strFileName);
     logfile.open(QIODevice::WriteOnly | QIODevice::Append);
     if(strOutStream != "")
     {
         QTextStream logStream(&logfile);
         logStream<<strOutStream<<"\r\n";
     }
     logfile.flush();
     logfile.close();
     mutex.unlock();
}

void TLLog::initLog()
{
     qInstallMessageHandler(MessageOutput);
}
