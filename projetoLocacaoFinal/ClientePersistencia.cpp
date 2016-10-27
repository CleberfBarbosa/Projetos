#include "ClientePersistencia.h"
namespace projetoLocacao{
ClientePersistencia::ClientePersistencia(QString nomeDoArquivoNoDisco):
    nomeDoArquivoNoDisco(nomeDoArquivoNoDisco)
{
}

void ClientePersistencia::incluir(Cliente objeto){
    try{
        //Criando um arquivo para escrita
        std::ofstream arquivoCliente;
        //.toStdString().c_str() = Transformado Classe String padrão de c para c++
        arquivoCliente.open(nomeDoArquivoNoDisco.toStdString().c_str(),
                std::ios::out|std::ios::app);
        //std::ios::out|std::ios::app = Se não existe, cria arquivo para escrita
                                      //Se existe, adiciona o conteudo no final
        if(!arquivoCliente.is_open()){
            throw QString("Arquivo de Clientes nao foi aberto");
        }
        arquivoCliente<<objeto.desmaterializarCliente().toStdString()+"\n";
        arquivoCliente.close();
    }catch(...){
        throw QString("Erro no Metodo incluir");
    }
}

void ClientePersistencia::alterar(Cliente objeto){
    try{
        std::queue<projetoLocacao::Cliente> *filaDeClientes;
        filaDeClientes = listagemDeClientes();
        //Criando um arquivo para escrita
        std::ofstream arquivoCliente;
        arquivoCliente.open(nomeDoArquivoNoDisco.toStdString().c_str(), std::ios::out);
        //.toStdString().c_str() = Transformado Classe String padrão de c para c++
        if(!arquivoCliente.is_open()){
            throw QString("Arquivo de Clientes nao foi aberto");
        }
        while(!filaDeClientes->empty()){ //Enquanto a fila nao estiver vazia:
            projetoLocacao::Cliente conteudo = filaDeClientes->front();
            if(objeto.getNome() == conteudo.getNome()){ //se nome que eu pesquisei = nome que esta no arquivo:
                arquivoCliente<<objeto.desmaterializarCliente().toStdString()+"\n"; //nome que pesquisei no arquivo
            }
            else{
                arquivoCliente<<conteudo.desmaterializarCliente().toStdString()+"\n"; // nome que não pesquisei
            }
            filaDeClientes->pop();
        }
        arquivoCliente.close();
    }catch(std::bad_alloc&){
        throw QString("Fila nao foi criada");
    }
}

void ClientePersistencia::excluir(QString nome){
    try{
        bool existe = false;
        std::queue<projetoLocacao::Cliente> *filaDeContatos;
        filaDeContatos = listagemDeClientes();
        //Criando um arquivo para escrita
        std::ofstream arquivoCliente;
        arquivoCliente.open(nomeDoArquivoNoDisco.toStdString().c_str(), std::ios::out);
        //.toStdString().c_str() = Transformado Classe String padrão de c para c++
        if(!arquivoCliente.is_open()){
            throw QString("Arquivo de Clientes nao foi aberto");
        }
        while(!filaDeContatos->empty()){
            projetoLocacao::Cliente objeto;
            objeto = filaDeContatos->front();
            if(objeto.getNome() == nome){
                existe = true;
            }
            else{
                arquivoCliente<<objeto.desmaterializarCliente().toStdString()+"\n";
            }
            filaDeContatos->pop();
        }
            if(existe == false){
                throw QString("Cliente nao existe. Nao foi possivel excluir.");
        }
            arquivoCliente.close();
        }catch(std::bad_alloc&){
            throw QString("Fila nao foi criada");
        }
        catch(QString erro){
        throw erro;
        }
}


Cliente ClientePersistencia::consultar(QString nome){
    try{
        bool existe = false;
        //Criando arquivo para leitura
        std::ifstream arquivoCliente;
        arquivoCliente.open(nomeDoArquivoNoDisco.toStdString().c_str());
        //.toStdString().c_str() = Transformado Classe String padrão de c para c++
        if(!arquivoCliente.is_open()){
            throw QString("Arquivo de Clientes nao foi aberto");
        }
        std::string linha;
        getline(arquivoCliente, linha);
        while(!arquivoCliente.eof()){
            projetoLocacao::Cliente objeto;
            objeto.materializarCliente(QString::fromStdString(linha));
            if(objeto.getNome() == nome){
                existe = true;
                return objeto;
            }
            getline(arquivoCliente, linha);
        }
        arquivoCliente.close();
        if(existe == false){
            throw QString("Cliente nao existe. Nao foi possivel consultar/alterar.");
        }
    }catch(std::bad_alloc&){
            throw QString("Fila nao foi criada");
    }
        catch(QString erro){
        throw  erro;
        }
}

std::queue<projetoLocacao::Cliente>* ClientePersistencia::listagemDeClientes(){
    try{
        std::queue<projetoLocacao::Cliente>* filaDeClientes;
        filaDeClientes = new std::queue<projetoLocacao::Cliente>();
        //Criando arquivo para leitura
        std::ifstream arquivoCliente;
        arquivoCliente.open(nomeDoArquivoNoDisco.toStdString().c_str());
        if(!arquivoCliente.is_open()){
            delete filaDeClientes; //A Fila foi criada, o processo não foi concluido
                                   //ao retornar sera criado outro alocamento de memoria
            throw QString("Arquivo de Clientes nao foi aberto");
        }
        std::string linha;
        getline(arquivoCliente, linha);
        while(!arquivoCliente.eof()){
            projetoLocacao::Cliente objeto;
            objeto.materializarCliente(QString::fromStdString(linha)); //Retorna uma cópia da String linha
            filaDeClientes->push(objeto); //Pega o objeto e coloca na fila
            getline(arquivoCliente, linha);
        }
        arquivoCliente.close();
        return filaDeClientes;
    }catch(std::bad_alloc&){
        throw QString("Fila nao foi criada");
    }
}
}
