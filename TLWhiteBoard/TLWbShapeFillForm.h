#ifndef TLWBSHAPEFILLFORM_H
#define TLWBSHAPEFILLFORM_H

#include <QWidget>

enum class EN_WB_SHAPE_FILL
{
    COLOR,
    TRANSPARENT
};

namespace Ui {
class TLWbShapeFillForm;
}

class TLWbShapeFillForm : public QWidget
{
    Q_OBJECT

public:
    explicit TLWbShapeFillForm(QWidget *parent = 0);
    ~TLWbShapeFillForm();
    EN_WB_SHAPE_FILL getFillType();
private:
    void initUi();
    void initData();
    void initConnect();
    void initTranslate();
signals:
    void sigFillTypeChanged();
private slots:
    void slotFillColorClicked();
    void slotFillTransparentClicked();
private:
    Ui::TLWbShapeFillForm *ui;
    EN_WB_SHAPE_FILL m_fillType;
};

#endif // TLWBSHAPEFILLFORM_H
