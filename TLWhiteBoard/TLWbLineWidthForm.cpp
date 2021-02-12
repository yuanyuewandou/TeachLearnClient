#include "TLWbLineWidthForm.h"
#include "ui_TLWbLineWidthForm.h"

TLWbLineWidthForm::TLWbLineWidthForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TLWbLineWidthForm)
{
    ui->setupUi(this);
    ui->m_lineWidth1Button->setText("1");
    ui->m_lineWidth3Button->setText("3");
    ui->m_lineWidth5Button->setText("5");
    ui->m_lineWidth7Button->setText("7");
    ui->m_lineWidth9Button->setText("9");
}

TLWbLineWidthForm::~TLWbLineWidthForm()
{
    delete ui;
}


