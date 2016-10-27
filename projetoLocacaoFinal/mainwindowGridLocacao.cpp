#include "mainwindowGridLocacao.h"
#include "ui_mainwindowGridLocacao.h"
#include <stack>
#include <QMessageBox>
MainWindowGridLocacao::MainWindowGridLocacao(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindowGridLocacao),
    agendaDeLocacao("AgendaDeLocacao.csv")
{
    ui->setupUi(this);
}

MainWindowGridLocacao::~MainWindowGridLocacao()
{
    delete ui;
}

void MainWindowGridLocacao::mostrarGrid()
{
    try
    {
        //essa função será chamada dentro da mainwindowLocacao

        //declaro um ponteiro para uma pilha do tipo locação recebendo uma pilha da função listagem
        std::stack<projetoLocacao::Locacao>* pilha=agendaDeLocacao.listagemDeLocacao();

        ui->tableWidgeGridLocacao->setRowCount(0);//estou dando um clear na lista
        //pois sem isso sempre que eu chamar a função de listagem ele vai listar os objetos novamente
        // sem apagar os que tinham sido listados antes

        while(!pilha->empty())//enquanto ouver elementos na pilha ele repete
        {
            projetoLocacao::Locacao objeto=pilha->top();//pego o objeto da pilha

            QTableWidgetItem *item1=new QTableWidgetItem(objeto.getPlacaDoVeiculo());
            QTableWidgetItem *item2=new QTableWidgetItem(objeto.getnomeDoCliente());
            QTableWidgetItem *item3=new QTableWidgetItem(objeto.getData());
            QTableWidgetItem *item4=new QTableWidgetItem(QString::number(objeto.getValorDaLocacao()));
            QTableWidgetItem *item5=new QTableWidgetItem(QString::number(objeto.getKilometragemInicial()));
            QTableWidgetItem *item6= new QTableWidgetItem(QString::number(objeto.getKilometragemFinal()));




            int linha=ui->tableWidgeGridLocacao->rowCount();

            ui->tableWidgeGridLocacao->insertRow(linha);
            ui->tableWidgeGridLocacao->setItem(linha,0,item1);
            ui->tableWidgeGridLocacao->setItem(linha,1,item2);
            ui->tableWidgeGridLocacao->setItem(linha,2,item3);
            ui->tableWidgeGridLocacao->setItem(linha,3,item4);
            ui->tableWidgeGridLocacao->setItem(linha,4,item5);
            ui->tableWidgeGridLocacao->setItem(linha,5,item6);
            pilha->pop();//retiro o objeto da pilha
        }
    }catch(QString erro)
    {
        QMessageBox::information(this, "ERRO",erro);
    }
}
