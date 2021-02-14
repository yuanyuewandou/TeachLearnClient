#ifndef TLWBLINEWIDTHFORM_H
#define TLWBLINEWIDTHFORM_H

#include <QWidget>

namespace Ui {
class TLWbLineWidthForm;
}

class TLWbLineWidthForm : public QWidget
{
    Q_OBJECT

public:
    explicit TLWbLineWidthForm(QWidget *parent = 0);
    ~TLWbLineWidthForm();
    int getLineWidth();
private:
    void initUi();
    void initData();
    void initConnect();
    void initTranslate();
signals:
    void sigLineWidthChanged();
private slots:
    void slotLineWidthChanged();
private:
    Ui::TLWbLineWidthForm *ui;
    int m_width;
};

#endif // TLWBLINEWIDTHFORM_H
