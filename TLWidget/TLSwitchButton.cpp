#include "TLSwitchButton.h"
#include <QPainter>
#include <QEvent>
#include <QTimer>

TLSwitchButton::TLSwitchButton(QWidget *parent): TLWidget(parent)
{
    m_checked = false;
    m_buttonStyle	= ButtonStyle_Rect;

    m_bgColorOff = QColor(225, 225, 225);
    m_bgColorOn = QColor(250, 250, 250);
    m_bgColorOff = m_bgColorOn;

    m_sliderColorOff = QColor(100, 100, 100);
    m_sliderColorOn = QColor(100, 184, 255);
    m_sliderColorOff = m_sliderColorOn;

    m_textColorOff = QColor(255, 255, 255);
    m_textColorOn = QColor(10, 10, 10);
    m_textColorOff = m_textColorOn;

    m_textOff = "off";
    m_textOn = "on";

    m_imageOff = "./image/switchOff.png";
    m_imageOn = "./image/switchOn.png";

    m_space = 2;
    m_rectRadius = 5;

    m_step = width() / 50;
    m_startX = 0;
    m_endX = 0;

    m_timer = new QTimer(this);
    m_timer->setInterval(5);
    connect(m_timer, SIGNAL(timeout()), this, SLOT(updateValue()));

    setFont(QFont("Microsoft Yahei", 10));
}

TLSwitchButton::~TLSwitchButton()
{

}

void TLSwitchButton::mousePressEvent(QMouseEvent *)
{
    m_checked = !m_checked;
    emit checkedChanged(m_checked);

    //每次移动的步长为宽度的 50分之一
    m_step = width() / 50;

    //状态切换改变后自动计算终点坐标
    if (m_checked) {
        if (m_buttonStyle == ButtonStyle_Rect) {
            m_endX = width() - width() / 2;
        } else if (m_buttonStyle == ButtonStyle_CircleIn) {
            m_endX = width() - height();
        } else if (m_buttonStyle == ButtonStyle_CircleOut) {
            m_endX = width() - height() + m_space;
        }
    } else {
        m_endX = 0;
    }

    m_timer->start();
}

void TLSwitchButton::resizeEvent(QResizeEvent *)
{
    //每次移动的步长为宽度的 50分之一
    m_step = width() / 50;

    //尺寸大小改变后自动设置起点坐标为终点
    if (m_checked) {
        if (m_buttonStyle == ButtonStyle_Rect) {
            m_startX = width() - width() / 2;
        } else if (m_buttonStyle == ButtonStyle_CircleIn) {
            m_startX = width() - height();
        } else if (m_buttonStyle == ButtonStyle_CircleOut) {
            m_startX = width() - height() + m_space;
        }
    } else {
        m_startX = 0;
    }

    update();
}

void TLSwitchButton::paintEvent(QPaintEvent *)
{
    //绘制准备工作,启用反锯齿
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);

    if (m_buttonStyle == ButtonStyle_Image) {
        //绘制图片
        drawImage(&painter);
    } else {
        //绘制背景
        drawBg(&painter);
        //绘制滑块
        drawSlider(&painter);
        //绘制文字
        drawText(&painter);
    }
}

void TLSwitchButton::drawBg(QPainter *painter)
{
    painter->save();
    painter->setPen(Qt::NoPen);

    if (!m_checked) {
        painter->setBrush(m_bgColorOff);
    } else {
        painter->setBrush(m_bgColorOn);
    }

    if (m_buttonStyle == ButtonStyle_Rect) {
        painter->drawRoundedRect(rect(), m_rectRadius, m_rectRadius);
    } else if (m_buttonStyle == ButtonStyle_CircleIn) {
        QRect rect(0, 0, width(), height());
        //半径为高度的一半
        int radius = rect.height() / 2;
        //圆的宽度为高度
        int circleWidth = rect.height();

        QPainterPath path;
        path.moveTo(radius, rect.left());
        path.arcTo(QRectF(rect.left(), rect.top(), circleWidth, circleWidth), 90, 180);
        path.lineTo(rect.width() - radius, rect.height());
        path.arcTo(QRectF(rect.width() - rect.height(), rect.top(), circleWidth, circleWidth), 270, 180);
        path.lineTo(radius, rect.top());

        painter->drawPath(path);
    } else if (m_buttonStyle == ButtonStyle_CircleOut) {
        QRect rect(m_space, m_space, width() - m_space * 2, height() - m_space * 2);
        painter->drawRoundedRect(rect, m_rectRadius, m_rectRadius);
    }

    painter->restore();
}

