#include "Locacao.h"


namespace projetoLocacao
{



Locacao::Locacao(QString placaDoVeiculo, QString nomeDoCliente, QString data, float valorDaLocacao,
        int kilometragemInicial, int kilometragemFinal, bool situacao):
    placaDoVeiculo(placaDoVeiculo),
    nomeDoCliente(nomeDoCliente),
    data(data),
    valorDaLocacao(valorDaLocacao),
    kilometragemInicial(kilometragemInicial),
    kilometragemFinal(kilometragemFinal),
    situacao(situacao)
{

}


//----------------------------------------------------------------------------------------------------------------
/*
 * O metodo materializar pega uma QString que é referente a um linha do arquivo, dividi tudo que esta escrito
 * usando o ';' como parametro e cria uma lista de QStrings, então cada campo que está entre';'
 * da QString fica ocupando uma posição da lista, apartir dai usamos a lista para adicionar valores a um objeto
 * assim criamos um objeto apartir da QString do arquivo .
 */
void Locacao::materializarLocacao(QString str)
{
    try
    {
        QStringList listStr = str.split(';');
        if(listStr.length()!=7)//throw QString ("ERRO AO MATERIALIZAR");

        this->setPlacaDoVeiculo(listStr[0]);
        this->setnomeDoCliente(listStr[1]);
        this->setData(listStr[2]);
        this->setValorDaLocacao(listStr[3].toFloat());
        this->setKilometragemInicial(listStr[4].toInt());
        this->setKilometragemFinal(listStr[5].toInt());
        if(listStr[6]=="Locado")
        this->setSituacao(true);//Quando o veiculo está locado significa que a checkbox
        //está marcada e entao o veiculo nao esta disponivel
        else this->setSituacao(false);

/*

        QStringList strList = str.split(';');
        if(strList.length()!=7) throw;
        placaDoVeiculo = strList[0];
        nomeDoCliente = strList[1];
        data = strList[2];
        valorDaLocacao = strList[3].toFloat();
        kilometragemInicial = strList[4].toInt();
        kilometragemFinal = strList[5].toInt();
        if(strList[6]=="Locado")
       situacao=true;//Quando o veiculo está locado significa que a checkbox
        //está marcada e entao o veiculo nao esta disponivel
        else situacao=false;

        */


    }catch(...){
        throw QString ("Erro na Classe Materializar da Locação");
    }
}



//----------------------------------------------------------------------------------------------------------------
/*
 * O metodo desmaterializar pega o objeto, vai pegando todas as sua informações
 * e concatenando numa QString separando as infos por um ';' ele é chamado sempre que se adicionar um novo
 * veiculo.
 */
QString Locacao::desmaterializarLocacao()const
{
    try
    {
        QString saida;
        saida=placaDoVeiculo+";";
        saida+=nomeDoCliente+";";
        saida+=data+";";
        saida+=QString::number(valorDaLocacao)+";";
        saida+=QString::number(kilometragemInicial)+";";
        saida+=QString::number(kilometragemFinal)+";";
        if(situacao)saida+="Locado;";//Quando o veiculo estiver locado a checkbox estará marcada assim
        //retornará verdadeiro sempre que o veiculo nao estiver disponivel
        else saida+="Disponivel;";
        return saida;
    }catch(...){
        throw QString ("Erro na Classe Desmaterializar da Locação");
    }

}
}
