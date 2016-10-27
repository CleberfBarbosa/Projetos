#ifndef TRANSFORMARDADOSLOCACAO_H
#define TRANSFORMARDADOSLOCACAO_H
#include <QString>

namespace projetoLocacao {

class TransformarDadosLocacao{
//Interface: Classe somente com metodos virtuais puros
public:
    virtual void materializarLocacao(QString str)=0; //pega o objeto e transforma em string
    virtual QString desmaterializarLocacao()const=0; //pega o string e transforma em objeto
};

}
#endif // TRANSFORMARDADOSLOCACAO_H
