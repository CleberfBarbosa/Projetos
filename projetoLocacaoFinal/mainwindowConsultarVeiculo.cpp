#include "mainwindowConsultarVeiculo.h"
#include "ui_mainwindowConsultarVeiculo.h"



//--------------------------------------------------------------------------------------------------------------
MainWindowConsultarVeiculo::MainWindowConsultarVeiculo(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindowConsultarVeiculo)

{
    ui->setupUi(this);
}



//--------------------------------------------------------------------------------------------------------------
MainWindowConsultarVeiculo::~MainWindowConsultarVeiculo()
{
    delete ui;
}



//--------------------------------------------------------------------------------------------------------------
/*
 * essa função será chamada na mainwindowVeiculo passando um objeto por paramento, objeto esse que foi o
 * pesquisado pelo usuario, essa tela so será aberta se o objeto existir
 * nao possui nenhum botao apenas preenche todos os campos e os deixa em off, nao altera tambem o
 * objeto de nenhuma forma
 */
void MainWindowConsultarVeiculo::mostrarVeiculoPesquisado(projetoLocacao::Veiculo objetoPesquisado)
{
    try
    {
        ui->lineEditMarca->setText(objetoPesquisado.getMarca());
        ui->lineEditModelo->setText(objetoPesquisado.getModelo());
        ui->lineEditPlaca->setText(objetoPesquisado.getPlaca());
        ui->lineEditKilometragem->setText(QString::number(objetoPesquisado.getKilometragem()));
        ui->lineEditValorDeCompra->setText(QString::number(objetoPesquisado.getValorDeCompra()));
        ui->checkBoxSituacao->setChecked(objetoPesquisado.getSituacao());
        ui->lineEditMarca->setEnabled(false);
        ui->lineEditModelo->setEnabled(false);
        ui->lineEditPlaca->setEnabled(false);
        ui->lineEditKilometragem->setEnabled(false);
        ui->lineEditValorDeCompra->setEnabled(false);
        ui->checkBoxSituacao->setEnabled(false);
    }catch(QString erro){
        QMessageBox::information(this,"ERRO",erro);
    }
}
