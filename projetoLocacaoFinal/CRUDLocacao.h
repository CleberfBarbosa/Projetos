#ifndef CRUDLOCACAO_H
#define CRUDLOCACAO_H
#include <Locacao.h>
#include <Veiculo.h>
#include <Cliente.h>
#include <stack>

namespace projetoLocacao{
//****************INTERFACE****************
class CRUDLocacao{
public:
    virtual void locar(Locacao objeto) = 0;
    virtual void devolver(Locacao objeto) = 0;
    virtual Locacao consultarLocacao(QString placa) = 0;
    virtual std::stack<projetoLocacao::Locacao>* listagemDeLocacao() = 0;
};




}
#endif // CRUDLOCACAO_H
