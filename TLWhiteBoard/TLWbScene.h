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
    void setUserId(const int id);
    void addFigure(const QJsonObject& figure);
    void deleteFigure(const int globalId);
    void undo();
signals:
    void sigSendAddFigureMsg(const QJsonObject& figure);
    void sigSendDeleteFigureMsg(const int globalId);
protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
private:
    bool setShapePos(TLWbShape* shape,const QJsonArray& points);
public slots:
protected:
    int m_toolType;
    TLWbShape* m_currentShape;
    TLWbToolForm* m_toolForm;
    int m_id;
    std::list<TLWbShape*> m_shapeList;
};

#endif // TLWBSCENE_H
