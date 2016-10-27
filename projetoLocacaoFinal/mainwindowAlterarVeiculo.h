#ifndef MAINWINDOWALTERARVEICULO_H
#define MAINWINDOWALTERARVEICULO_H

#include <QMainWindow>
#include <Veiculo.h>
#include <VeiculoPersistencia.h>
#include <QString>

namespace Ui {
class MainWindowAlterarVeiculo;
}

class MainWindowAlterarVeiculo : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindowAlterarVeiculo(QWidget *parent = 0);
    ~MainWindowAlterarVeiculo();

    void preencherCampos(projetoLocacao::Veiculo objetoPesquisado);

private slots:
    void on_pushButtonSalvar_clicked();

    void on_checkBoxSituacao_clicked(bool checked);

private:
    Ui::MainWindowAlterarVeiculo *ui;
    projetoLocacao::VeiculoPersistencia agendaVeiculos;
    projetoLocacao::Veiculo objetoParaExcluir;//* Uso este atributo para pegar o objeto referente a placa digitada
    bool situacaoDoVeiculo;
    //utilizei um atributo booleano para pode usar o checkbox pois nao conheço outra forma para utiliza-lo
};

#endif // MAINWINDOWALTERARVEICULO_H
