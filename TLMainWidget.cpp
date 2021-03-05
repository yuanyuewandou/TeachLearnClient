#include "TLMainWidget.h"
#include "ui_TLMainWidget.h"
#include "TLSettingObj.h"
#include "TLLog.h"
#include "TLWhiteBoardMainWindow.h"

#define DEFAULT_USER   "xiaoyuhao"
#define DEFAULT_IP   "192.168.1.6"
#define DEFAULT_PORT 9001

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

    ui->m_userLabel->setText(g_strUserName + g_strMaoHao);
    ui->m_ipLabel->setText(g_strIp + g_strMaoHao);
    ui->m_portLabel->setText(g_strPort + g_strMaoHao);
}

void TLMainWidget::initUi()
{
    m_whiteBoardWindow = new TLWhiteBoardMainWindow(this);
    ui->m_userLineEdit->setText(DEFAULT_USER);
    ui->m_ipWidget->setIP(DEFAULT_IP);
    ui->m_portLineEdit->setText(QString::number(DEFAULT_PORT));
}

void TLMainWidget::initData()
{

}

void TLMainWidget::initConnect()
{
    connect(ui->m_languageSwitchButton,SIGNAL(checkedChanged(bool)),this,SLOT(slotLanguageSwitch(bool)));
    connect(ui->m_whiteBoardButton,SIGNAL(sigClicked()),this,SLOT(slotWhiteBoardClicked()));
    connect(ui->m_leftPushButton,SIGNAL(clicked(bool)),this,SLOT(slotLeftClicked()));
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
    QString strUserName = ui->m_userLineEdit->text();
    if(!strUserName.isEmpty())
    {
        m_whiteBoardWindow->show();
        m_whiteBoardWindow->join(strUserName,ui->m_ipWidget->getIP(),
                                 ui->m_portLineEdit->text().toInt());
    }
}

void TLMainWidget::slotLeftClicked()
{
    m_whiteBoardWindow->left();
}
