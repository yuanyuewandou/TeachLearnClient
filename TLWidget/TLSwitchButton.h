#ifndef TLSwitchButton_H
#define TLSwitchButton_H
/**
 * 1:可设置开关按钮的样式 圆角矩形/内圆形/外圆形/图片
 * 2:可设置选中和未选中时的背景颜色
 * 3:可设置选中和未选中时的滑块颜色
 * 4:可设置显示的文本
 * 5:可设置滑块离背景的间隔
 * 6:可设置圆角角度
 */
#include "TLWidget.h"
class QTimer;

class TLSwitchButton: public TLWidget
{
    Q_OBJECT
public:
    enum ButtonStyle {
        ButtonStyle_Rect = 0,     //圆角矩形
        ButtonStyle_CircleIn = 1, //内圆形
        ButtonStyle_CircleOut = 2,//外圆形
        ButtonStyle_Image = 3     //图片
    };

    TLSwitchButton(QWidget *parent = 0);
    ~TLSwitchButton();

protected:
    void mousePressEvent(QMouseEvent *);
    void resizeEvent(QResizeEvent *);
    void paintEvent(QPaintEvent *);
    void drawBg(QPainter *painter);
    void drawSlider(QPainter *painter);
    void drawText(QPainter *painter);
    void drawImage(QPainter *painter);

private:
    bool m_checked;               //是否选中
    ButtonStyle m_buttonStyle;    //开关按钮样式

    QColor m_bgColorOff;          //关闭时背景颜色
    QColor m_bgColorOn;           //打开时背景颜色

    QColor m_sliderColorOff;      //关闭时滑块颜色
    QColor m_sliderColorOn;       //打开时滑块颜色

    QColor m_textColorOff;        //关闭时文本颜色
    QColor m_textColorOn;         //打开时文本颜色

    QString m_textOff;            //关闭时显示的文字
    QString m_textOn;             //打开时显示的文字

    QString m_imageOff;           //关闭时显示的图片
    QString m_imageOn;            //打开时显示的图片

    int m_space;                  //滑块离背景间隔
    int m_rectRadius;             //圆角角度

    int m_step;                   //每次移动的步长
    int m_startX;                 //滑块开始X轴坐标
    int m_endX;                   //滑块结束X轴坐标
    QTimer *m_timer;              //定时器绘制

private slots:
    void updateValue();

public:
    bool getChecked()const
    {
        return m_checked;
    }
    ButtonStyle getButtonStyle()const
    {
        return m_buttonStyle;
    }

    QColor getBgColorOff()const
    {
        return m_bgColorOff;
    }
    QColor getBgColorOn()const
    {
        return m_bgColorOn;
    }

    QColor getSliderColorOff()const
    {
        return m_sliderColorOff;
    }
    QColor getSliderColorOn()const
    {
        return m_sliderColorOn;
    }

    QColor getTextColorOff()const
    {
        return m_textColorOff;
    }
    QColor getTextColorOn()const
    {
        return m_textColorOn;
    }

    QString getTextOff()const
    {
        return m_textOff;
    }
    QString getTextOn()const
    {
        return m_textOn;
    }

    QString getImageOff()const
    {
        return m_imageOff;
    }
    QString getImageOn()const
    {
        return m_imageOn;
    }

    int getSpace()const
    {
        return m_space;
    }
    int getRectRadius()const
    {
        return m_rectRadius;
    }

public slots:
    //设置是否选中
    void setChecked(bool checked);
    //设置风格样式
    void setButtonStyle(ButtonStyle buttonStyle);

    //设置背景颜色
    void setBgColor(QColor bgColorOff, QColor bgColorOn);
    //设置滑块颜色
    void setSliderColor(QColor sliderColorOff, QColor sliderColorOn);
    //设置文本颜色
    void setTextColor(QColor textColorOff, QColor textColorOn);

    //设置文本
    void setText(QString textOff, QString textOn);

    //设置背景图片
    void setImage(QString imageOff, QString imageOn);

    //设置间隔
    void setSpace(int space);
    //设置圆角角度
    void setRectRadius(int rectRadius);

signals:
    void checkedChanged(bool checked);
};

#endif // TLSwitchButton_H
