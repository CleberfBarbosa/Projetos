#ifndef CLIENTE_H
#define CLIENTE_H
#include<QString>
#include<TransformarDadosCliente.h>
#include<fstream>
#include<QStringList>

namespace projetoLocacao {//inicio

class Cliente:public TransformarDadosCliente //A classe Cliente herda de sua interface transformar dados
                                             //e deve implementar codigo de duas funções
{
private:
    QString nome;
    QString CPF;
    QString carteiraDeHabilitacao;
    int ddd;
    long telefone;
    QString email;
public:
    Cliente(QString nome, QString CPF, QString carteiraDeHabilitacao, int ddd, long telefone, QString email);
    Cliente(){}
    QString getNome()const{return nome;}
    QString getCPF()const{return CPF;}
    QString getCarteiraDeHabilitacao()const {return carteiraDeHabilitacao;}
    int getDdd()const{return ddd;}
    long getTelefone()const{return telefone;}
    QString getEmail()const{return email;}

    void setNome(QString nome){this->nome = nome;}
    void setCPF(QString CPF){this->CPF = CPF;}
    void setCarteiraDeHabilitacao(QString carteiraDeHabilitacao){this->carteiraDeHabilitacao = carteiraDeHabilitacao;}
    void setDdd(int ddd){this->ddd = ddd;}
    void setTelefone(long telefone){this->telefone = telefone;}
    void setEmail(QString email){this->email = email;}

    //implementacao das funções herdadas
    QString desmaterializarCliente()const;
    void materializarCliente(QString str);

};
}//fim

#endif // CLIENTE_H
