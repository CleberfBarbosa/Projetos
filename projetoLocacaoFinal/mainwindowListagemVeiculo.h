#ifndef MAINWINDOWLISTAGEMVEICULO_H
#define MAINWINDOWLISTAGEMVEICULO_H
#include <VeiculoPersistencia.h>
#include <Veiculo.h>
#include <QString>
#include <QMainWindow>
#include <list>
#include <Veiculo.h>

namespace Ui {
class MainWindowListagemVeiculo;
}

class MainWindowListagemVeiculo : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindowListagemVeiculo(QWidget *parent = 0);
    ~MainWindowListagemVeiculo();
    void listagemDeVeiculos();
    /*
     * essa função de listagem será chamada na mainwindowVeiculo e nao passará nada como paramentro
     * quando ela é chamada ela mesma ira chamar a função de listagem dos veiculos da classe VeiculoPersistecia,
     * essa funçao ira me retornar uma lista de objetos do tipo Veiculo, eu crio uma lista do mesmo tipo
     * para receber essa primeira lista, e aparti dessa segunda lista vou preencher minha grid de veiculos
     */

private:
    Ui::MainWindowListagemVeiculo *ui;
    projetoLocacao::VeiculoPersistencia agendaVeiculos;//é necessario usar esse objeto pois vou precisar
   //acessar a função de listagem dele
};

#endif // MAINWINDOWLISTAGEMVEICULO_H
