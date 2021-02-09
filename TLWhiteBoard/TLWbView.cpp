#include "TLWbView.h"
#include <QMouseEvent>
#include <QResizeEvent>
TLWbView::TLWbView(QGraphicsScene *scene,QWidget *parent) :
    QGraphicsView(scene,parent)
{
    setRenderHint(QPainter::Antialiasing,true);
}

void TLWbView::mousePressEvent(QMouseEvent *event)
{
    QGraphicsView::mousePressEvent(event);
}

void TLWbView::mouseMoveEvent(QMouseEvent *event)
{
    QGraphicsView::mouseMoveEvent(event);
}

void TLWbView::mouseReleaseEvent(QMouseEvent *event)
{
    QGraphicsView::mouseReleaseEvent(event);
}

void TLWbView::resizeEvent(QResizeEvent *event)
{
    QGraphicsView::resizeEvent(event);
    const QSize& size = event->size();
    auto s = scene();
    if(s != nullptr)
    {
        QRectF rc(0,0,size.width(),size.height());
        setSceneRect(rc);
        s->setSceneRect(rc);
    }
}

