#ifndef MAINWINDOWVEICULO_H
#define MAINWINDOWVEICULO_H

#include <QMainWindow>
#include <mainwindowNovoVeiculo.h>
#include <mainwindowListagemVeiculo.h>
#include <mainwindowAlterarVeiculo.h>
#include <mainwindowConsultarVeiculo.h>
#include <list>
#include <QMessageBox>
#include <Veiculo.h>
#include <VeiculoPersistencia.h>
#include <QString>

namespace Ui {
class MainWindowVeiculo;
}

class MainWindowVeiculo : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindowVeiculo(QWidget *parent = 0);
    ~MainWindowVeiculo();
private slots:
    void on_pushButtonNovo_clicked();

    void on_pushButtonAlterar_clicked();

    void on_pushButtonExcluir_clicked();

    void on_pushButtonConsultar_clicked();

    void on_pushButtonListar_clicked();


private:
    Ui::MainWindowVeiculo *ui;
    MainWindowConsultarVeiculo irConsultarVeiculo;
    MainWindowNovoVeiculo irNovoVeiculo;
    MainWindowListagemVeiculo irListagemVeiculo;
    MainWindowAlterarVeiculo irAlterarVeiculo;


    projetoLocacao::VeiculoPersistencia agendaVeiculos;

};

#endif // MAINWINDOWVEICULO_H
