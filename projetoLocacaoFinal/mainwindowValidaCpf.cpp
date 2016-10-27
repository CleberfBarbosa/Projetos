#include "mainwindowValidaCpf.h"
#include "ui_mainwindowValidaCpf.h"


//ESSA FUNÇÃO SOMENTE VERIFICA SE O CPF EXISTE, ELA NAO FAZ VALIDAÇÃO DE SE ELE É REAL


MainWindowValidaCpf::MainWindowValidaCpf(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindowValidaCpf),
    arquivoDeClientes("arquivoDeClientes.csv")
{
    ui->setupUi(this);
}

MainWindowValidaCpf::~MainWindowValidaCpf()
{
    delete ui;
}

void MainWindowValidaCpf::on_pushButtonOk_clicked()
{
    try
    {
        //aqui vou verificar se o cpf digitado existe e se existir chamar a função para preencher dados a fim
        //de locar um veiculo
        bool existe=false;
        //crio um ponteiro para um fila e chamo a função do cliente persistencia e faço meu ponteiro apontar
        //para a fila que foi devolvida por essa funçaõ
        std::queue<projetoLocacao::Cliente>* filaDeClientes;
        filaDeClientes=arquivoDeClientes.listagemDeClientes();
        projetoLocacao::Cliente objeto;
        QString Cpf = ui->lineEdit->text();
        while(!filaDeClientes->empty())//enquanto houver elemento na fila ele repete
        {
            objeto=filaDeClientes->front();//pega o elemento da fila
            if(objeto.getCPF()==Cpf)//compara se o cpf que foi digitado no campo
                //é o cpf do objeto que foi pego da fila
            {
                //caso seja minha variavel bool fica true, chamo a função da mainwindowLocando para
                //passar o nome do dono do cpf para ela e dou um break no while
                existe=true;
                locandoVeiculo.pegaCliente(objeto.getNome());
                break;
            }
            filaDeClientes->pop();//retira o elemento da lista
        }
        delete filaDeClientes;//deleto a fila
        if(!existe)throw QString ("Cpf não cadastrado");
        locandoVeiculo.show();//chamo a mainwindow para locar veiculo
        close();//fecho essa mainwindow na qual estou
        ui->lineEdit->clear();//limpo a lineedit
    }catch(QString erro){
    QMessageBox::information(this,"ERRO",erro);
}
    catch(...)
    {
        throw QString ("Cpf não cadastrado");
    }
}
