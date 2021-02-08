#include "TLMainWidget.h"
#include <QApplication>
#include "TLSettingObj.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    if(!TLSettingObj::getInstance()->runInit())
    {

    }
    TLMainWidget w;
    w.show();

    return a.exec();
}
