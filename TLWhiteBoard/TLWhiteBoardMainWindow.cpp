#include "TLWhiteBoardMainWindow.h"
#include "ui_TLWhiteBoardMainWindow.h"
#include "TLWbToolForm.h"
#include "TLWbScene.h"
#include "TLWbView.h"
#include "TLWbShape.h"
#include "TLWbMoveWidget.h"


TLWhiteBoardMainWindow::TLWhiteBoardMainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::TLWhiteBoardMainWindow)
{
    ui->setupUi(this);
    initData();
    initUi();
    translateUi();
    initConnect();
}

TLWhiteBoardMainWindow::~TLWhiteBoardMainWindow()
{
    delete ui;
}

void TLWhiteBoardMainWindow::translateUi()
{

}

void TLWhiteBoardMainWindow::initData()
{
    m_scene = nullptr;
}

void TLWhiteBoardMainWindow::initUi()
{
    m_scene = new TLWbScene();
    m_scene->setSceneRect(0,0,800,500);
    m_scene->setUserId(151);
    TLWbView* wbView = new TLWbView(m_scene);
    wbView->setFixedSize(800,500);
    wbView->setSceneRect(0,0,800,500);
    setCentralWidget(wbView);

    TLWbToolForm* toolForm = new TLWbToolForm(this);
    toolForm->setGeometry(10, 10, 350,200);
    toolForm->showNormal();
    TLWbMoveWidget *moveWidget = new TLWbMoveWidget(this);
    moveWidget->setWidget(toolForm);
    m_scene->setTooLFrom(toolForm);
}

void TLWhiteBoardMainWindow::initConnect()
{
    connect(m_scene,SIGNAL(sigAddFigureReq(QJsonObject)),this,SLOT(slotAddFigure(QJsonObject)));
    connect(&m_client,SIGNAL(sigJoined(QString,int)),this,SLOT(slotJoined(QString,int)));
    connect(&m_client,SIGNAL(sigUserLeft(QString,int)),this,SLOT(slotUserLeft(QString,int)));
}

void TLWhiteBoardMainWindow::join(QString name)
{
    m_client.join(name,"localhost",9001);
}

void TLWhiteBoardMainWindow::slotAddFigure(QJsonObject figure)
{

}

void TLWhiteBoardMainWindow::slotJoined(QString,int)
{

}

void TLWhiteBoardMainWindow::slotUserLeft(QString,int)
{

}
