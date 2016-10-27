#ifndef LOCACAO_H
#define LOCACAO_H
#include <TransformarDadosLocacao.h>
#include <QString>
#include <QStringList>

namespace projetoLocacao{
class Locacao:public TransformarDadosLocacao // está herdando de sua interface TransformarDados
{
private:

    QString placaDoVeiculo;
    QString nomeDoCliente;
    QString data;
    float valorDaLocacao;
    int kilometragemInicial;
    int kilometragemFinal;
    bool situacao;


public:


    Locacao(){;}
    Locacao(QString placaDoVeiculo, QString nomeDoCliente, QString data, float valorDaLocacao,
            int kilometragemInicial, int kilometragemFinal, bool situacao);


    void setPlacaDoVeiculo(QString placaDoVeiculo){this->placaDoVeiculo=placaDoVeiculo;}
    void setnomeDoCliente(QString nomeDoCliente){this->nomeDoCliente=nomeDoCliente;}
    void setData(QString data){this->data=data;}
    void setValorDaLocacao(float valorDaLocacao){this->valorDaLocacao=valorDaLocacao;}
    void setKilometragemInicial(float kilometragemInicial){this->kilometragemInicial=kilometragemInicial;}
    void setKilometragemFinal(float kilometragemFinal){this->kilometragemFinal=kilometragemFinal;}
    void setSituacao(bool situacao){this->situacao=situacao;}

    QString getPlacaDoVeiculo()const {return placaDoVeiculo;}
    QString getnomeDoCliente()const {return nomeDoCliente;}
    QString getData()const {return data;}
    float getValorDaLocacao()const {return valorDaLocacao;}
    int getKilometragemInicial()const {return kilometragemInicial;}
    int getKilometragemFinal()const {return kilometragemFinal;}
    bool getSituacao()const {return situacao;}

    void materializarLocacao(QString str);
    QString desmaterializarLocacao()const;
};
}
#endif // LOCACAO_H
