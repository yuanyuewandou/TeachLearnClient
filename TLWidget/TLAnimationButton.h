#ifndef TLAnimationButton_H
#define TLAnimationButton_H

#include <QVariant>
#include <QWidget>

class QPropertyAnimation;

class TLAnimationButton : public QWidget
{
    Q_OBJECT
public:
    explicit TLAnimationButton(QWidget *parent = 0);
    ~TLAnimationButton();

protected:
    void enterEvent(QEvent *);
    void leaveEvent(QEvent *);
    void paintEvent(QPaintEvent *);
    void mouseReleaseEvent(QMouseEvent *event);
private:
    bool m_enter;                         //是否进入
    bool m_leave;                         //是否离开
    int m_pixWidth;                       //图片宽度
    int m_pixHeight;                      //图片高度
    int m_oldWidth;                       //图片旧宽度
    int m_oldHeight;                      //图片旧高度

    QPropertyAnimation* m_enterAnimation; //进入动画
    QPropertyAnimation* m_leaveAnimation; //离开动画

    int m_targetWidth;                    //目标宽度
    int m_targetHeight;                   //目标高度
    QString m_text;                       //显示文字
    QString m_image;                      //图像路径


private slots:
    void enterImageChanged(QVariant index);
    void leaveImageChanged(QVariant index);

public slots:
    //设置显示的文字
    void setText(QString text);
    //设置显示的图像
    void setImage(QString image);
signals:
    void sigClicked();
};

#endif // TLAnimationButton_H
