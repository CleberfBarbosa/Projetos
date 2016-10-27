#ifndef LOCACAOPERSISTENCIA_H
#define LOCACAOPERSISTENCIA_H
#include <Locacao.h>
#include <stack>
#include <fstream>
#include <CRUDLocacao.h>
#include <Veiculo.h>
#include <Cliente.h>


namespace projetoLocacao{
class LocacaoPersistencia:public CRUDLocacao
{
private:
    QString nomeDoArquivoNoDisco;
public:
    LocacaoPersistencia(QString nomeDoArquivoNoDisco);
    void locar(Locacao objeto);
    void devolver(Locacao objeto);
    Locacao consultarLocacao(QString placa);
    std::stack<projetoLocacao::Locacao>* listagemDeLocacao();
};
}

#endif // LOCACAOPERSISTENCIA_H
