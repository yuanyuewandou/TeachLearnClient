#ifndef TLWBSCENE_H
#define TLWBSCENE_H

#include <QGraphicsScene>
#include <QJsonObject>
#include <list>

class TLWbShape;
class TLWbToolForm;

class TLWbScene : public QGraphicsScene
{
    Q_OBJECT
public:
    explicit TLWbScene(QObject *parent = nullptr);
    ~TLWbScene();
    void setTooLFrom(TLWbToolForm* toolForm);
    void setUserId(int id);
signals:
    void sigAddFigureReq(QJsonObject figure);
protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
public slots:
protected:
    int m_toolType;
    TLWbShape* m_currentShape;
    TLWbToolForm* m_toolForm;
    int m_id;
    std::list<TLWbShape*> m_shapeList;
};

#endif // TLWBSCENE_H
