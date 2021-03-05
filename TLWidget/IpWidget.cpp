#pragma execution_character_set("utf-8")

#include "IpWidget.h"
#include "qlabel.h"
#include "qlineedit.h"
#include "qboxlayout.h"
#include "qvalidator.h"
#include "qevent.h"
#include "qdebug.h"
#if (QT_VERSION < QT_VERSION_CHECK(6,0,0))
#include "qregexp.h"
#endif

IpWidget::IpWidget(QWidget *parent) : QWidget(parent)
{
    m_bgColor = "#FFFFFF";
    m_borderColor = "#A6B5B8";
    m_borderRadius = 3;

    //用于显示小圆点的标签,居中对齐
    m_labDot1 = new QLabel;
    m_labDot1->setAlignment(Qt::AlignCenter);
    m_labDot1->setText(".");

    m_labDot2 = new QLabel;
    m_labDot2->setAlignment(Qt::AlignCenter);
    m_labDot2->setText(".");

    m_labDot3 = new QLabel;
    m_labDot3->setAlignment(Qt::AlignCenter);
    m_labDot3->setText(".");

    //用于输入IP地址的文本框,居中对齐
    m_txtIP1 = new QLineEdit;
    m_txtIP1->setObjectName("m_txtIP1");
    m_txtIP1->setAlignment(Qt::AlignCenter);
    m_txtIP1->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    connect(m_txtIP1, SIGNAL(textChanged(QString)), this, SLOT(textChanged(QString)));

    m_txtIP2 = new QLineEdit;
    m_txtIP2->setObjectName("m_txtIP2");
    m_txtIP2->setAlignment(Qt::AlignCenter);
    m_txtIP2->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    connect(m_txtIP2, SIGNAL(textChanged(QString)), this, SLOT(textChanged(QString)));

    m_txtIP3 = new QLineEdit;
    m_txtIP3->setObjectName("m_txtIP3");
    m_txtIP3->setAlignment(Qt::AlignCenter);
    m_txtIP3->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    connect(m_txtIP3, SIGNAL(textChanged(QString)), this, SLOT(textChanged(QString)));

    m_txtIP4 = new QLineEdit;
    m_txtIP4->setObjectName("m_txtIP4");
    m_txtIP4->setAlignment(Qt::AlignCenter);
    m_txtIP4->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    connect(m_txtIP4, SIGNAL(textChanged(QString)), this, SLOT(textChanged(QString)));

#if (QT_VERSION < QT_VERSION_CHECK(6,0,0))
    //设置IP地址校验过滤
    QRegExp regExp("(2[0-5]{2}|2[0-4][0-9]|1?[0-9]{1,2})");
    QRegExpValidator *validator = new QRegExpValidator(regExp, this);
    m_txtIP1->setValidator(validator);
    m_txtIP2->setValidator(validator);
    m_txtIP3->setValidator(validator);
    m_txtIP4->setValidator(validator);
#endif

    //绑定事件过滤器,识别键盘按下
    m_txtIP1->installEventFilter(this);
    m_txtIP2->installEventFilter(this);
    m_txtIP3->installEventFilter(this);
    m_txtIP4->installEventFilter(this);

    QFrame *frame = new QFrame;
    frame->setObjectName("frameIP");

    QStringList qss;
    qss.append(QString("QFrame#frameIP{border:1px solid %1;border-radius:%2px;}").arg(m_borderColor).arg(m_borderRadius));
    qss.append(QString("QLabel{min-width:15px;background-color:%1;}").arg(m_bgColor));
    qss.append(QString("QLineEdit{background-color:%1;border:none;}").arg(m_bgColor));
    qss.append(QString("QLineEdit#m_txtIP1{border-top-left-radius:%1px;border-bottom-left-radius:%1px;}").arg(m_borderRadius));
    qss.append(QString("QLineEdit#m_txtIP4{border-top-right-radius:%1px;border-bottom-right-radius:%1px;}").arg(m_borderRadius));
    frame->setStyleSheet(qss.join(""));

    QVBoxLayout *verticalLayout = new QVBoxLayout(this);
    verticalLayout->setContentsMargins(0, 0, 0, 0);
    verticalLayout->setSpacing(0);
    verticalLayout->addWidget(frame);

    //将控件按照横向布局排列
    QHBoxLayout *layout = new QHBoxLayout(frame);
    layout->setContentsMargins(0, 0, 0, 0);
    layout->setSpacing(0);
    layout->addWidget(m_txtIP1);
    layout->addWidget(m_labDot1);
    layout->addWidget(m_txtIP2);
    layout->addWidget(m_labDot2);
    layout->addWidget(m_txtIP3);
    layout->addWidget(m_labDot3);
    layout->addWidget(m_txtIP4);
}

