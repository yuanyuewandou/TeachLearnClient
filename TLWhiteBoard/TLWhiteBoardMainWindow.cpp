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

void TLWhiteBoardMainWindow::initUi()
{
    m_scene = new TLWbScene();
    m_scene->setSceneRect(0,0,800,500);
    //m_scene->setToolType(TOOL_LINE);
    //m_scene->setToolType(TOOL_RECTANGLE);
    //m_scene->setToolType(TOOL_OVAL);
    //m_scene->setToolType(TOOL_TRIANGLE);
    m_scene->setToolType(TOOL_GRAFFITI);
    TLWbView* wbView = new TLWbView(m_scene);
    wbView->setFixedSize(800,500);
    wbView->setSceneRect(0,0,800,500);
    setCentralWidget(wbView);

    TLWbToolForm* toolForm = new TLWbToolForm(this);
    toolForm->setGeometry(10, 10, 332,300);
    toolForm->show();
    TLWbMoveWidget *moveWidget = new TLWbMoveWidget(this);
    moveWidget->setWidget(toolForm);
}

void TLWhiteBoardMainWindow::initData()
{
    m_scene = nullptr;
}

void TLWhiteBoardMainWindow::initConnect()
{

}

void TLWhiteBoardMainWindow::showEvent(QShowEvent *event)
{
    Q_UNUSED(event);

}

void TLWhiteBoardMainWindow::closeEvent(QCloseEvent *event)
{
    Q_UNUSED(event);

}

