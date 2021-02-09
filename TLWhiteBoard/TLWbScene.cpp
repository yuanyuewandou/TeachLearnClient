#include "TLWbScene.h"

TLWbScene::TLWbScene(QObject *parent) : QGraphicsScene(parent)
{

}

TLWbScene:: ~TLWbScene()
{

}

void TLWbScene::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    QGraphicsScene::mousePressEvent(event);
}

void TLWbScene::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    QGraphicsScene::mouseMoveEvent(event);
}

void TLWbScene::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    QGraphicsScene::mouseReleaseEvent(event);
}
