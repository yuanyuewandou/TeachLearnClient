#include "TLWbToolForm.h"
#include "ui_TLWbToolForm.h"
#include "TLWbUiConfig.h"
#include "TLWbShapeForm.h"

#define MIN_HEIGHT 52
#define LAYOUT_SPACING 10

TLWbToolForm::TLWbToolForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TLWbToolForm)
{
    ui->setupUi(this);
    initData();
    initUi();
    translateUi();
    initConnect();
}

TLWbToolForm::~TLWbToolForm()
{
    delete ui;
}

TLWbShape* TLWbToolForm::getCurrentShape()
{
    if(ui->m_stackedWidget->isVisible())
    {
        if(ui->m_stackedWidget->currentWidget() == ui->m_shapePage)
        {
            return ui->m_shapePage->getCurrentShape();
        }
        else if(ui->m_stackedWidget->currentWidget() == ui->m_penPage)
        {
            return ui->m_penPage->getCurrentShape();
        }
        else
            return nullptr;
    }
    else
        return nullptr;
//    return ui->m_shapePage->getCurrentShape();
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
    setHeight(1);
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

void TLWbToolForm::slotShapePushButtonClicked()
{
    ui->m_stackedWidget->show();
    ui->m_stackedWidget->setCurrentWidget(ui->m_shapePage);
    setHeight(5);
}

void TLWbToolForm::slotTextPushButtonClicked()
{
    ui->m_stackedWidget->show();
    ui->m_stackedWidget->setCurrentWidget(ui->m_textPage);
    setHeight(3);
}

void TLWbToolForm::slotPenPushButtonClicked()
{
    ui->m_stackedWidget->show();
    ui->m_stackedWidget->setCurrentWidget(ui->m_penPage);
    setHeight(3);
}

void TLWbToolForm::slotErasePushButtonClicked()
{
    ui->m_stackedWidget->hide();
    setHeight(1);
    emit sigErase();
}

void TLWbToolForm::slotSelectPushButtonClicked()
{
    ui->m_stackedWidget->hide();
    setHeight(1);
}

void TLWbToolForm::setHeight(int row)
{
    if(row > 0)
    {
        setFixedHeight(MIN_HEIGHT * row - LAYOUT_SPACING * (row -1));
    }
}
