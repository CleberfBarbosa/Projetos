#include "mainwindowLocacao.h"
#include "ui_mainwindowLocacao.h"

MainWindowLocacao::MainWindowLocacao(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindowLocacao)
{
    ui->setupUi(this);
}

MainWindowLocacao::~MainWindowLocacao()
{
    delete ui;
}

void MainWindowLocacao::on_pushButtonLocar_clicked()
{
    validaCpf.show();
}

void MainWindowLocacao::on_pushButtonDevolver_clicked()
{
    validaPlaca.show();
}

void MainWindowLocacao::on_pushButtonConsultarLocacao_clicked()
{
    consultaPlaca.show();
}

void MainWindowLocacao::on_pushButtonListarLocacao_clicked()
{
    irGridLocacao.show();//abre a mainwindow
    irGridLocacao.mostrarGrid();//chama a função para preencher a grid
}
