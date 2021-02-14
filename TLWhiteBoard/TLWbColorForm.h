#ifndef TLWBCOLORFORM_H
#define TLWBCOLORFORM_H

#include <QWidget>

namespace Ui {
class TLWbColorForm;
}

class TLWbColorForm : public QWidget
{
    Q_OBJECT

public:
    explicit TLWbColorForm(QWidget *parent = 0);
    ~TLWbColorForm();
    QColor getColor();
private:
    void initUi();
    void initData();
    void initTranslate();
    void initConnection();
signals:
    void sigColorChanged();
private slots:
    void slotColorClicked();
private:
    Ui::TLWbColorForm *ui;
    QColor m_Color;
};

#endif // TLWBCOLORFORM_H
