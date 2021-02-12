#ifndef TLWBSCENE_H
#define TLWBSCENE_H

#include <QGraphicsScene>

class TLWbShape;
class TLWbScene : public QGraphicsScene
{
    Q_OBJECT
public:
    explicit TLWbScene(QObject *parent = nullptr);
    ~TLWbScene();
    void setToolType(int type);
signals:
protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
public slots:
protected:
    int m_toolType;
    TLWbShape* m_currentShape;
};

#endif // TLWBSCENE_H