void TLSwitchButton::drawSlider(QPainter *painter)
{
    painter->save();
    painter->setPen(Qt::NoPen);

    if (!m_checked) {
        painter->setBrush(m_sliderColorOff);
    } else {
        painter->setBrush(m_sliderColorOn);
    }

    if (m_buttonStyle == ButtonStyle_Rect) {
        int sliderWidth = width() / 2 - m_space * 2;
        int sliderHeight = height() - m_space * 2;
        QRect sliderRect(m_startX + m_space, m_space, sliderWidth , sliderHeight);
        painter->drawRoundedRect(sliderRect, m_rectRadius, m_rectRadius);
    } else if (m_buttonStyle == ButtonStyle_CircleIn) {
        QRect rect(0, 0, width(), height());
        int sliderWidth = rect.height() - m_space * 2;
        QRect sliderRect(m_startX + m_space, m_space, sliderWidth, sliderWidth);
        painter->drawEllipse(sliderRect);
    } else if (m_buttonStyle == ButtonStyle_CircleOut) {
        QRect rect(0, 0, width() - m_space, height() - m_space);
        int sliderWidth = rect.height();
        QRect sliderRect(m_startX, m_space / 2, sliderWidth, sliderWidth);
        painter->drawEllipse(sliderRect);
    }

    painter->restore();
}

void TLSwitchButton::drawText(QPainter *painter)
{
    painter->save();

    if (!m_checked) {
        painter->setPen(m_textColorOff);
        painter->drawText(width() / 2, 0, width() / 2 - m_space, height(), Qt::AlignCenter, m_textOff);
    } else {
        painter->setPen(m_textColorOn);
        painter->drawText(0, 0, width() / 2 + m_space * 2, height(), Qt::AlignCenter, m_textOn);
    }

    painter->restore();
}

void TLSwitchButton::drawImage(QPainter *painter)
{
    painter->save();

    QPixmap pix;

    if (!m_checked) {
        pix = QPixmap(m_imageOff);
    } else {
        pix = QPixmap(m_imageOn);
    }

    //自动等比例平滑缩放居中显示
    int targetWidth = pix.width();
    int targetHeight = pix.height();
    pix = pix.scaled(targetWidth, targetHeight, Qt::KeepAspectRatio, Qt::SmoothTransformation);

    int pixX = rect().center().x() - targetWidth / 2;
    int pixY = rect().center().y() - targetHeight / 2;
    QPoint point(pixX, pixY);
    painter->drawPixmap(point, pix);

    painter->restore();
}

void TLSwitchButton::updateValue()
{
    if (m_checked) {
        if (m_startX < m_endX) {
            m_startX = m_startX + m_step;
        } else {
            m_startX = m_endX;
            m_timer->stop();
        }
    } else {
        if (m_startX > m_endX) {
            m_startX = m_startX - m_step;
        } else {
            m_startX = m_endX;
            m_timer->stop();
        }
    }

    update();
}

void TLSwitchButton::setChecked(bool checked)
{
    if (m_checked != checked) {
        m_checked = checked;
        emit checkedChanged(checked);
        update();
    }
}

void TLSwitchButton::setButtonStyle(TLSwitchButton::ButtonStyle buttonStyle)
{
    m_buttonStyle = buttonStyle;
    update();
}

void TLSwitchButton::setBgColor(QColor bgColorOff, QColor bgColorOn)
{
    m_bgColorOff = bgColorOff;
    m_bgColorOn = bgColorOn;
    update();
}

void TLSwitchButton::setSliderColor(QColor sliderColorOff, QColor sliderColorOn)
{
    m_sliderColorOff = sliderColorOff;
    m_sliderColorOn = sliderColorOn;
    update();
}

void TLSwitchButton::setTextColor(QColor textColorOff, QColor textColorOn)
{
    m_textColorOff = textColorOff;
    m_textColorOn = textColorOn;
    update();
}

void TLSwitchButton::setText(QString textOff, QString textOn)
{
    m_textOff = textOff;
    m_textOn = textOn;
    update();
}

void TLSwitchButton::setImage(QString imageOff, QString imageOn)
{
    m_imageOff = imageOff;
    m_imageOn = imageOn;
    update();
}

void TLSwitchButton::setSpace(int space)
{
    m_space = space;
    update();
}

void TLSwitchButton::setRectRadius(int rectRadius)
{
    m_rectRadius = rectRadius;
    update();
}
