#include "TLTranslateStr.h"

QString g_strEnglish;
QString g_strChinese;
QString g_strHome;
QString g_strWhiteBoard;
TLTranslateStr::TLTranslateStr(QObject *parent) : QObject(parent)
{
    translateUi();
}

void TLTranslateStr::translateUi()
{
    g_strEnglish = tr("English");
    g_strChinese = tr("Chinese");
    g_strHome = tr("Home");
    g_strWhiteBoard = tr("White Board");
}

