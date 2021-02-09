#ifndef TLWBSCENE_H
#define TLWBSCENE_H

#include <QGraphicsScene>

class TLWbScene : public QGraphicsScene
{
    Q_OBJECT
public:
    explicit TLWbScene(QObject *parent = nullptr);
    ~TLWbScene();
signals:
protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
public slots:
};

#endif // TLWBSCENE_H
