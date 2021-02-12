#include "TLWbToolForm.h"
#include "ui_TLWbToolForm.h"

TLWbToolForm::TLWbToolForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TLWbToolForm)
{
    ui->setupUi(this);
    initUi();
    translateUi();
    initData();
    initConnect();
}

TLWbToolForm::~TLWbToolForm()
{
    delete ui;
}

void TLWbToolForm::translateUi()
{

}

void TLWbToolForm::initUi()
{

}

void TLWbToolForm::initData()
{

}

void TLWbToolForm::initConnect()
{

}

int TLWbToolForm::getType()
{
    return m_type;
}

void TLWbToolForm::slotLinePushButtonClicked()
{

}

