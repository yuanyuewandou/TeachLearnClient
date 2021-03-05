#include "TLWhiteBoardMainWindow.h"
#include "ui_TLWhiteBoardMainWindow.h"
#include "TLWbToolForm.h"
#include "TLWbScene.h"
#include "TLWbView.h"
#include "TLWbShape.h"
#include "TLWbMoveWidget.h"
#include "TLWbClient.h"

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
    m_client = new TLWbClient();
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

    m_toolForm = new TLWbToolForm(this);
    m_toolForm->setGeometry(10, 10, 350,200);
    m_toolForm->showNormal();
    TLWbMoveWidget *moveWidget = new TLWbMoveWidget(this);
    moveWidget->setWidget(m_toolForm);
    m_scene->setTooLFrom(m_toolForm);
}

void TLWhiteBoardMainWindow::initConnect()
{
    connect(m_scene,SIGNAL(sigSendAddFigureMsg(const QJsonObject&)),this,SLOT(slotSendAddFigureMsg(const QJsonObject&)));
    connect(m_scene,SIGNAL(sigSendDeleteFigureMsg(const int)),this,SLOT(slotSendDeleteFigureMsg(const int)));
    connect(m_client,SIGNAL(sigJoined(QString,int)),this,SLOT(slotJoined(QString,int)));
    connect(m_client,SIGNAL(sigJoinReply(QString,int)),this,SLOT(slotJoinReply(QString,int)));
    connect(m_client,SIGNAL(sigUserLeft(QString,int)),this,SLOT(slotUserLeft(QString,int)));
    connect(m_client,SIGNAL(sigFigureAdded(const QJsonObject&)),this,SLOT(slotFigureAdded(const QJsonObject&)));
    connect(m_client,SIGNAL(sigFigureCleared(int)),this,SLOT(slotFigureCleared(int)));
    connect(m_client,SIGNAL(sigFigureDeleted(int)),this,SLOT(slotFigureDeleted(int)));
    connect(m_toolForm,SIGNAL(sigErase()),this,SLOT(slotFigureUndo()));
}

void TLWhiteBoardMainWindow::join(const QString& name,const QString & strIp,const int & port)
{
    m_client->join(name,strIp,port);
}

void TLWhiteBoardMainWindow::left()
{
    m_client->left();
}

void TLWhiteBoardMainWindow::slotSendAddFigureMsg(const QJsonObject& figure)
{
    QString strInfo= QString("Send Add Figure");
    ui->m_statusbar->showMessage(strInfo,10000);
    m_client->sendAddFigureMsg(figure);
}

void TLWhiteBoardMainWindow::slotSendDeleteFigureMsg(const int globalId)
{
    QString strInfo= QString("Send Delete Figure");
    ui->m_statusbar->showMessage(strInfo,10000);
    m_client->sendDeleteFigureMsg(globalId);
}

void TLWhiteBoardMainWindow::slotFigureAdded(const QJsonObject& figure)
{
    QString strInfo= QString("Figure Added");
    ui->m_statusbar->showMessage(strInfo,10000);
    m_scene->addFigure(figure);
}

void TLWhiteBoardMainWindow::slotFigureCleared(const int ownerId)
{
    QString strInfo= QString("Figure Cleared");
    ui->m_statusbar->showMessage(strInfo,10000);
}

void TLWhiteBoardMainWindow::slotFigureDeleted(const int globalId)
{
    QString strInfo= QString("Figure Deleted");
    ui->m_statusbar->showMessage(strInfo,10000);
    m_scene->deleteFigure(globalId);
}

void TLWhiteBoardMainWindow::slotJoined(QString name,int id)
{
    QString strJoinedInfo = QString("user:%1 joined,id:%2").arg(name).arg(id);
    ui->m_statusbar->showMessage(strJoinedInfo,10000);
}

void TLWhiteBoardMainWindow::slotJoinReply(QString name,int id)
{
    QString strJoinedReplyInfo = QString("user:%1 join Reply,id:%2").arg(name).arg(id);
    ui->m_statusbar->showMessage(strJoinedReplyInfo,10000);
    m_scene->setUserId(id);
}

void TLWhiteBoardMainWindow::slotUserLeft(QString name,int id)
{
    QString strleftInfo = QString("user:%1 left,id:%2").arg(name).arg(id);
    ui->m_statusbar->showMessage(strleftInfo,10000);
}

void TLWhiteBoardMainWindow::slotFigureUndo()
{
    m_scene->undo();
}
