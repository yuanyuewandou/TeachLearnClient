#ifndef TLSETTINGOBJ_H
#define TLSETTINGOBJ_H

#include <QObject>
#include <QTranslator>

enum class EN_LANGUAGE
{
    LANGUAGE_EN,
    LANGUAGE_ZH
};

class TLTranslateStr;
class TLLog;
class TLSettingObj : public QObject
{
    Q_OBJECT
public:
    static TLSettingObj* getInstance();
    void initData();
    bool runInit();
    void initStyle();
    bool setLanguage(EN_LANGUAGE laguage = EN_LANGUAGE::LANGUAGE_ZH);
private:
    explicit TLSettingObj(QObject *parent = nullptr);
signals:
public slots:
private:
    static TLSettingObj* m_pInstance;
    QTranslator m_translator;
    TLTranslateStr* m_tranlateStr;
    TLLog* m_log;
};

#endif // TLSETTINGOBJ_H
