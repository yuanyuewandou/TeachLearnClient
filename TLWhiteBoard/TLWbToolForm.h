#ifndef TLWBTOOLFORM_H
#define TLWBTOOLFORM_H

#include <QWidget>

namespace Ui {
class TLWbToolForm;
}

enum class WB_TOOL_TYPE
{
    LINE,
    RECT,
    CORCLE
};

class TLWbToolForm : public QWidget
{
    Q_OBJECT

public:
    explicit TLWbToolForm(QWidget *parent = 0);
    ~TLWbToolForm();
public:
    WB_TOOL_TYPE getType();
private:
    void translateUi();
    void initUi();
    void initData();
    void initConnect();
private slots:
    void slotLinePushButtonClicked();
private:
    Ui::TLWbToolForm *ui;
    WB_TOOL_TYPE m_type;
};

#endif // TLWBTOOLFORM_H
