#include "mainwindowVeiculo.h"
#include "ui_mainwindowVeiculo.h"

//-----------------------------------------------------------------------------------------------------


MainWindowVeiculo::MainWindowVeiculo(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindowVeiculo),
    agendaVeiculos("AgendaDeVeiculos.csv")
{
    ui->setupUi(this);
}

//-----------------------------------------------------------------------------------------------------


MainWindowVeiculo::~MainWindowVeiculo()
{
    delete ui;
}

//-----------------------------------------------------------------------------------------------------
/*
 * Apenas ira abrir a janela de novo veiculo
 */
void MainWindowVeiculo::on_pushButtonNovo_clicked()
{
    irNovoVeiculo.show();
}



//-----------------------------------------------------------------------------------------------------
/*
 * Primeiro irei pegar a placa digitada e pesquisar para ver se existe algum objeto com essa placa
 * caso exista abro a janela de alteração de veiculo e chamo a função para preencher todos os campos
 * passando o objeto que foi encontrado como parametro
 */
void MainWindowVeiculo::on_pushButtonAlterar_clicked()
{
    try
    {
        projetoLocacao::Veiculo objeto;
        QString placaPesquisada=ui->lineEditPlacaPesquisada->text().toUpper();
        objeto=agendaVeiculos.consultarVeiculo(placaPesquisada);
        irAlterarVeiculo.show();
        irAlterarVeiculo.preencherCampos(objeto);
    }catch(QString erro){
        QMessageBox::information(this, "ERRO",erro);
}

}



//-----------------------------------------------------------------------------------------------------
/*
 * Primeiro eu pego a placa que foi digitada e a procuro se existe algum objeto referente a ela
 * caso exista a função de consultar me retorna um objeto veiculo
 * o qual eu guardo em um objeto do tipo veiculo e chamo a função de excluir veiculo do
 * veiculo persistencia e limpo o campo que a placa foi digitada apenas para mostrar que o
 * objeto foi excluido, nao retorno nenhuma mensagem ao usuario para dizer que o objeto foi excluido
 * apenas se houver algum problema
 */
void MainWindowVeiculo::on_pushButtonExcluir_clicked()
{
    try
    {
        QString placaParaExcluir;
        placaParaExcluir=ui->lineEditPlacaPesquisada->text().toUpper();
        projetoLocacao::Veiculo objParaExcluir=agendaVeiculos.consultarVeiculo(placaParaExcluir);
        ui->lineEditPlacaPesquisada->clear();
        agendaVeiculos.excluirVeiculo(objParaExcluir);
}catch(QString erro){
    QMessageBox::information(this, "ERRO",erro);
}
}


//-----------------------------------------------------------------------------------------------------


void MainWindowVeiculo::on_pushButtonConsultar_clicked()
{
    try{
        QString placaPesquisada=ui->lineEditPlacaPesquisada->text().toUpper();
        projetoLocacao::Veiculo obj;
        obj=agendaVeiculos.consultarVeiculo(placaPesquisada);
        irConsultarVeiculo.show();
        irConsultarVeiculo.mostrarVeiculoPesquisado(obj);

    }catch(QString erro){
        QMessageBox::information(this, "ERRO",erro);}

}


//-----------------------------------------------------------------------------------------------------
/*
 * Primeiramente ira abrir a janela de listagem de veiculos com a tablegrid e chamo a função listagemDeVeiculos
 * dessa mainWindow
 */
void MainWindowVeiculo::on_pushButtonListar_clicked()
{
    try{
        irListagemVeiculo.show();
        irListagemVeiculo.listagemDeVeiculos();
    }catch(QString erro){
        QMessageBox::information(this, "ERRO",erro);
}
}


//-----------------------------------------------------------------------------------------------------

