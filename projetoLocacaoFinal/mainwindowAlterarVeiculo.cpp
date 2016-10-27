#include "mainwindowAlterarVeiculo.h"
#include "ui_mainwindowAlterarVeiculo.h"


//----------------------------------------------------------------------------------------------------------
MainWindowAlterarVeiculo::MainWindowAlterarVeiculo(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindowAlterarVeiculo),
    situacaoDoVeiculo(true),//inicializando a situação do veiculo
    agendaVeiculos("AgendaDeVeiculos.csv")//dando nome ao arquivo que guardará os veiculos

{
    ui->setupUi(this);
}




//------------------------------------------------------------------------------------------------------------
MainWindowAlterarVeiculo::~MainWindowAlterarVeiculo()
{
    delete ui;
}




//--------------------------------------------------------------------------------------------------------------
/*
 * Quando o usuario clicar em salvar será seguido o mesmo procedimento do metodo para incluir um novo veiculo
 * com a diferença que o objeto que foi pesquisado para ser alterado e foi armazenado no objetoParaExcluir
 * será excluido e depois pego o novo objeto que foi criado e incluo ele
 */
void MainWindowAlterarVeiculo::on_pushButtonSalvar_clicked()
{
    try{
        QString marca=ui->lineEditMarca->text();
        QString modelo=ui->lineEditModelo->text();
        QString placa=ui->lineEditPlaca->text().toUpper();
        float kilometragem=ui->lineEditKilometragem->text().toFloat();
        float valorDeCompra=ui->lineEditValorDeCompra->text().toFloat();
        bool situacao=situacaoDoVeiculo;

        projetoLocacao::Veiculo objVeiculo(marca,modelo,placa,kilometragem,valorDeCompra,situacao);
        agendaVeiculos.excluirVeiculo(objetoParaExcluir);
        agendaVeiculos.validaNovaPlaca(placa);
        agendaVeiculos.incluirVeiculo(objVeiculo);
        /*Não pude usar o metodo alterar por que eu preciso validar a placa caso ela seja alterada
          se eu usar o alterar nao seria possivel, por que ele iria verificar se existe alguma placa
            igual a digitada e como eu ainda nao havia excluido o objeto entao caso ele nao altere a placa
            sempre iria dar que a placa digitada ja existe*/

        ui->lineEditMarca->clear();
        ui->lineEditModelo->clear();
        ui->lineEditPlaca->clear();
        ui->lineEditKilometragem->clear();
        ui->lineEditValorDeCompra->clear();
        ui->checkBoxSituacao->setChecked(true);
        close();//para fechar a janela
    }catch(QString erro){
        QMessageBox::information(this,"ERRO",erro);
    }

}





//----------------------------------------------------------------------------------------------------------------

/*
 * Essa função será chamado dentro mainwindowVeiculo apenas caso a placa corresponda a algum objeto existente
 * ela so serve para preencherr todos os campos com os dados a serem modificados para facilitar para o usuario
 * caso ele so queira alterar um campo, assim ele nao precisara preencher tudo.
 */
void MainWindowAlterarVeiculo::preencherCampos(projetoLocacao::Veiculo objetoPesquisado)
{
    try
    {
        objetoParaExcluir=objetoPesquisado;
        /*Usei esse objetoParaExcluir pq o objetoPesquisado que é passado
        *por parametro ira desaparecer no fecha chaves, entao como eu criei um objeto (objetoParaExcluir)
        *o objeto ao qual a placa foi digitada na lineEdit para pesquisar a placa ficara guardado nele,
        *foi a melhor forma que encontrei, pq vou precisar excluir esse objeto que foi pesquisado,
        *porem eu so quero que ele seja excluido quando o usuario clicar em salvar
        *essa foi a melhor forma que encontrei para nao perder o objeto que foi pesquisado para ser alterado
        *inicialmente
        *
        *
        * daqui para baixo so estou preenchendo os campos para o usuario alterar

        */
        ui->lineEditMarca->setText(objetoPesquisado.getMarca());
        ui->lineEditModelo->setText(objetoPesquisado.getModelo());
        ui->lineEditPlaca->setText(objetoPesquisado.getPlaca());
        ui->lineEditKilometragem->setText(QString::number(objetoPesquisado.getKilometragem()));
        ui->lineEditValorDeCompra->setText(QString::number(objetoPesquisado.getValorDeCompra()));
        ui->checkBoxSituacao->setChecked(objetoPesquisado.getSituacao());
    }catch(QString erro){
        QMessageBox::information(this,"ERRO",erro);
    }
}







//-------------------------------------------------------------------------------------------------------------
/*
 * Essa função serve apenas para pegar a situação do veiculo, por isso usei o atributo bool, ele vai receber o
 * estado da checkbox no caso se o veiculo esta disponivel ou nao e depois guardar no atributo do objeto da
 * classe veiculo, tentei de outra forma antes para nao precisar usar o atributo mas estava dando erro(a checkbox
 * sempre dava disponivel) entao usei essa forma e funcionou
 */
void MainWindowAlterarVeiculo::on_checkBoxSituacao_clicked(bool checked)
{
    situacaoDoVeiculo=checked;
}
