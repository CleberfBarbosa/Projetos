#include "Veiculo.h"


namespace projetoLocacao{

//----------------------------------------------------------------------------------------------------------------
Veiculo::Veiculo(QString marca, QString modelo, QString placa, float kilometragem, float valorDeCompra,
                 bool situacao):
    marca(marca),
    modelo(modelo),
    placa(placa),
    kilometragem(kilometragem),
    valorDeCompra(valorDeCompra),
    situacao(situacao)
{
}




//----------------------------------------------------------------------------------------------------------------
/*
 * O metodo desmaterializar pega o objeto, vai pegando todas as sua informações
 * e concatenando numa QString separando as infos por um ';' ele é chamado sempre que se adicionar um novo
 * veiculo.
 */
QString Veiculo::desmaterializarVeiculo()const
{
    try
    {
        QString saida;
        saida=marca+";";
        saida+=modelo+";";
        saida+=placa+";";
        saida+=QString::number(kilometragem)+";";
        saida+=QString::number(valorDeCompra)+";";
        if(situacao)saida+="disponivel;";
            else saida+="indisponivel;";
        return saida;
    }catch(...){
        throw QString ("Erro no metodo desmaterializar classe Veiculo");
    }
}



//----------------------------------------------------------------------------------------------------------------
/*
 * O metodo materializar pega uma QString que é referente a um linha do arquivo, dividi tudo que esta escrito
 * usando o ';' como parametro e cria uma lista de QStrings, então cada campo que está entre';'
 * da QString fica ocupando uma posição da lista, apartir dai usamos a lista para adicionar valores a um objeto
 * assim criamos um objeto apartir da QString do arquivo .
 */
void Veiculo::materializarVeiculo(QString str)
{
    try
    {
        QStringList strList=str.split(';');//cria a QStringList dizendo que a variavel str
        //será dividida usando como parametro de divisão o ';'
        if(strList.length()!=6)// throw QString ("Erro no metodo materializar classe Veiculo");
            //deve ter 6 posiçoes pois é a quantidade de atributos do objeto se nao for
            //esse o tamanho da strList entao está faltando algo e objeto nao pode ser montado corretamente
            //daqui para baixo é adicionado os valores aos atributos do objeto
        this->setMarca(strList[0]);
        this->setModelo(strList[1]);
        this->setPlaca(strList[2]);
        this->setKilometragem(strList[3].toFloat());
        this->setValorDeCompra(strList[4].toFloat());
        if(strList[5]=="disponivel")this->setSituacao(true);
        else this->setSituacao(false);
    }catch(...){
        throw QString ("Erro no metodo materializar classe Veiculo");
    }
}

}
