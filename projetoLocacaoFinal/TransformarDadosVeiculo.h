#ifndef TRANSFORMARDADOSVEICULO_H
#define TRANSFORMARDADOSVEICULO_H
#include <QString>

namespace projetoLocacao{
//Apenas um interface para a classe veiculo
class TransformarDadosVeiculo
{
public:
    virtual void materializarVeiculo(QString str)=0;
    virtual QString desmaterializarVeiculo()const=0;
};

}

#endif // TRANSFORMARDADOSVEICULO_H
