#include "TLWbPenForm.h"
#include "ui_TLWbPenForm.h"

TLWbPenForm::TLWbPenForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TLWbPenForm)
{
    ui->setupUi(this);
}

TLWbPenForm::~TLWbPenForm()
{
    delete ui;
}
