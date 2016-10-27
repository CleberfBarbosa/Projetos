#include "mainwindowConsultaPlacaLocacao.h"
#include "ui_mainwindowConsultaPlacaLocacao.h"

MainWindowConsultaPlacaLocacao::MainWindowConsultaPlacaLocacao(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindowConsultaPlacaLocacao),
    agendaDeLocacao("AgendaDeLocacao.csv")
{
    ui->setupUi(this);
}

MainWindowConsultaPlacaLocacao::~MainWindowConsultaPlacaLocacao()
{
    delete ui;
}

void MainWindowConsultaPlacaLocacao::on_pushButtonOk_clicked()
{
    try
    {
        //irá consultar a placa digitada e so deixará abrir a janela se a placa digitada existir e estiver locada
        QString placaPesquisada = ui->lineEditPlacaConsultar->text().toUpper();
        projetoLocacao::Locacao objeto=agendaDeLocacao.consultarLocacao(placaPesquisada);//verifica se a placa
        //consta nos arquivos

        //chama a função para preencher os dados de todos os campos
        //apenas se o elemento existir
        consultaLocacao.preencheDadosVeiculo(objeto);
        consultaLocacao.show();
        close();
        ui->lineEditPlacaConsultar->clear();//limpa a lineedit para que qnd voltar nessa janela ela esteja limpa
    }catch(QString erro){
        QMessageBox::information(this,"ERRO",erro);
    }
}
