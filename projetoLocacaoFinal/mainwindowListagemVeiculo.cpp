#include "mainwindowListagemVeiculo.h"
#include "ui_mainwindowListagemVeiculo.h"
#include <QMessageBox>




//-------------------------------------------------------------------------------------------------------------
MainWindowListagemVeiculo::MainWindowListagemVeiculo(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindowListagemVeiculo),
    agendaVeiculos("AgendaDeVeiculos.csv")
{
    ui->setupUi(this);
}



//-------------------------------------------------------------------------------------------------------------
MainWindowListagemVeiculo::~MainWindowListagemVeiculo()
{
    delete ui;
}



//-------------------------------------------------------------------------------------------------------------
/*
 * essa função de listagem será chamada na mainwindowVeiculo e nao passará nada como paramentro
 * quando ela é chamada ela mesma ira chamar a função de listagem dos veiculos da classe VeiculoPersistecia,
 * essa funçao ira me retornar o endereço de memoria de uma lista de objetos do tipo Veiculo, eu crio
 * um ponteiro lista do mesmo tipo
 * para receber essa primeira lista, e aparti desse segundo ponteiro vou preencher minha grid de veiculos
 */
void MainWindowListagemVeiculo::listagemDeVeiculos()
{
    try
    {

        std::list<projetoLocacao::Veiculo>* lista=agendaVeiculos.listagemDeVeiculos();
        ui->tableWidgetGridVeiculos->setRowCount(0);//estou dando um clear na lista
        //pois sem isso sempre que eu chamar a função de listagem ele vai listar os objetos novamente
        // sem apagar os que tinham sido listados antes
        while(!lista->empty())//enquanto ouver elementos na lista ele repete
        {
            projetoLocacao::Veiculo objeto=lista->front();//pego o objeto da lista na primeira
            //posição mas nao o removo e guardo em um outro objeto


            //mostrar o contato na grid
            QTableWidgetItem *item1=new QTableWidgetItem(objeto.getMarca());
            QTableWidgetItem *item2=new QTableWidgetItem(objeto.getModelo());
            QTableWidgetItem *item3=new QTableWidgetItem(objeto.getPlaca());
            QTableWidgetItem *item4=new QTableWidgetItem(QString::number(objeto.getKilometragem()));
            QTableWidgetItem *item5=new QTableWidgetItem(QString::number(objeto.getValorDeCompra()));
            QTableWidgetItem *item6;
            if(objeto.getSituacao())
            item6=new QTableWidgetItem("Disponivel");
            else
               item6=new QTableWidgetItem("Indisponivel");





            int linha=ui->tableWidgetGridVeiculos->rowCount();

            ui->tableWidgetGridVeiculos->insertRow(linha);
            ui->tableWidgetGridVeiculos->setItem(linha,0,item1);
            ui->tableWidgetGridVeiculos->setItem(linha,1,item2);
            ui->tableWidgetGridVeiculos->setItem(linha,2,item3);
            ui->tableWidgetGridVeiculos->setItem(linha,3,item4);
            ui->tableWidgetGridVeiculos->setItem(linha,4,item5);
            ui->tableWidgetGridVeiculos->setItem(linha,5,item6);
            lista->pop_front();// retiro o primeiro elemento da lista, o qual acabou de ser impresso
            // na tablegrid
        }
        delete lista;
    }catch(QString erro){
        QMessageBox::information(this, "ERRO",erro);
}
}
