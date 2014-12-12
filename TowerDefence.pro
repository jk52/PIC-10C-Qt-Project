#-------------------------------------------------
#
# Project created by QtCreator 2014-11-06T17:01:32
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = TowerDefence
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    quitwidget.cpp \
    gameboard.cpp \
    customLabel.cpp \
    mGameBoard.cpp \
    hGameBoard.cpp \
    wtfGameBoard.cpp \
    customLabelm.cpp \
    customLabelh.cpp \
    customLabelwtf.cpp

HEADERS  += mainwindow.h \
    quitwidget.h \
    gameboard.h \
    customLabel.h \
    mGameBoard.h \
    hGameBoard.h \
    wtfGameBoard.h \
    customLabelm.h \
    customLabelh.h \
    customLabelwtf.h

FORMS    += mainwindow.ui
