#include "TLWbColorForm.h"
#include "ui_TLWbColorForm.h"
#include "TLWbUiConfig.h"
TLWbColorForm::TLWbColorForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TLWbColorForm)
{
    ui->setupUi(this);
    ui->m_colorBlackButton->setColor(QColor(Qt::black));
    ui->m_colorWhiteButton->setColor(QColor(Qt::white));
    ui->m_colorYellowButton->setColor(QColor(Qt::yellow));
    ui->m_colorBlueButton->setColor(QColor(Qt::blue));
    ui->m_colorGreenButton->setColor(QColor(Qt::green));
    ui->m_colorRedButton->setColor(QColor(Qt::red));
    ui->m_colorPinkButton->setColor(QColor(Qt::magenta));
    ui->m_colorGrayButton->setColor(QColor(Qt::gray));
}

TLWbColorForm::~TLWbColorForm()
{
    delete ui;
}
