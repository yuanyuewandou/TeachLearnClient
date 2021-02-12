#include "TLWbMoveWidget.h"
#include <QEvent>
#include <QMouseEvent>

TLWbMoveWidget::TLWbMoveWidget(QObject *parent) : QObject(parent)
{
    m_lastPoint = QPoint(0, 0);
    m_pressed = false;
    m_leftButton = false;
    m_inControl = true;
    m_widget = nullptr;
}

void TLWbMoveWidget::setLeftButton(bool leftButton)
{
    m_leftButton = leftButton;
}

void TLWbMoveWidget::setInControl(bool inControl)
{
    m_inControl = inControl;
}

void TLWbMoveWidget::setWidget(QWidget *widget)
{
    if (m_widget == nullptr)
    {
        m_widget = widget;
        m_widget->installEventFilter(this);
    }
}

bool TLWbMoveWidget::eventFilter(QObject *watched, QEvent *event)
{
    if (m_widget != nullptr && watched == m_widget) {
        QMouseEvent *mouseEvent = (QMouseEvent *)event;
        if (mouseEvent->type() == QEvent::MouseButtonPress) {
            //如果限定了只能鼠标左键拖动则判断当前是否是鼠标左键
            if (m_leftButton && mouseEvent->button() != Qt::LeftButton) {
                return false;
            }

            //判断控件的区域是否包含了当前鼠标的坐标
            if (m_widget->rect().contains(mouseEvent->pos())) {
                m_lastPoint = mouseEvent->pos();
                m_pressed = true;
            }
        } else if (mouseEvent->type() == QEvent::MouseMove && m_pressed) {
            //计算坐标偏移值,调用move函数移动过去
            int offsetX = mouseEvent->pos().x() - m_lastPoint.x();
            int offsetY = mouseEvent->pos().y() - m_lastPoint.y();
            int x = m_widget->x() + offsetX;
            int y = m_widget->y() + offsetY;
            if (m_inControl) {
                //可以自行调整限定在容器中的范围,这里默认保留20个像素在里面
                int offset = 20;
                bool xyOut = (x + m_widget->width() < offset || y + m_widget->height() < offset);
                bool whOut = false;
                QWidget *w = (QWidget *)m_widget->parent();
                if (w != 0) {
                    whOut = (w->width() - x < offset || w->height() - y < offset);
                }
                if (xyOut || whOut) {
                    return false;
                }
            }

            m_widget->move(x, y);
        } else if (mouseEvent->type() == QEvent::MouseButtonRelease && m_pressed) {
           m_pressed = false;
        }
    }
    return QObject::eventFilter(watched, event);
}
