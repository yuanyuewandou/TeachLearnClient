#ifndef TLWBVIEW_H
#define TLWBVIEW_H

#include <QGraphicsView>
class TLWbView : public QGraphicsView
{
    Q_OBJECT
public:
    explicit TLWbView(QGraphicsScene *scene,QWidget *parent = nullptr);

signals:
protected:
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void resizeEvent(QResizeEvent *event);
public slots:
};

#endif // TLWBVIEW_H
