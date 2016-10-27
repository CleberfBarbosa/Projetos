#ifndef CLIENTEPERSISTENCIA_H
#define CLIENTEPERSISTENCIA_H
#include <Cliente.h>
#include <queue>
#include <fstream>
#include <CRUDCliente.h>

namespace projetoLocacao {
class ClientePersistencia:public CRUDCliente
{
private:
    QString nomeDoArquivoNoDisco;
public:
    ClientePersistencia(QString nomeDoArquivoNoDisco);

    void incluir(Cliente objeto);
    void alterar(Cliente objeto);
    void excluir(QString nome);
    Cliente consultar(QString nome);
    std::queue<projetoLocacao::Cliente>* listagemDeClientes();

};
}
#endif // CLIENTEPERSISTENCIA_H
