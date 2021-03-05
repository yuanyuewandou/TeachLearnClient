#ifndef IpWidget_H
#define IpWidget_H

/**
 * IP地址输入框控件 作者:feiyangqingyun(QQ:517216493) 2017-8-11
 * 1. 可设置IP地址,自动填入框
 * 2. 可清空IP地址
 * 3. 支持按下小圆点自动切换
 * 4. 支持退格键自动切换
 * 5. 支持IP地址过滤
 * 6. 可设置背景色/边框颜色/边框圆角角度
 */

#include <QWidget>

class QLabel;
class QLineEdit;

#ifdef quc
class Q_DECL_EXPORT IpWidget : public QWidget
#else
class IpWidget : public QWidget
#endif

{
    Q_OBJECT
    Q_PROPERTY(QString ip READ getIP WRITE setIP)

public:
    explicit IpWidget(QWidget *parent = 0);

protected:
    bool eventFilter(QObject *watched, QEvent *event);

private:
    QLabel *m_labDot1;    //第一个小圆点
    QLabel *m_labDot2;    //第二个小圆点
    QLabel *m_labDot3;    //第三个小圆点

    QLineEdit *m_txtIP1;  //IP地址网段输入框1
    QLineEdit *m_txtIP2;  //IP地址网段输入框2
    QLineEdit *m_txtIP3;  //IP地址网段输入框3
    QLineEdit *m_txtIP4;  //IP地址网段输入框4

    QString m_ip;         //IP地址
    QString m_bgColor;    //背景颜色
    QString m_borderColor;//边框颜色
    int m_borderRadius;   //边框圆角角度

private slots:
    void textChanged(const QString &text);

public:
    //获取IP地址
    QString getIP()                 const;
    QSize sizeHint()                const;
    QSize minimumSizeHint()         const;

public Q_SLOTS:
    //设置IP地址
    void setIP(const QString &ip);
    //清空
    void clear();
    //设置背景颜色
    void setBgColor(const QString &bgColor);
    //设置边框颜色
    void setBorderColor(const QString &borderColor);
    //设置边框圆角角度
    void setBorderRadius(int borderRadius);

};

#endif // IpWidget_H
