#include "TLMainWidget.h"
#include "ui_TLMainWidget.h"
#include "TLSettingObj.h"
#include "TLLog.h"

TLMainWidget::TLMainWidget(QWidget *parent) :
    TLWidget(parent),
    ui(new Ui::TLMainWidget)
{
    ui->setupUi(this);
    initUi();
    translateUi();
    initData();
    initConnect();
}

TLMainWidget::~TLMainWidget()
{
    delete ui;
}

void TLMainWidget::translateUi()
{
    ui->m_homeButton->setText(g_strHome);
    ui->m_homeButton->setImage(IMAGE_HOME);
    ui->m_languageSwitchButton->setText(g_strEnglish,g_strChinese);
}

void TLMainWidget::initUi()
{

}

void TLMainWidget::initData()
{

}

void TLMainWidget::initConnect()
{
    connect(ui->m_languageSwitchButton,SIGNAL(checkedChanged(bool)),this,SLOT(slotLanguageSwitch(bool)));
}

void TLMainWidget::slotLanguageSwitch(bool isEnglish)
{
    if(isEnglish)
        TLSettingObj::getInstance()->setLanguage(EN_LANGUAGE::LANGUAGE_EN);
    else
        TLSettingObj::getInstance()->setLanguage(EN_LANGUAGE::LANGUAGE_ZH);
}
