#include<QApplication>
#include "TLSettingObj.h"
#include "TLTranslateStr.h"
#include "TLLog.h"
#include <QFile>

TLSettingObj* TLSettingObj::m_pInstance = new TLSettingObj(nullptr);

TLSettingObj* TLSettingObj::getInstance()
{
    return m_pInstance;
}

TLSettingObj::TLSettingObj(QObject *parent) : QObject(parent)
{
    initData();
}

void TLSettingObj::initData()
{
    m_tranlateStr = nullptr;
    m_log = new TLLog();
}

bool TLSettingObj::runInit()
{
    qInfo() << "TeachLearnClient Run";
    bool bRet = false;
    bRet = setLanguage();
    if(bRet)
    {
        m_tranlateStr = new TLTranslateStr(nullptr);
    }

    initStyle();
    return true;
}

bool TLSettingObj::setLanguage(EN_LANGUAGE laguage)
{
    QString strLanguageFile = "lang_zh.qm";
    if(laguage == EN_LANGUAGE::LANGUAGE_EN)
        strLanguageFile = "lang_en.qm";
    m_translator.load(strLanguageFile,"./qm/");
    bool bRet = qApp->installTranslator(&m_translator);
    if(bRet && m_tranlateStr)
        m_tranlateStr->translateUi();
}

void TLSettingObj::initStyle()
{
    QFile styleFile(":/res/qss/TLStyle.qss");
    styleFile.open(QIODevice::ReadOnly);
    QString strStyleSheet(styleFile.readAll());;
    qApp->setStyleSheet(strStyleSheet);
}

