#include "mainwindowConsultaLocacao.h"
#include "ui_mainwindowConsultaLocacao.h"

MainWindowConsultaLocacao::MainWindowConsultaLocacao(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindowConsultaLocacao)
{
    ui->setupUi(this);
}

MainWindowConsultaLocacao::~MainWindowConsultaLocacao()
{
    delete ui;
}

void MainWindowConsultaLocacao::preencheDadosVeiculo(projetoLocacao::Locacao objLocacao)
{
    try
    {
        //ele vai preencher todos os campos que serão exibidos e deixar todos em off
        //essa função será chamada apenas se a placa digitada para pesquisa exista e esteja realmente alugada
        //essa função é chamada dentro da mainwindowConsultaPlacaLocacao
        ui->lineEditPlacaLocacao->setText(objLocacao.getPlacaDoVeiculo());
        ui->lineEditNomeClienteLocacao->setText(objLocacao.getnomeDoCliente());
        ui->lineEditDataLocacao->setText(objLocacao.getData());
        ui->lineEditKmInicial->setText(QString::number(objLocacao.getKilometragemInicial()));
        ui->lineEditValorLocacao->setText(QString::number(objLocacao.getValorDaLocacao()));
        ui->checkBoxSituacaoLocacao->setChecked(true);
        ui->lineEditPlacaLocacao->setEnabled(false);
        ui->lineEditNomeClienteLocacao->setEnabled(false);
        ui->lineEditDataLocacao->setEnabled(false);
        ui->lineEditKmInicial->setEnabled(false);
        ui->lineEditValorLocacao->setEnabled(false);
        ui->checkBoxSituacaoLocacao->setEnabled(false);
    }catch(QString erro){
        QMessageBox::information(this,"ERRO",erro);
    }
}
