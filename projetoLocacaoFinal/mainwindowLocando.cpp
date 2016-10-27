#include "mainwindowLocando.h"
#include "ui_mainwindowLocando.h"

MainWindowLocando::MainWindowLocando(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindowLocando),
    agendaDeVeiculo("AgendaDeVeiculos.csv"),
    agendaDeLocacao("AgendaDeLocacao.csv")
{
    ui->setupUi(this);
}

MainWindowLocando::~MainWindowLocando()
{
    delete ui;
}

void MainWindowLocando::on_pushButtonSalvarLocacao_clicked()
{
    try
    {
        //aqui vamos alugar um veiculo
        //antes foi verificado o cpf para o qual o veiculo ira ser alugado e para que o nome nao seja alterado
        //usamos uma função para pega-lo
        QString placaDoVeiculo=ui->lineEditPlacaLocacao->text().toUpper();
        QString nomeDoCliente = nomeDado;//nome referente ao cpf digitado
        QString data = ui->lineEditDataLocacao->text();
        float valorDaLocacao = ui->lineEditValorLocacao->text().toFloat();
        int kilometragemInicial=ui->lineEditKmInicial->text().toInt();

        //como eu nao tenho uma kilometragem final eu inicializo ela com a kilometragem inicial
        //e a situação eu sempre coloco como true pois se o objeto esta aqui e no arquivo de locação
        //isso significa que ele sempre estará locado
        projetoLocacao::Locacao objLocacao(placaDoVeiculo,nomeDoCliente,data,valorDaLocacao,
                                           kilometragemInicial,kilometragemInicial,true);
        //verifico se a placa digitada existe pois nao posso alugar um carro que nao esteja cadastrado
        projetoLocacao::Veiculo objVeiculo = agendaDeVeiculo.consultarVeiculo(placaDoVeiculo);
        //verifico a situação do veiculo, se ele nao estiver disponivel eu nao posso aluga-lo
        if(!(objVeiculo.getSituacao()))throw QString ("Veiculo não está disponivel");
        else{
            //se o objeto estiver disponivel eu mudo sua situação para indisponivel pois estou alugando ele
            objVeiculo.setSituacao(false);
            agendaDeVeiculo.alterarVeiculo(objVeiculo,objVeiculo);//altero ele, o padrao para pesquisa é a placa
            //como a placa nao será alterada posso usar o msm objeto para os dois parametros
            agendaDeLocacao.locar(objLocacao);//chamo o metodo de locar
            close();
        }
    }catch(QString erro){
        QMessageBox::information(this,"ERRO",erro);
    }

}


void MainWindowLocando::pegaCliente(QString nome)
{
    //essa função é chamada na mainwindowValidaCpf e so vem pra ca caso o cpf digitado seja de algum
    //cliente cadastrado, ele recebe o nome referente ao cpf digitado
    //aqui ele vai dar um clear em todos os campos para que nao tenha o risco de haver algo nas linedit
    ui->lineEditPlacaLocacao->clear();
    ui->lineEditNomeClienteLocacao->clear();
    ui->lineEditDataLocacao->clear();
    ui->lineEditKmInicial->clear();
    ui->lineEditValorLocacao->clear();
    //vou usar esse nome dado na função acima para preencher o objeto a ser locado
    nomeDado=nome;
    //preencho a lineedit do nome com o nome referente ao cpf digitado e deixo a lineedit em off
    ui->lineEditNomeClienteLocacao->setText(nomeDado);
    ui->lineEditNomeClienteLocacao->setEnabled(false);

    //criar tablegrid com todos os carros


    std::list<projetoLocacao::Veiculo>* lista=agendaDeVeiculo.listagemDeVeiculos();
    ui->tableWidgetGridVeiculos->setRowCount(0);//estou dando um clear na lista
    //pois sem isso sempre que eu chamar a função de listagem ele vai listar os objetos novamente
    // sem apagar os que tinham sido listados antes
    while(!lista->empty())//enquanto ouver elementos na lista ele repete
    {
        projetoLocacao::Veiculo objeto=lista->front();//pego o objeto da lista na primeira
        //posição mas nao o removo e guardo em um outro objeto


        //if(objeto.getSituacao()){

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
        //}
    }
    delete lista;
}
