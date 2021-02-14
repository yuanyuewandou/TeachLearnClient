#include "TLWbToolButton.h"

TLWbToolButton::TLWbToolButton(QWidget *parent) : QPushButton(parent)
{
     m_strStyle = QString("QPushButton{\
                             background-color:rgb(%1,%2,%3);\
                             border: 0px solid rgb(100,125,100);}\
                             QPushButton:checked{\
                             background-color:rgb(%1,%2,%3);\
                             border:2px solid rgb(100,125,100);}");
     QString strStyle = m_strStyle.arg(255).arg(255).arg(255);
     setStyleSheet(strStyle);
}

