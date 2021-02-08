#include "TLAnimationButton.h"
#include <QPainter>
#include <QPropertyAnimation>

TLAnimationButton::TLAnimationButton(QWidget *parent) :QWidget(parent)
{
    m_enter = true;
    m_leave = false;
    m_pixWidth = 0;
    m_pixHeight = 0;
    m_oldWidth = 0;
    m_oldHeight = 0;

    m_enterAnimation = new QPropertyAnimation(this, "");
    m_enterAnimation->setStartValue(0);
    m_enterAnimation->setEndValue(5);
    m_enterAnimation->setDuration(200);
    connect(m_enterAnimation,SIGNAL(valueChanged(QVariant)), this, SLOT(enterImageChanged(QVariant)));

    m_leaveAnimation = new QPropertyAnimation(this, "");
    m_leaveAnimation->setStartValue(0);
    m_leaveAnimation->setEndValue(5);
    m_leaveAnimation->setDuration(200);
    connect(m_leaveAnimation,SIGNAL(valueChanged(QVariant)), this, SLOT(leaveImageChanged(QVariant)));
}

TLAnimationButton::~TLAnimationButton()
{
    delete m_enterAnimation;
    delete m_leaveAnimation;
}

void TLAnimationButton::enterEvent(QEvent *)
{
    m_enter = true;
    m_leave = false;
    m_pixWidth = m_pixWidth -25;
    m_pixHeight = m_pixHeight- 25;
    m_enterAnimation->start();
}

void TLAnimationButton::leaveEvent(QEvent *)
{
    m_enter = false;
    m_leave = true;
    m_pixWidth = m_oldWidth;
    m_pixHeight = m_oldHeight;
    m_leaveAnimation->start();
}

void TLAnimationButton::paintEvent(QPaintEvent *)
{
    if (m_image.isEmpty()) {
        return;
    }

    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);

    QPixmap pix(m_image);
    pix =pix.scaled(m_targetWidth, m_targetHeight, Qt::KeepAspectRatio,Qt::SmoothTransformation);

    if (m_enter || m_leave) {
        int pixX =rect().center().x() - m_targetWidth / 2;
        int pixY =rect().center().y() - m_targetHeight / 2 - 10;
        QPoint point(pixX,pixY);
        painter.drawPixmap(point,pix);
        painter.drawText(QRectF(0,height() - 20, width(), 20), Qt::AlignCenter, m_text);
    }
}

void TLAnimationButton::enterImageChanged(QVariant index)
{
    int i = index.toInt();
    m_targetWidth = m_pixWidth+ i * 5;
    m_targetHeight =m_pixHeight + i * 5;
    update();
}

void TLAnimationButton::leaveImageChanged(QVariant index)
{
    int i = index.toInt();
    m_targetWidth = m_pixWidth- i * 5;
    m_targetHeight = m_pixWidth - i * 5;
    update();
}

void TLAnimationButton::setImage(QString image)
{
    m_image =image;
    QPixmap pix(image);
    m_pixWidth =pix.width();
    m_pixHeight =pix.height();
    m_oldWidth = m_pixWidth;
    m_oldHeight = m_pixHeight;
    m_targetWidth = m_pixWidth- 25;
    m_targetHeight =m_pixHeight - 25;
    update();
}

void TLAnimationButton::setText(QString text)
{
    m_text = text;
    update();
}

void TLAnimationButton::mouseReleaseEvent(QMouseEvent *event)
{
   emit sigClicked();
}
