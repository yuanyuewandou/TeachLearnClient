#include "TLWbToolDockWidget.h"
#include "ui_TLWbToolDockWidget.h"
#include<QPushButton>

TLWbToolDockWidget::TLWbToolDockWidget(QWidget *parent) :
    QDockWidget(parent),
    ui(new Ui::TLWbToolDockWidget)
{
    ui->setupUi(this);
    initUi();
    translateUi();
    initData();
    initConnect();
}

TLWbToolDockWidget::~TLWbToolDockWidget()
{
    delete ui;
}

void TLWbToolDockWidget::translateUi()
{

}

void TLWbToolDockWidget::initUi()
{
    this->setWindowTitle(g_strWhiteBoard);
    setFeatures(QDockWidget::DockWidgetMovable | QDockWidget::DockWidgetFloatable);
    setAllowedAreas(Qt::LeftDockWidgetArea | Qt::RightDockWidgetArea);
}

void TLWbToolDockWidget::initData()
{

}

void TLWbToolDockWidget::initConnect()
{

}
