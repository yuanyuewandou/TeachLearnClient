#include "TLWbShapeFillForm.h"
#include "ui_TLWbShapeFillForm.h"
#include "TLWbUiConfig.h"
TLWbShapeFillForm::TLWbShapeFillForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TLWbShapeFillForm)
{
    ui->setupUi(this);
    initData();
    initUi();
    initTranslate();
    initConnect();
}

TLWbShapeFillForm::~TLWbShapeFillForm()
{
    delete ui;
}

EN_WB_SHAPE_FILL TLWbShapeFillForm::getFillType()
{
    return m_fillType;
}

void TLWbShapeFillForm::initUi()
{
    ui->m_FillColorButton->setIcon(QIcon(IMAGE_BLACK_COLOR));
    ui->m_FillTransparentButton->setIcon(QIcon(IMAGE_TOOL_RECTANGLE));
    ui->m_FillTransparentButton->setChecked(true);
}

void TLWbShapeFillForm::initData()
{
    m_fillType = EN_WB_SHAPE_FILL::TRANSPARENT;
}

void TLWbShapeFillForm::initConnect()
{
    connect(ui->m_FillColorButton,SIGNAL(clicked(bool)),this,SLOT(slotFillColorClicked()));
    connect(ui->m_FillTransparentButton,SIGNAL(clicked(bool)),this,SLOT(slotFillTransparentClicked()));
}

void TLWbShapeFillForm::initTranslate()
{

}

void TLWbShapeFillForm::slotFillColorClicked()
{
    m_fillType = EN_WB_SHAPE_FILL::COLOR;
    emit sigFillTypeChanged();
}

void TLWbShapeFillForm::slotFillTransparentClicked()
{
    m_fillType = EN_WB_SHAPE_FILL::TRANSPARENT;
    emit sigFillTypeChanged();
}

