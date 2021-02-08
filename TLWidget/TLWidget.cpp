#include "TLWidget.h"
#include<QEvent>
TLWidget::TLWidget(QWidget *parent) : QWidget(parent)
{

}

void TLWidget::initUi()
{

}

void TLWidget::translateUi()
{

}

void TLWidget::initData()
{

}

void TLWidget::initConnect()
{

}

void TLWidget::changeEvent(QEvent* event)
{
    switch (event->type())
    {
        case QEvent::LanguageChange:
            translateUi();
            break;
        default:
            QWidget::changeEvent(event);
    }
}
