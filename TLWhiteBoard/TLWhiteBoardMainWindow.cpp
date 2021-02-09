#include "TLWhiteBoardMainWindow.h"
#include "ui_TLWhiteBoardMainWindow.h"
#include "TLWbToolForm.h"
TLWhiteBoardMainWindow::TLWhiteBoardMainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::TLWhiteBoardMainWindow)
{
    ui->setupUi(this);
    initUi();
    translateUi();
    initData();
    initConnect();
}

TLWhiteBoardMainWindow::~TLWhiteBoardMainWindow()
{
    delete ui;
}

void TLWhiteBoardMainWindow::translateUi()
{

}

void TLWhiteBoardMainWindow::initUi()
{
    TLWbToolForm* toolForm = new TLWbToolForm();
    ui->m_toolDockWidget->setWidget(toolForm);
    addDockWidget(Qt::LeftDockWidgetArea, ui->m_toolDockWidget);
    setDockNestingEnabled(false);
}

void TLWhiteBoardMainWindow::initData()
{

}

void TLWhiteBoardMainWindow::initConnect()
{

}
