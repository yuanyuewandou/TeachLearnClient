#include "TLWbLineWidthForm.h"
#include "ui_TLWbLineWidthForm.h"

TLWbLineWidthForm::TLWbLineWidthForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TLWbLineWidthForm)
{
    ui->setupUi(this);
    initData();
    initUi();
    initTranslate();
    initConnect();
}

int TLWbLineWidthForm::getLineWidth()
{
    return m_width;
}

TLWbLineWidthForm::~TLWbLineWidthForm()
{
    delete ui;
}

void TLWbLineWidthForm::initUi()
{
    ui->m_lineWidth1Button->setText("1");
    ui->m_lineWidth3Button->setText("3");
    ui->m_lineWidth5Button->setText("5");
    ui->m_lineWidth7Button->setText("7");
    ui->m_lineWidth9Button->setText("9");

    ui->m_lineWidth1Button->setChecked(true);
}

void TLWbLineWidthForm::initData()
{
    m_width = 1;
}

void TLWbLineWidthForm::initConnect()
{
    connect(ui->m_lineWidth1Button,SIGNAL(clicked(bool)),this,SLOT(slotLineWidthChanged()));
    connect(ui->m_lineWidth3Button,SIGNAL(clicked(bool)),this,SLOT(slotLineWidthChanged()));
    connect(ui->m_lineWidth5Button,SIGNAL(clicked(bool)),this,SLOT(slotLineWidthChanged()));
    connect(ui->m_lineWidth7Button,SIGNAL(clicked(bool)),this,SLOT(slotLineWidthChanged()));
    connect(ui->m_lineWidth9Button,SIGNAL(clicked(bool)),this,SLOT(slotLineWidthChanged()));
}

void TLWbLineWidthForm::initTranslate()
{

}

void TLWbLineWidthForm::slotLineWidthChanged()
{
    TLWbToolButton* pBtn = (TLWbToolButton*)sender();
    m_width = pBtn->text().toInt();
    emit sigLineWidthChanged();
}

