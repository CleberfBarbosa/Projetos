#-------------------------------------------------
#
# Project created by QtCreator 2014-06-17T09:57:47
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = projetoLocacaoFinal
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp\
    Veiculo.cpp \
    VeiculoPersistencia.cpp\
    mainwindowVeiculo.cpp\
    mainwindowNovoVeiculo.cpp\
    mainwindowConsultarVeiculo.cpp\
    mainwindowListagemVeiculo.cpp\
    mainwindowAlterarVeiculo.cpp\
    Cliente.cpp \
    ClientePersistencia.cpp \
    mainwindowCliente.cpp \
    mainwindowNovoCliente.cpp \
    mainwindowGRIDCliente.cpp \
    mainwindowLocacao.cpp \
    Locacao.cpp \
    mainwindowValidaCpf.cpp \
    mainwindowLocando.cpp \
    mainwindowVerificaPlacaDevolver.cpp \
    mainwindowDevolvendo.cpp \
    mainwindowConsultaPlacaLocacao.cpp \
    mainwindowConsultaLocacao.cpp\
    Locacaopersistencia.cpp \
    mainwindowGridLocacao.cpp

HEADERS  += mainwindow.h\
    TransformarDadosVeiculo.h \
    Veiculo.h \
    VeiculoPersistencia.h\
    mainwindowVeiculo.h\
    mainwindowNovoVeiculo.h\
    mainwindowConsultarVeiculo.h\
    mainwindowListagemVeiculo.h\
    mainwindowAlterarVeiculo.h\
    Cliente.h \
    ClientePersistencia.h \
    TransformarDadosCliente.h \
    mainwindowCliente.h \
    mainwindowNovoCliente.h \
    mainwindowGRIDCliente.h \
    CRUDCliente.h \
    mainwindowLocacao.h \
    TransformarDadosLocacao.h \
    Locacao.h \
    mainwindowValidaCpf.h \
    mainwindowLocando.h \
    mainwindowVerificaPlacaDevolver.h \
    mainwindowDevolvendo.h \
    mainwindowConsultaPlacaLocacao.h \
    mainwindowConsultaLocacao.h\
    CRUDLocacao.h\
    Locacaopersistencia.h \
    mainwindowGridLocacao.h

FORMS    += mainwindow.ui\
    mainwindowVeiculo.ui\
    mainwindowNovoVeiculo.ui\
    mainwindowConsultarVeiculo.ui\
    mainwindowListagemVeiculo.ui\
    mainwindowAlterarVeiculo.ui\
    mainwindowCliente.ui \
    mainwindowNovoCliente.ui \
    mainwindowGRIDCliente.ui \
    mainwindowLocacao.ui \
    mainwindowValidaCpf.ui \
    mainwindowLocando.ui \
    mainwindowVerificaPlacaDevolver.ui \
    mainwindowDevolvendo.ui \
    mainwindowConsultaPlacaLocacao.ui \
    mainwindowConsultaLocacao.ui \
    mainwindowGridLocacao.ui
