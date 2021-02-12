#include "TLWbToolForm.h"
#include "ui_TLWbToolForm.h"
#include "TLWbUiConfig.h"
#include "TLWbShapeForm.h"

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
    ui->m_selectButton->setIcon(QIcon(IMAGE_TOOL_SELECT));
    ui->m_toolPenButton->setIcon(QIcon(IMAGE_TOOL_PEN));
    ui->m_toolEraseButton->setIcon(QIcon(IMAGE_TOOL_ERASE));
    ui->m_toolTextButton->setIcon(QIcon(IMAGE_TOOL_TEXT));
    ui->m_toolShapeButton->setIcon(QIcon(IMAGE_TOOL_SHAPES));
    ui->m_stackedWidget->hide();
}

void TLWbToolForm::initData()
{

}

void TLWbToolForm::initConnect()
{
    connect(ui->m_toolShapeButton,SIGNAL(clicked(bool)),this,SLOT(slotShapePushButtonClicked()));
    connect(ui->m_toolTextButton,SIGNAL(clicked(bool)),this,SLOT(slotTextPushButtonClicked()));
    connect(ui->m_toolEraseButton,SIGNAL(clicked(bool)),this,SLOT(slotErasePushButtonClicked()));
    connect(ui->m_toolPenButton,SIGNAL(clicked(bool)),this,SLOT(slotPenPushButtonClicked()));
    connect(ui->m_selectButton,SIGNAL(clicked(bool)),this,SLOT(slotSelectPushButtonClicked()));
}

int TLWbToolForm::getType()
{
    return m_type;
}

void TLWbToolForm::slotShapePushButtonClicked()
{
    ui->m_stackedWidget->show();
    ui->m_stackedWidget->setCurrentWidget(ui->m_shapePage);
}

void TLWbToolForm::slotTextPushButtonClicked()
{
    ui->m_stackedWidget->show();
    ui->m_stackedWidget->setCurrentWidget(ui->m_textPage);
}

void TLWbToolForm::slotPenPushButtonClicked()
{
    ui->m_stackedWidget->show();
    ui->m_stackedWidget->setCurrentWidget(ui->m_penPage);
}

void TLWbToolForm::slotErasePushButtonClicked()
{
    ui->m_stackedWidget->hide();
}

void TLWbToolForm::slotSelectPushButtonClicked()
{
    ui->m_stackedWidget->hide();
}
