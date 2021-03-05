#include "TLWbPenForm.h"
#include "ui_TLWbPenForm.h"
#include "TLWbGraffiti.h"
TLWbPenForm::TLWbPenForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TLWbPenForm)
{
    ui->setupUi(this);
    m_shape = new TLWbGraffiti;
}

TLWbPenForm::~TLWbPenForm()
{
    delete ui;
    delete m_shape;
}

TLWbShape* TLWbPenForm::getCurrentShape()
{
    m_shape->setStrokeWidth(ui->m_lineWidthWidget->getLineWidth());
    m_shape->setStrokeColor(ui->m_colorWidget->getColor());
    return m_shape->clone();;
}
