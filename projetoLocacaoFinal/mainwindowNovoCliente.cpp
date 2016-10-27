#include "mainwindowNovoCliente.h"
#include "ui_mainwindowNovoCliente.h"

MainWindowNovoCliente::MainWindowNovoCliente(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindowNovoCliente),
    arquivoDeClientes("arquivoDeClientes.csv")
{
    ui->setupUi(this);
}

MainWindowNovoCliente::~MainWindowNovoCliente()
{
    delete ui;
}

void MainWindowNovoCliente::on_pushButtonSalvar_clicked()
{
    try{
        QString nome = ui->lineEditNome->text();
        QString CPF = ui->lineEditCPF->text();
        QString carteiraDeHabilitacao = ui->lineEditCarteiraDeHabilitacao->text();
        int ddd = ui->lineEditDdd->text().toInt();
        long telefone = ui->lineEditTelefone->text().toInt();
        QString email = ui->lineEditEmail->text();

        projetoLocacao::Cliente obj(nome, CPF, carteiraDeHabilitacao, ddd, telefone, email);
        arquivoDeClientes.incluir(obj);
    }catch(QString erro){
        QMessageBox::information(this, "Erro", erro);
    }
    ui->lineEditNome->clear();
    ui->lineEditCPF->clear();
    ui->lineEditCarteiraDeHabilitacao->clear();
    ui->lineEditDdd->clear();
    ui->lineEditTelefone->clear();
    ui->lineEditEmail->clear();
    close();
}

void MainWindowNovoCliente::on_pushButtonCancelar_clicked()
{
    close();
}
