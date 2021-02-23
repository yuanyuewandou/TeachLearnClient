#include <QCoreApplication>
#include "TLWbServer.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    TLWbServer  server;
    server.listen(QHostAddress::Any,9001);
    return a.exec();
}
