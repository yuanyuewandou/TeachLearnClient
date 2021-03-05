#include "TLTranslateStr.h"

QString g_strEnglish;
QString g_strChinese;
QString g_strHome;
QString g_strWhiteBoard;
QString g_strWhiteBoardTool;

QString g_strMaoHao;

QString g_strUserName;
QString g_strIp;
QString g_strPort;
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
    g_strWhiteBoardTool = tr("White Board Tool");

    g_strMaoHao = tr(":");

    g_strUserName = tr("User Name");
    g_strIp = tr("IP");
    g_strPort = tr("Port");
}

