#ifndef MAINWINDOWCONSULTARVEICULO_H
#define MAINWINDOWCONSULTARVEICULO_H

#include <QMainWindow>
#include <QString>
#include <Veiculo.h>
#include <QMessageBox>

namespace Ui {
class MainWindowConsultarVeiculo;
}

class MainWindowConsultarVeiculo : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindowConsultarVeiculo(QWidget *parent = 0);
    ~MainWindowConsultarVeiculo();
    void mostrarVeiculoPesquisado(projetoLocacao::Veiculo objetoPesquisado);
    /*
     * função mostrar veiculo serve para prencher todos os campos do objeto pesquisado
     * e deixa-los todos em off para que nao sejam modificados
     */

private:
    Ui::MainWindowConsultarVeiculo *ui;


};

#endif // MAINWINDOWCONSULTARVEICULO_H
