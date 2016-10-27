#include "mainwindowNovoVeiculo.h"
#include "ui_mainwindowNovoVeiculo.h"
#include <QCheckBox>
#include <QMessageBox>

//----------------------------------------------------------------------------------------------------------
MainWindowNovoVeiculo::MainWindowNovoVeiculo(QWidget *parent) :
    QMainWindow(parent),
    agendaVeiculos("AgendaDeVeiculos.csv"),
    situacaoDoVeiculo(true),//inicializando a situação do veiculo
    ui(new Ui::MainWindowNovoVeiculo)//dando nome ao arquivo
{
    ui->setupUi(this);
}




//----------------------------------------------------------------------------------------------------------
MainWindowNovoVeiculo::~MainWindowNovoVeiculo()
{
    delete ui;
}




//----------------------------------------------------------------------------------------------------------
/*
 * Quando o usuario clicar em salvar será chamado a função de incluir presente na classe veiculoPersistencia
 * e a janela será fechada
 */
void MainWindowNovoVeiculo::on_pushButtonSalvarVeiculo_clicked()
{
    try{
        QString marca=ui->lineEditMarcaVeiculo->text();
        QString modelo=ui->lineEditModeloVeiculo->text();
        QString placa=ui->lineEditPlacaVeiculo->text().toUpper();
        float kilometragem=ui->lineEditKmVeiculo->text().toFloat();
        float valorDeCompra=ui->lineEditValordeCompra->text().toFloat();
        bool situacao=situacaoDoVeiculo;
        projetoLocacao::Veiculo objVeiculo(marca,modelo,placa,kilometragem,valorDeCompra,situacao);
        agendaVeiculos.validaNovaPlaca(objVeiculo.getPlaca());
        agendaVeiculos.incluirVeiculo(objVeiculo);
        close();
        ui->lineEditMarcaVeiculo->clear();
        ui->lineEditModeloVeiculo->clear();
        ui->lineEditPlacaVeiculo->clear();
        ui->lineEditKmVeiculo->clear();
        ui->lineEditValordeCompra->clear();
        ui->checkBoxDisponivel->setChecked(true);
    }catch(QString erro){
        QMessageBox::information(this,"ERRO",erro);
    }
}






//----------------------------------------------------------------------------------------------------------
/*
 * Essa função serve apenas para pegar a situação do veiculo, por isso usei o atributo bool, ele vai receber o
 * estado da checkbox no caso se o veiculo esta disponivel ou nao e depois guardar no atributo do objeto da
 * classe veiculo, tentei de outra forma antes para nao precisar usar o atributo mas estava dando erro(a checkbox
 * sempre dava disponivel) entao usei essa forma e funcionou
 */
void MainWindowNovoVeiculo::on_checkBoxDisponivel_clicked(bool checked)
{
    situacaoDoVeiculo=checked;
}
