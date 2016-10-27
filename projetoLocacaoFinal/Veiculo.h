#ifndef VEICULO_H
#define VEICULO_H
#include <QString>
#include <QStringList>
#include <TransformarDadosVeiculo.h>

namespace projetoLocacao{

class Veiculo:public TransformarDadosVeiculo //A classe veiculo herda de sua interface transformar dados
        //e deve implementar codigo de duas funções
{
private:
    QString marca;
    QString modelo;
    QString placa;
    float kilometragem;
    float valorDeCompra;
    bool situacao;


public:


    Veiculo(QString marca, QString modelo, QString placa, float kilometragem, float valorDeCompra, bool situacao);
    Veiculo(){}


    void setMarca(QString marca){this->marca=marca;}
    void setModelo(QString modelo){this->modelo=modelo;}
    void setPlaca(QString placa){this->placa=placa;}
    void setKilometragem(float kilometragem){this->kilometragem=kilometragem;}
    void setValorDeCompra(float valorDeCompra){this->valorDeCompra=valorDeCompra;}
    void setSituacao(bool situacao){this->situacao=situacao;}


    QString getMarca()const{return marca;}
    QString getModelo()const{return modelo;}
    QString getPlaca()const{return placa;}
    float getKilometragem()const{return kilometragem;}
    float getValorDeCompra()const{return valorDeCompra;}
    bool getSituacao()const{return situacao;}


    //aqui será implementado as funções herdadas
    void materializarVeiculo(QString str);
    QString desmaterializarVeiculo()const;
};

}
#endif // VEICULO_H
