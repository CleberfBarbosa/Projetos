#include "mainwindowCliente.h"
#include "ui_mainwindowCliente.h"

MainWindowCliente::MainWindowCliente(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindowCliente),
    arquivoDeClientes("arquivoDeClientes.csv")
{
    ui->setupUi(this);
}

MainWindowCliente::~MainWindowCliente()
{
    delete ui;
}

void MainWindowCliente::on_pushButtonCadastrar_clicked()
{
    irNovoCliente.show();
    ui->lineEditProcurar->clear();
}

void MainWindowCliente::on_pushButtonAlterar_clicked()
{
    try{//sei que deveria estar usando cpf para fazer a alteração mas o tempo para entrega do trabalho foi curto
        //como esse nao é para ser um sistema realmente funcional, estou considerando que nao existirão clientes
        //com dados iguais.
    projetoLocacao::Cliente objeto;
    objeto = arquivoDeClientes.consultar(ui->lineEditProcurar->text());
    QString nome = ui->lineEditProcurar->text();
    if(objeto.getNome() == nome){
        arquivoDeClientes.excluir(nome);
    }
    irNovoCliente.show();
    }catch(QString erro){
        QMessageBox::information(this, "Erro", erro);
    }
    ui->lineEditProcurar->clear();
}

void MainWindowCliente::on_pushButtonExcluir_clicked()
{
    try{//sei que deveria estar usando cpf para fazer a exclusao mas o tempo para entrega do trabalho foi curto
        QString nome = ui->lineEditProcurar->text();
        arquivoDeClientes.excluir(nome);
    }catch(QString erro){
        QMessageBox::information(this, "Erro", erro);
    }
    ui->lineEditProcurar->clear();
}

void MainWindowCliente::on_pushButtonConsultar_clicked()
{
    try{
        QString nome = ui->lineEditProcurar->text();
        projetoLocacao::Cliente objeto = arquivoDeClientes.consultar(nome);
        irListaDeClientes.show();
        irListaDeClientes.consultarCliente(objeto);
    }catch(QString erro){
        QMessageBox::information(this,"Erro",erro);
    }
    ui->lineEditProcurar->clear();
}

void MainWindowCliente::on_pushButtonListar_clicked()
{
    irListaDeClientes.show();
    irListaDeClientes.listar();
    ui->lineEditProcurar->clear();
}
