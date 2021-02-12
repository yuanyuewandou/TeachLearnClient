#include "TLWbTextForm.h"
#include "ui_TLWbTextForm.h"

TLWbTextForm::TLWbTextForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TLWbTextForm)
{
    ui->setupUi(this);
    ui->m_fontSize5Button->setText("5");
    ui->m_fontSize10Button->setText("10");
    ui->m_fontSize15Button->setText("15");
    ui->m_fontSize20Button->setText("20");
    ui->m_fontSize25Button->setText("25");
}

TLWbTextForm::~TLWbTextForm()
{
    delete ui;
}
