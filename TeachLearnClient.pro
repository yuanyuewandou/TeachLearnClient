#-------------------------------------------------
#
# Project created by QtCreator 2021-02-07T19:41:14
#
#-------------------------------------------------

QT       += core gui network
CONFIG  += c++11
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = TeachLearnClient
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

INCLUDEPATH += ./TLWidget\
                ./TLUtils\
                ./TLWhiteBoard\
                ./TLWhiteBoard/TLWbNet

SOURCES += \
        main.cpp \
        TLMainWidget.cpp \
        TLWidget/TLAnimationButton.cpp \
    TLWidget/TLWidget.cpp \
    TLWidget/TLTranslateStr.cpp \
    TLSettingObj.cpp \
    TLWidget/TLSwitchButton.cpp \
    TLUtils/TLLog.cpp \
    TLWhiteBoard/TLWhiteBoardMainWindow.cpp \
    TLWhiteBoard/TLWbToolForm.cpp \
    TLWhiteBoard/TLWbView.cpp \
    TLWhiteBoard/TLWbScene.cpp \
    TLWhiteBoard/TLWbShape.cpp \
    TLWhiteBoard/TLWbLine.cpp \
    TLWhiteBoard/TLWbRectangle.cpp \
    TLWhiteBoard/TLWbTriangle.cpp \
    TLWhiteBoard/TLWbOval.cpp \
    TLWhiteBoard/TLWbGraffiti.cpp \
    TLWhiteBoard/TLWbColorButton.cpp \
    TLWhiteBoard/TLWbColorForm.cpp \
    TLWhiteBoard/TLWbLineWidthForm.cpp \
    TLWhiteBoard/TLWbShapeForm.cpp \
    TLWhiteBoard/TLWbShapeFillForm.cpp \
    TLWhiteBoard/TLWbTextForm.cpp \
    TLWhiteBoard/TLWbPenForm.cpp \
    TLWhiteBoard/TLWbMoveWidget.cpp \
    TLWhiteBoard/TLWbToolButton.cpp \
    TLWhiteBoard/TLWbNet/TLWbClient.cpp



HEADERS += \
    TLMainWidget.h \
    TLWidget/TLAnimationButton.h \
    TLWidget/TLImageConfig.h \
    TLWidget/TLWidget.h \
    TLWidget/TLTranslateStr.h \
    TLSettingObj.h \
    TLWidget/TLSwitchButton.h \
    TLUtils/TLLog.h \
    TLWhiteBoard/TLWhiteBoardMainWindow.h \
    TLWhiteBoard/TLWbToolForm.h \
    TLWhiteBoard/TLWbView.h \
    TLWhiteBoard/TLWbScene.h \
    TLWhiteBoard/TLWbShape.h \
    TLWhiteBoard/TLWbLine.h \
    TLWhiteBoard/TLWbRectangle.h \
    TLWhiteBoard/TLWbTriangle.h \
    TLWhiteBoard/TLWbOval.h \
    TLWhiteBoard/TLWbGraffiti.h \
    TLWhiteBoard/TLWbUiConfig.h \
    TLWhiteBoard/TLWbColorButton.h \
    TLWhiteBoard/TLWbColorForm.h \
    TLWhiteBoard/TLWbLineWidthForm.h \
    TLWhiteBoard/TLWbShapeForm.h \
    TLWhiteBoard/TLWbShapeFillForm.h \
    TLWhiteBoard/TLWbTextForm.h \
    TLWhiteBoard/TLWbPenForm.h \
    TLWhiteBoard/TLWbMoveWidget.h \
    TLWhiteBoard/TLWbToolButton.h \
    TLWhiteBoard/TLWbNet/TLWbClient.h



FORMS += \
        TLMainWidget.ui \
    TLWhiteBoard/TLWhiteBoardMainWindow.ui \
    TLWhiteBoard/TLWbToolForm.ui \
    TLWhiteBoard/TLWbColorForm.ui \
    TLWhiteBoard/TLWbLineWidthForm.ui \
    TLWhiteBoard/TLWbShapeForm.ui \
    TLWhiteBoard/TLWbShapeFillForm.ui \
    TLWhiteBoard/TLWbTextForm.ui \
    TLWhiteBoard/TLWbPenForm.ui


SUBDIRS += \
    TeachLearnClient.pro

TRANSLATIONS = \
$$PWD/qm/lang_en.ts \
$$PWD/qm/lang_zh.ts

RESOURCES += \
    res.qrc


