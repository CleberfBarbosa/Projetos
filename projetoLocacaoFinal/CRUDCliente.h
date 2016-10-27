#ifndef CRUDCLIENTE_H
#define CRUDCLIENTE_H
#include <Cliente.h>
#include <queue>

namespace projetoLocacao{
//****************INTERFACE****************
class CRUDCliente{
public:
    virtual void incluir(Cliente objeto) = 0;
    virtual void alterar(Cliente objeto) = 0;
    virtual void excluir(QString nome) = 0;
    virtual Cliente consultar(QString nome) = 0;
    virtual std::queue<projetoLocacao::Cliente>* listagemDeClientes() = 0;
};
}
#endif // CRUDCLIENTE_H
