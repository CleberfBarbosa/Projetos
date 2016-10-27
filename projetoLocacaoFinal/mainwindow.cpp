#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButtonVeiculo_clicked()
{
    irVeiculo.show();
}

void MainWindow::on_pushButtonCliente_clicked()
{
    irCliente.show();
}

void MainWindow::on_pushButtonLocacao_clicked()
{
    irLocacao.show();
}
