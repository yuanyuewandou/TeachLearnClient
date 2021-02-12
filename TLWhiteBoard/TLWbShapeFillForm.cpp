#include "TLWbShapeFillForm.h"
#include "ui_TLWbShapeFillForm.h"

TLWbShapeFillForm::TLWbShapeFillForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TLWbShapeFillForm)
{
    ui->setupUi(this);
}

TLWbShapeFillForm::~TLWbShapeFillForm()
{
    delete ui;
}
