#include "mainwindowVerificaPlacaDevolver.h"
#include "ui_mainwindowVerificaPlacaDevolver.h"

MainWindowVerificaPlacaDevolver::MainWindowVerificaPlacaDevolver(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindowVerificaPlacaDevolver),
    agendaDeLocacao("AgendaDeLocacao.csv")
{
    ui->setupUi(this);
}

MainWindowVerificaPlacaDevolver::~MainWindowVerificaPlacaDevolver()
{
    delete ui;
}

void MainWindowVerificaPlacaDevolver::on_pushButtonOk_clicked()
{
    try
    {
        //aqui vai verificar se a placa existe e se ela existe se esta realmente locada
        //caso sim ele chama a mainwindowDevolvendo, chamando a função que preenche o campos necessarios

        //verifica se a placa digitada existe
        projetoLocacao::Locacao obj = agendaDeLocacao.consultarLocacao(ui->lineEditPlacaDevolver->text().toUpper());
        //chama a função preencherCampos da mainwindowDevolvendo que vai preencher todos os campos necessarios
        //passa o objeto caso ele exista como parametro
        devolverVeiculo.preencherCampos(obj);
        devolverVeiculo.show();//abre a mainwindowDevolvendo
        close();//fecha a mainWindow na qual estamos
        ui->lineEditPlacaDevolver->clear();//limpa a lineedit
    }catch(QString erro){
        QMessageBox::information(this,"ERRO",erro);
    }
}
