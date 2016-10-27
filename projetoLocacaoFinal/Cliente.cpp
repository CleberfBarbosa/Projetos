#include "Cliente.h"
namespace projetoLocacao{//inicio

Cliente::Cliente(QString nome, QString CPF, QString carteiraDeHabilitacao, int ddd, long telefone, QString email):
    nome(nome),
    CPF(CPF),
    carteiraDeHabilitacao(carteiraDeHabilitacao),
    ddd(ddd),
    telefone(telefone),
    email(email)
{
}

QString Cliente::desmaterializarCliente()const{ //Transformando a string em objeto
    QString saida = nome;
    saida += ";";
    saida += CPF;
    saida+=";";
    saida += carteiraDeHabilitacao;
    saida+=";";
    saida+= QString::number(ddd);
    saida+=";";
    saida += QString::number(telefone);
    saida+=";";
    saida += email;
    return saida;
}

void Cliente::materializarCliente(QString str){ //Transformando o objeto em string
    try{
        QStringList strList = str.split(';');
        if(strList.length()!=6) throw;
        nome = strList[0];
        CPF = strList[1];
        carteiraDeHabilitacao = strList[2];
        ddd = strList[3].toInt();
        telefone = strList[4].toInt();
        email = strList[5];
    }catch(...){
throw QString("Erro no metodo materializar Cliente");
}
}

}//fim
