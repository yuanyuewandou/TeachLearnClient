#include "TLWbColorForm.h"
#include "ui_TLWbColorForm.h"
#include "TLWbUiConfig.h"
TLWbColorForm::TLWbColorForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TLWbColorForm)
{
    ui->setupUi(this);
    initData();
    initUi();
    initTranslate();
    initConnection();
}

TLWbColorForm::~TLWbColorForm()
{
    delete ui;
}

QColor TLWbColorForm::getColor()
{
    return m_Color;
}

void TLWbColorForm::initUi()
{
    ui->m_colorBlackButton->setColor(QColor(Qt::black));
    ui->m_colorWhiteButton->setColor(QColor(Qt::white));
    ui->m_colorYellowButton->setColor(QColor(Qt::yellow));
    ui->m_colorBlueButton->setColor(QColor(Qt::blue));
    ui->m_colorGreenButton->setColor(QColor(Qt::green));
    ui->m_colorRedButton->setColor(QColor(Qt::red));
    ui->m_colorPinkButton->setColor(QColor(Qt::magenta));
    ui->m_colorGrayButton->setColor(QColor(Qt::gray));

    ui->m_colorWhiteButton->hide();
    ui->m_colorBlackButton->setChecked(true);
}

void TLWbColorForm::initData()
{
    m_Color = QColor(Qt::black);
}

void TLWbColorForm::initTranslate()
{

}

void TLWbColorForm::initConnection()
{
    connect(ui->m_colorBlackButton,SIGNAL(clicked(bool)),this,SLOT(slotColorClicked()));
    connect(ui->m_colorWhiteButton,SIGNAL(clicked(bool)),this,SLOT(slotColorClicked()));
    connect(ui->m_colorYellowButton,SIGNAL(clicked(bool)),this,SLOT(slotColorClicked()));
    connect(ui->m_colorBlueButton,SIGNAL(clicked(bool)),this,SLOT(slotColorClicked()));
    connect(ui->m_colorGreenButton,SIGNAL(clicked(bool)),this,SLOT(slotColorClicked()));
    connect(ui->m_colorRedButton,SIGNAL(clicked(bool)),this,SLOT(slotColorClicked()));
    connect(ui->m_colorPinkButton,SIGNAL(clicked(bool)),this,SLOT(slotColorClicked()));
    connect(ui->m_colorGrayButton,SIGNAL(clicked(bool)),this,SLOT(slotColorClicked()));
}

void TLWbColorForm::slotColorClicked()
{
    TLWbColorButton* pBtn = (TLWbColorButton*)sender();
    m_Color = pBtn->getColor();
    emit sigColorChanged();
}
