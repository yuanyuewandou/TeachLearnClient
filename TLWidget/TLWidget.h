#ifndef TLWIDGET_H
#define TLWIDGET_H

#include <QWidget>
#include "TLImageConfig.h"
#include "TLTranslateStr.h"

class QEvent;

class TLWidget : public QWidget
{
    Q_OBJECT
public:
    explicit TLWidget(QWidget *parent = nullptr);
signals:
public slots:
private:
    virtual void translateUi();
    virtual void initUi();
    virtual void initData();
    virtual void initConnect();
    void changeEvent(QEvent*);
};

#endif // TLWIDGET_H
