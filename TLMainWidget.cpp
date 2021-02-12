#include "TLMainWidget.h"
#include "ui_TLMainWidget.h"
#include "TLSettingObj.h"
#include "TLLog.h"
#include "TLWhiteBoardMainWindow.h"

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

    ui->m_whiteBoardButton->setText(g_strWhiteBoard);
    ui->m_whiteBoardButton->setImage(IMAGE_WHITE_BOARD);

}

void TLMainWidget::initUi()
{
    m_whiteBoardWindow = new TLWhiteBoardMainWindow(this);

//    QString strStyle = "QPushButton{\
//                    border: 0px solid red;} \
//                    QPushButton:checked{ \
//                   border:2px solid black;}";
//    ui->pushButton->setStyleSheet(strStyle);
//    ui->pushButton_2->setStyleSheet(strStyle);

}

void TLMainWidget::initData()
{
    ui->m_tableWidget->setRowCount(5);
    ui->m_tableWidget->setColumnCount(5);
}

void TLMainWidget::initConnect()
{
    connect(ui->m_languageSwitchButton,SIGNAL(checkedChanged(bool)),this,SLOT(slotLanguageSwitch(bool)));
    connect(ui->m_whiteBoardButton,SIGNAL(sigClicked()),this,SLOT(slotWhiteBoardClicked()));
}

void TLMainWidget::slotLanguageSwitch(bool isEnglish)
{
    if(isEnglish)
        TLSettingObj::getInstance()->setLanguage(EN_LANGUAGE::LANGUAGE_EN);
    else
        TLSettingObj::getInstance()->setLanguage(EN_LANGUAGE::LANGUAGE_ZH);
}

void TLMainWidget::slotWhiteBoardClicked()
{
    m_whiteBoardWindow->show();
}