bool IpWidget::eventFilter(QObject *watched, QEvent *event)
{
    if (event->type() == QEvent::KeyPress) {
        QLineEdit *txt = (QLineEdit *)watched;
        if (txt == m_txtIP1 || txt == m_txtIP2 || txt == m_txtIP3 || txt == m_txtIP4) {
            QKeyEvent *key = (QKeyEvent *)event;

            //如果当前按下了小数点则移动焦点到下一个输入框
            if (key->text() == ".") {
                this->focusNextChild();
            }

            //如果按下了退格键并且当前文本框已经没有了内容则焦点往前移
            if (key->key() == Qt::Key_Backspace) {
                if (txt->text().length() <= 1) {
                    this->focusNextPrevChild(false);
                }
            }
        }
    }

    return QWidget::eventFilter(watched, event);
}

void IpWidget::textChanged(const QString &text)
{
    int len = text.length();
    int value = text.toInt();

    //判断当前是否输入完成一个网段,是的话则自动移动到下一个输入框
    if (len == 3) {
        if (value >= 100 && value <= 255) {
            this->focusNextChild();
        }
    }

    //拼接成完整IP地址
    m_ip = QString("%1.%2.%3.%4").arg(m_txtIP1->text()).arg(m_txtIP2->text()).arg(m_txtIP3->text()).arg(m_txtIP4->text());
}

QString IpWidget::getIP() const
{
    return m_ip;
}

QSize IpWidget::sizeHint() const
{
    return QSize(250, 20);
}

QSize IpWidget::minimumSizeHint() const
{
    return QSize(30, 10);
}

void IpWidget::setIP(const QString &ip)
{
#if (QT_VERSION < QT_VERSION_CHECK(6,0,0))
    //先检测IP地址是否合法
    QRegExp regExp("((2[0-4]\\d|25[0-5]|[01]?\\d\\d?)\\.){3}(2[0-4]\\d|25[0-5]|[01]?\\d\\d?)");
    if (!regExp.exactMatch(ip)) {
        return;
    }
#endif

    if (m_ip != ip) {
        m_ip = ip;

        //将IP地址填入各个网段
        QStringList list = ip.split(".");
        m_txtIP1->setText(list.at(0));
        m_txtIP2->setText(list.at(1));
        m_txtIP3->setText(list.at(2));
        m_txtIP4->setText(list.at(3));
    }
}

void IpWidget::clear()
{
    m_txtIP1->clear();
    m_txtIP2->clear();
    m_txtIP3->clear();
    m_txtIP4->clear();
    m_txtIP1->setFocus();
}

void IpWidget::setBgColor(const QString &bgColor)
{
    if (m_bgColor != bgColor) {
        m_bgColor = bgColor;
    }
}

void IpWidget::setBorderColor(const QString &borderColor)
{
    if (m_borderColor != borderColor) {
        m_borderColor = borderColor;
    }
}

void IpWidget::setBorderRadius(int borderRadius)
{
    if (m_borderRadius != borderRadius) {
        m_borderRadius = borderRadius;
    }
}
