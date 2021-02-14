#include "TLWbShapeForm.h"
#include "ui_TLWbShapeForm.h"
#include "TLWbUiConfig.h"
#include "TLWbShape.h"
#include "TLWbLine.h"
#include "TLWbRectangle.h"
#include "TLWbOval.h"
#include "TLWbTriangle.h"

TLWbShapeForm::TLWbShapeForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TLWbShapeForm)
{
    ui->setupUi(this);
    initData();
    initUi();
    translateUi();
    initConnect();
}

TLWbShapeForm::~TLWbShapeForm()
{
    delete ui;
}

TLWbShape* TLWbShapeForm::getCurrentShape()
{
    return m_currentShape->clone();
}

void TLWbShapeForm::initData()
{
    m_lineShape = new TLWbLine();
    m_rectShape = new TLWbRectangle();
    m_ovalShape = new TLWbOval();
    m_triangleShape = new TLWbTriangle();
    m_currentShape = m_lineShape;
    initCurrentShape();
}

void TLWbShapeForm::initUi()
{
    //tool
    ui->m_toolLineButton->setIcon(QIcon(IMAGE_TOOL_LINE));
    ui->m_toolOvalButton->setIcon(QIcon(IMAGE_TOOL_OVAL));
    ui->m_toolTriangleButton->setIcon(QIcon(IMAGE_TOOL_TRIANGLE));
    ui->m_toolRectButton->setIcon(QIcon(IMAGE_TOOL_RECTANGLE));
    //ui->m_toolGraffitiButton->setIcon(QIcon(IMAGE_TOOL_PEN));
    ui->m_toolLineButton->setChecked(true);
}

void TLWbShapeForm::translateUi()
{

}

void TLWbShapeForm::initConnect()
{
    connect(ui->m_toolLineButton,SIGNAL(clicked(bool)),this,SLOT(slotLineClicked()));
    connect(ui->m_toolOvalButton,SIGNAL(clicked(bool)),this,SLOT(slotOvalClicked()));
    connect(ui->m_toolTriangleButton,SIGNAL(clicked(bool)),this,SLOT(slotTriangleClicked()));
    connect(ui->m_toolRectButton,SIGNAL(clicked(bool)),this,SLOT(slotRectClicked()));
    connect(ui->m_colorWidget,SIGNAL(sigColorChanged()),this,SLOT(slotColorChanged()));
    connect(ui->m_lineWidthWidget,SIGNAL(sigLineWidthChanged()),this,SLOT(slotLineWidthChanged()));
    connect(ui->m_shapeFillWidget,SIGNAL(sigFillTypeChanged()),this,SLOT(slotFillTypeChanged()));
}

void TLWbShapeForm::slotLineClicked()
{
    m_currentShape = m_lineShape;
    initCurrentShape();
}

void TLWbShapeForm::slotRectClicked()
{
    m_currentShape = m_rectShape;
    initCurrentShape();
}

void TLWbShapeForm::slotOvalClicked()
{
    m_currentShape = m_ovalShape;
    initCurrentShape();
}

void TLWbShapeForm::slotTriangleClicked()
{
    m_currentShape = m_triangleShape;
    initCurrentShape();
}

void TLWbShapeForm::initCurrentShape()
{
    slotFillTypeChanged();
}

void TLWbShapeForm::slotColorChanged()
{
    EN_WB_SHAPE_FILL type = ui->m_shapeFillWidget->getFillType();
    if(type == EN_WB_SHAPE_FILL::COLOR)
    {
        m_currentShape->setFillColor(ui->m_colorWidget->getColor());
    }
    else if(type == EN_WB_SHAPE_FILL::TRANSPARENT)
    {
        m_currentShape->setFillColor(Qt::transparent);
        m_currentShape->setStrokeColor(ui->m_colorWidget->getColor());
    }
}

void TLWbShapeForm::slotLineWidthChanged()
{
    m_currentShape->setStrokeWidth(ui->m_lineWidthWidget->getLineWidth());
}

void TLWbShapeForm::slotFillTypeChanged()
{
    EN_WB_SHAPE_FILL type = ui->m_shapeFillWidget->getFillType();
    if(type == EN_WB_SHAPE_FILL::COLOR)
    {
        m_currentShape->setFillColor(ui->m_colorWidget->getColor());
        m_currentShape->setStrokeWidth(0);
    }
    else if(type == EN_WB_SHAPE_FILL::TRANSPARENT)
    {
        m_currentShape->setFillColor(Qt::transparent);
        m_currentShape->setStrokeColor(ui->m_colorWidget->getColor());
        slotLineWidthChanged();
    }
}
