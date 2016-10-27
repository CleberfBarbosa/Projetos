#include "mainwindowDevolvendo.h"
#include "ui_mainwindowDevolvendo.h"

MainWindowDevolvendo::MainWindowDevolvendo(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindowDevolvendo),
    agendaDeVeiculo("AgendaDeVeiculos.csv"),//dando nome aos arquivos
    agendaDeLocacao("AgendaDeLocacao.csv")//dando nome aos arquivos
{
    ui->setupUi(this);
}

MainWindowDevolvendo::~MainWindowDevolvendo()
{
    delete ui;
}

void MainWindowDevolvendo::on_pushButtonDevolverLocacao_clicked()
{
    try
    {
        /*
         * aqui ira se fazer a devolução do veiculo, so se entra nessa tela se a placa digitada na
         * mainwindowVerificaPlacaDevolver existir e foi um veiculo locado
         */
        int kmFinal= ui->lineEditKmFinal->text().toInt();//pega o valor digitado no campo km final
        int kmInicial= objDevolver.getKilometragemFinal();//pega o valor do km inicial
        if(kmFinal<kmInicial)//quando se devolver a kilometragem inicial do veiculo nao
            //pode ser inferior a kilometragem inicial
            throw QString("A Km final não pode ser menor que a inicial");
        //vou pegar a placa do veiculo que será devolvido para obter o objeto veiculo referente a placa
        projetoLocacao::Veiculo objVeiculo=agendaDeVeiculo.consultarVeiculo(objDevolver.getPlacaDoVeiculo());
        //mudo a situação do veiculo para disponivel
        objVeiculo.setSituacao(true);
        //altero sua kilomentragem para a kilometragem de quando foi devolvido
        objVeiculo.setKilometragem(kmFinal);
        //mando alterar o objeto, passo o mesmo objeto nos dois campos pois a comparação é feita pela placa
        //para saber qual objeto vai ser excluido e a placa nao foi alterada
        //entao ele exclui o objeto com a situação e kilometragem antiga e grava o novo
        agendaDeVeiculo.alterarVeiculo(objVeiculo,objVeiculo);
        //entao eu chamo a função para devolver o objeto para que ele exclua o objeto que foi devolvido do arquivo
        agendaDeLocacao.devolver(objDevolver);
        close();//fecho a tela

    }catch(QString erro){
        QMessageBox::information(this,"ERRO",erro);
    }

}


void MainWindowDevolvendo::preencherCampos(projetoLocacao::Locacao obj)
{
    try
    {
        //preciso do objDevolver para que nao haja necessidade de pesquisa-lo novamente
        //e quando eu o usei de outra forma tive problemas os quais nao consegui resolver de outra forma
        objDevolver=obj;

        //preencho todos os campos e os deixo em off para que nao sejam alterados exceto o campo de km final
        //que será informado pelo usuario ao devolver o veiculo
        ui->lineEditPlacaLocacao->setText(obj.getPlacaDoVeiculo());
        ui->lineEditNomeClienteLocacao->setText(obj.getnomeDoCliente());
        ui->lineEditDataLocacao->setText(obj.getData());
        ui->lineEditValorLocacao->setText(QString::number(obj.getValorDaLocacao()));
        ui->lineEditKmInicial->setText(QString::number(obj.getKilometragemInicial()));
        ui->checkBoxSituacaoLocacao->setChecked(true);//uso isso aqui so por estetica
        ui->lineEditKmFinal->clear();
        ui->lineEditPlacaLocacao->setEnabled(false);
        ui->lineEditNomeClienteLocacao->setEnabled(false);
        ui->lineEditDataLocacao->setEnabled(false);
        ui->lineEditValorLocacao->setEnabled(false);
        ui->lineEditKmInicial->setEnabled(false);
        ui->checkBoxSituacaoLocacao->setEnabled(false);
    }catch(QString erro){
        QMessageBox::information(this,"ERRO",erro);
    }
}
