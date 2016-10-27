#ifndef TRANSFORMARDADOSCLIENTE_H
#define TRANSFORMARDADOSCLIENTE_H
#include <QString>

namespace projetoLocacao{

class TransformarDadosCliente{
//Interface: Classe somente com metodos virtuais puros
public:
    virtual void materializarCliente(QString str)=0; //pega o objeto e transforma em string
    virtual QString desmaterializarCliente()const=0; //pega o string e transforma em objeto
};
}
#endif // TRANSFORMARDADOSCLIENTE_H
