#ifndef TLTRANSLATESTR_H
#define TLTRANSLATESTR_H

#include <QObject>

extern QString g_strEnglish;
extern QString g_strChinese;
extern QString g_strHome;
extern QString g_strWhiteBoard;
extern QString g_strWhiteBoardTool;

class TLTranslateStr : public QObject
{
    Q_OBJECT
public:
    explicit TLTranslateStr(QObject *parent = nullptr);
    void translateUi();
signals:
public slots:
};

#endif // TLTRANSLATESTR_H
