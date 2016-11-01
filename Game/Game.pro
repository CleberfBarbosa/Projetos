#-------------------------------------------------
#
# Project created by QtCreator 2016-06-04T09:54:40
#
#-------------------------------------------------

QT       += core gui
QT       += multimedia
QT       += widgets
QT       += core

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Test
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    warrior_selected_confirmation.cpp \
    wizard_selected_confirmation.cpp \
    assassin_selected_confirmation.cpp \
    duelo.cpp \
    selecao_mov.cpp \
    personagem.cpp

HEADERS  += mainwindow.h \
    warrior_selected_confirmation.h \
    wizard_selected_confirmation.h \
    assassin_selected_confirmation.h \
    duelo.h \
    selecao_mov.h \
    personagem.h

FORMS    += mainwindow.ui \
    warrior_selected_confirmation.ui \
    wizard_selected_confirmation.ui \
    assassin_selected_confirmation.ui \
    duelo.ui \
    selecao_mov.ui


