#include "mainwindowGRIDCliente.h"
#include "ui_mainwindowGRIDCliente.h"

MainWindowGRIDCliente::MainWindowGRIDCliente(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindowGRIDCliente),
    arquivoDeClientes("arquivoDeClientes.csv")
{
    ui->setupUi(this);
}

MainWindowGRIDCliente::~MainWindowGRIDCliente()
{
    delete ui;
}

void MainWindowGRIDCliente::listar(){
    ui->tableWidgetGRIDCliente->clearContents(); //Remove todos os itens dos cabeçalhos
    ui->tableWidgetGRIDCliente->setRowCount(0); //Clear na fila
    try{
        std::queue<projetoLocacao::Cliente>* fila = 0;
        fila = arquivoDeClientes.listagemDeClientes();

        while(!fila->empty()){ //Enquanto a fila nao estiver vazia
            projetoLocacao::Cliente objeto = fila->front(); //pega o primeiro elemento da fila
            QTableWidgetItem *item1 = new QTableWidgetItem(objeto.getNome());
            QTableWidgetItem *item2 = new QTableWidgetItem(objeto.getCPF());
            QTableWidgetItem *item3 = new QTableWidgetItem(objeto.getCarteiraDeHabilitacao());
            QTableWidgetItem *item4 = new QTableWidgetItem(QString::number(objeto.getDdd()));
            QTableWidgetItem *item5 = new QTableWidgetItem(QString::number(objeto.getTelefone()));
            QTableWidgetItem *item6 = new QTableWidgetItem(objeto.getEmail());
            int linha = ui->tableWidgetGRIDCliente->rowCount(); //Retorna uma lista de todas as faixas selecionadas.
            ui->tableWidgetGRIDCliente->insertRow(linha);
            ui->tableWidgetGRIDCliente->setItem(linha, 0, item1);
            ui->tableWidgetGRIDCliente->setItem(linha, 1, item2);
            ui->tableWidgetGRIDCliente->setItem(linha, 2, item3);
            ui->tableWidgetGRIDCliente->setItem(linha, 3, item4);
            ui->tableWidgetGRIDCliente->setItem(linha, 4, item5);
            ui->tableWidgetGRIDCliente->setItem(linha, 5, item6);
            fila->pop();
            }
        delete fila;
    }catch(QString erro){
        QMessageBox::information(this, "Erro", erro);
    }
}

void MainWindowGRIDCliente::consultarCliente(projetoLocacao::Cliente objeto){
    ui->tableWidgetGRIDCliente->clearContents(); //Remove todos os itens dos cabeçalhos
    ui->tableWidgetGRIDCliente->setRowCount(0); //Clear na fila
    try{
        QTableWidgetItem *item1 = new QTableWidgetItem(objeto.getNome());
        QTableWidgetItem *item2 = new QTableWidgetItem(objeto.getCPF());
        QTableWidgetItem *item3 = new QTableWidgetItem(objeto.getCarteiraDeHabilitacao());
        QTableWidgetItem *item4 = new QTableWidgetItem(QString::number(objeto.getDdd()));
        QTableWidgetItem *item5 = new QTableWidgetItem(QString::number(objeto.getTelefone()));
        QTableWidgetItem *item6 = new QTableWidgetItem(objeto.getEmail());
        int linha = ui->tableWidgetGRIDCliente->rowCount();
        ui->tableWidgetGRIDCliente->insertRow(linha);
        ui->tableWidgetGRIDCliente->setItem(linha, 0, item1);
        ui->tableWidgetGRIDCliente->setItem(linha, 1, item2);
        ui->tableWidgetGRIDCliente->setItem(linha, 2, item3);
        ui->tableWidgetGRIDCliente->setItem(linha, 3, item4);
        ui->tableWidgetGRIDCliente->setItem(linha, 4, item5);
        ui->tableWidgetGRIDCliente->setItem(linha, 5, item6);
    }catch(QString erro){
        QMessageBox::information(this, "Erro", erro);
    }
}
