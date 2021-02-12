#include "TLWhiteBoardMainWindow.h"
#include "ui_TLWhiteBoardMainWindow.h"
#include "TLWbToolForm.h"
#include "TLWbScene.h"
#include "TLWbView.h"
#include "TLWbShape.h"

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
    TLWbToolForm* toolForm = new TLWbToolForm();
    ui->m_toolDockWidget->setWidget(toolForm);
    addDockWidget(Qt::TopDockWidgetArea, ui->m_toolDockWidget);
    setDockNestingEnabled(false);
    ui->m_toolDockWidget->hide();

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
    if(isVisible())
    {
        ui->m_toolDockWidget->show();
    }
    else
    {
        ui->m_toolDockWidget->hide();
    }
}

void TLWhiteBoardMainWindow::closeEvent(QCloseEvent *event)
{
    Q_UNUSED(event);
    ui->m_toolDockWidget->hide();
}

