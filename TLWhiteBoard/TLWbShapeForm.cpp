#include "TLWbShapeForm.h"
#include "ui_TLWbShapeForm.h"
#include "TLWbUiConfig.h"

TLWbShapeForm::TLWbShapeForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TLWbShapeForm)
{
    ui->setupUi(this);
    //tool
    ui->m_toolLineButton->setIcon(QIcon(IMAGE_TOOL_LINE));
    ui->m_toolOvalButton->setIcon(QIcon(IMAGE_TOOL_OVAL));
    ui->m_toolTriangleButton->setIcon(QIcon(IMAGE_TOOL_TRIANGLE));
    ui->m_toolRectButton->setIcon(QIcon(IMAGE_TOOL_RECTANGLE));
    //ui->m_toolGraffitiButton->setIcon(QIcon(IMAGE_TOOL_PEN));
}

TLWbShapeForm::~TLWbShapeForm()
{
    delete ui;
}
