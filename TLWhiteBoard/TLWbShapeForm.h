#ifndef TLWBSHAPEFORM_H
#define TLWBSHAPEFORM_H

#include <QWidget>

class TLWbShape;
namespace Ui {
class TLWbShapeForm;
}

class TLWbShapeForm : public QWidget
{
    Q_OBJECT

public:
    explicit TLWbShapeForm(QWidget *parent = 0);
    ~TLWbShapeForm();
    TLWbShape* getCurrentShape();
private:
    void initUi();
    void translateUi();
    void initData();
    void initConnect();
    void initCurrentShape();
private slots:
    void slotLineClicked();
    void slotRectClicked();
    void slotOvalClicked();
    void slotTriangleClicked();
    void slotColorChanged();
    void slotLineWidthChanged();
    void slotFillTypeChanged();
private:
    Ui::TLWbShapeForm *ui;
    TLWbShape* m_currentShape;
    TLWbShape* m_lineShape;
    TLWbShape* m_rectShape;
    TLWbShape* m_ovalShape;
    TLWbShape* m_triangleShape;
};

#endif // TLWBSHAPEFORM_H
