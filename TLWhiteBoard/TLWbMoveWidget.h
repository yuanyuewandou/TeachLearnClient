#ifndef TLWBMOVEWIDGET_H
#define TLWBMOVEWIDGET_H

#include <QObject>
#include <QWidget>

class TLWbMoveWidget : public QWidget
{
    Q_OBJECT
public:
    explicit TLWbMoveWidget(QWidget *parent = nullptr);
    //设置是否限定鼠标左键
    void setLeftButton(bool leftButton);
    //设置是否限定不能移出容器外面
    void setInControl(bool inControl);
    //设置要移动的控件
    void setWidget(QWidget *widget);
protected:
    bool eventFilter(QObject *watched, QEvent *event);

signals:

public slots:
private:
    QPoint m_lastPoint;   //最后按下的坐标
    bool m_pressed;       //鼠标是否按下
    bool m_leftButton;    //限定鼠标左键
    bool m_inControl;     //限定在容器内
    QWidget *m_widget;    //移动的控件
};

#endif // TLWBMOVEWIDGET_H
