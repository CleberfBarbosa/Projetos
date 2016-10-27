#ifndef VEICULOPERSISTENCIA_H
#define VEICULOPERSISTENCIA_H
#include <Veiculo.h>
#include <list>
#include <fstream>
#include <QMessageBox>
#include <QString>
namespace projetoLocacao{


class VeiculoPersistencia
{
private:
    QString nomeDoArquivoNoDisco;
public:
    VeiculoPersistencia(QString nomeDoArquivoNoDisco);

    void incluirVeiculo(Veiculo objeto);

    Veiculo consultarVeiculo(QString placa);

    void alterarVeiculo(Veiculo objetoParaExcluir, Veiculo objetoNovo);

    void excluirVeiculo(Veiculo objeto);

    std::list<projetoLocacao::Veiculo>* listagemDeVeiculos();

    void validaNovaPlaca(QString placaVerificada);



};


}

#endif // VEICULOPERSISTENCIA_H
