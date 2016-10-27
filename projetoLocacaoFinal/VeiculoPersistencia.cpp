#include "VeiculoPersistencia.h"
namespace projetoLocacao{


//-------------------------------------------------------------------------------------------------------------
//Aqui vamos dar nome ao arquivo
//sempre que criamos um objeto do veiculo persistencia em alguma lugar damos um nome ao arquivo
VeiculoPersistencia::VeiculoPersistencia(QString nomeDoArquivoNoDisco):
    nomeDoArquivoNoDisco(nomeDoArquivoNoDisco)
{
}


//-------------------------------------------------------------------------------------------------------------
void VeiculoPersistencia::incluirVeiculo(Veiculo objeto)
{
    try
    {
        //Crio um identificado de arquivo que é o arquivoVeiculo nesse caso ele pode abrir o arquivo apenas
        //para escrita pois é um ofstream
        std::ofstream arquivoVeiculo;

        //Aqui eu abro o arquivo para escrita, e com o app eu estou dizendo que nao quero que apague nada
        //caso o arquivo exista, ele vai escrever no fim do arquivo
        //dentro do parenteses fica o nome que o arquivo deve ter, porem o nome do arquivo deve ser em char
        //entao eu converto de QString para string e de string para char
        arquivoVeiculo.open(nomeDoArquivoNoDisco.toStdString().c_str(),
                std::ios::out|std::ios::app);
        //Verifica se o arquivo foi aberto
        if(!arquivoVeiculo.is_open()){
            throw QString ("Arquivo de veiculos nao foi aberto");
        }

        //com o objeto eu chamo o desmaterializar assim ele transforma o objeto em uma QString
        //porem arquivos nao reconhecem QString entao eu o converto para string e como o comando <<
        //eu o gravo no arquivo e dou um \n para pular para a proxima linha
        arquivoVeiculo<<objeto.desmaterializarVeiculo().toStdString()+"\n";
        arquivoVeiculo.close();//fecho o arquivo
    }catch(...){
        throw QString("Erro no metodo incluir");
    }

}



//-------------------------------------------------------------------------------------------------------------
Veiculo VeiculoPersistencia::consultarVeiculo(QString placa)
{

    try
    {
        /*
         * crio um ponteiro para uma lista do tipo Veiculo
         * depois chamo o metodo de listagem que me devolve um endereço de memoria para uma lista de Veiculos
         * e faço meu ponteiro lista receber e retorno da função listagem
         */
            std::list<projetoLocacao::Veiculo>* listaDeVeiculos;
            listaDeVeiculos = listagemDeVeiculos();

            //enquanto a lista nao estiver vazia ele vai procurar o elemento cuja placa corresponde
            while(!listaDeVeiculos->empty())
            {
                //pego primeiro elemento da lista mas nao o excluo da lista
                Veiculo objeto=listaDeVeiculos->front();
                if(objeto.getPlaca()==placa)//Aqui vou conferir se a placa do objeto que estava na lista
                    // é igual a placa pesquisada
                {
                    //caso seja eu deleto a lista e retorno o objeto
                    delete listaDeVeiculos;
                    return objeto;
                }
                //caso nao eu retiro o primeiro elemento da lista que foi o elemento que acabou de ser
                //pesquisado
                listaDeVeiculos->pop_front();
            }
            //caso ele nao entre no if é pq a placa nao esta cadastrada entao eu so deleto a lista
            // e lanço uma exeção
            delete listaDeVeiculos;
            throw QString("Nao foi encontrado");
    }catch(...){
        throw QString("Não foi possivel consultar ou elemento nao existe");
    }
}



//-------------------------------------------------------------------------------------------------------------
/*
 * O primeiro objeto é o antigo que foi o que seria alterado
 * e o segundo é o objeto ja alterado
 */
void VeiculoPersistencia::alterarVeiculo(Veiculo objetoParaExcluir, Veiculo objetoNovo)
{
    try
    {
        //primeiro vejo se a placa existe
        //se ela existe entao me retorna um objeto, entao eu passo esse objeto como parametro para ser excluido
        excluirVeiculo(objetoParaExcluir);
        incluirVeiculo(objetoNovo);
        }catch(...){
        throw QString("Não foi possivel alterar");
    }
}



//-------------------------------------------------------------------------------------------------------------
void VeiculoPersistencia::excluirVeiculo(Veiculo objeto)
{
    try
    {
        /*
         * crio um ponteiro para uma lista do tipo Veiculo
         * depois chamo o metodo de listagem que me devolve um endereço de memoria para uma lista de Veiculos
         * e faço meu ponteiro lista receber e retorno da função listagem
         */
        std::list<projetoLocacao::Veiculo>* listaDeVeiculos;
        listaDeVeiculos=listagemDeVeiculos();
        //Crio um identificado de arquivo que é o arquivoVeiculo nesse caso ele pode abrir o arquivo apenas
        //para escrita pois é um ofstream
        std::ofstream arquivoVeiculos;
        //Aqui eu abro o arquivo para escrita, porem sem o app pois ele vai abrir o arquivo e apagar tudo que
        //esta gravado nele
        //dentro do parenteses fica o nome que o arquivo deve ter, porem o nome do arquivo deve ser em char
        //entao eu converto de QString para string e de string para char
        arquivoVeiculos.open(nomeDoArquivoNoDisco.toStdString().c_str(),
                std::ios::out);
        //Verifica se o arquivo foi aberto
        if(!arquivoVeiculos.is_open()){
            delete listaDeVeiculos;
            throw QString ("Arquivo de Veiculos nao foi aberto");
        }
        //Enquanto a lista nao estiver vazia ele repete
        while(!listaDeVeiculos->empty())
        {
            Veiculo objetoDaLista=listaDeVeiculos->front();//objeto veiculo recebe o primeiro elemento da lista
            if(objetoDaLista.getPlaca()!=objeto.getPlaca())
                //verifica se o elemento da lista é o referente a placa digitada
                //caso nao seja ele entra no if e grava o elemento no arquivo
            {
                //com o objeto eu chamo o desmaterializar assim ele transforma o objeto em uma QString
                //porem arquivos nao reconhecem QString entao eu o converto para string e como o comando <<
                //eu o gravo no arquivo e dou um \n para pular para a proxima linha
                arquivoVeiculos<<objetoDaLista.desmaterializarVeiculo().toStdString()+"\n";
            }
            //entao eu retiro o elemento pesquisado da lista
            listaDeVeiculos->pop_front();
        }//sendo assim quando chegar aqui todos os elementos da lista terão sido gravados no arquivo
        //exceto o que deveria ser excluido, assim ele deixa de fazer parte do elementos cadastrados
        delete listaDeVeiculos;//deleto a lista
        arquivoVeiculos.close();
            }catch(...){
        throw QString("Não foi possivel excluir ou elemento não existe");
    }

}


//-------------------------------------------------------------------------------------------------------------
std::list<projetoLocacao::Veiculo>* VeiculoPersistencia::listagemDeVeiculos()
{
    try
    {
        //Crio um ponteiro para uma lista do tipo Veiculo
        std::list<projetoLocacao::Veiculo>* listaDeVeiculos;
        //crio por new uma lista para a qual meu ponteiro vai apontar, crio ela por new pq vou precisar dela
        //depois, e se nao for assim ela vai desaparecer qnd passar pelo fecha chaves
        listaDeVeiculos=new std::list<projetoLocacao::Veiculo>();
        //crio um identificador de arquivo apenas para leitura
        std::ifstream arquivoVeiculos;
        //Aqui eu abro o arquivo para leitura
        //dentro do parenteses fica o nome que o arquivo deve ter, porem o nome do arquivo deve ser em char
        //entao eu converto de QString para string e de string para char
        arquivoVeiculos.open(nomeDoArquivoNoDisco.toStdString().c_str());
        if(!arquivoVeiculos.is_open())//verifica se o arquivo foi aberto normalmente
        {
            delete listaDeVeiculos;
            throw QString ("Arquivo de veiculos não foi aberto");
        }
        std::string linha;
        getline(arquivoVeiculos,linha);//pego a linha do arquivo e guardo na string linha
        while(!arquivoVeiculos.eof())//enquanto o arquivo nao estiver vazio ele repete
        {
            Veiculo objeto;
            //uso o metodo materializar para pegar os dados da linha e preencher os atributos do objeto
            objeto.materializarVeiculo(QString::fromStdString(linha));//transformo a string linha em QString
            //para passar por atributo
            listaDeVeiculos->push_front(objeto);
            //depois do objeto pronto eu o introduzo na primeira posição
            //da minha lista
            //e pego a proxima linha do arquivo para fazer a mesma coisa
            getline(arquivoVeiculos,linha);
        }
        arquivoVeiculos.close();//fecho o arquivo
        return listaDeVeiculos;//retorno a lista
    }catch(std::bad_alloc&){
        //caso a lista nao possa ser criada pq alguma linha está com problema ou nao
        //haja espaço suficiente na memoria para criar uma lista para todos os elementos do arquivo
    throw QString("Lista não foi criada");
}

}




//-------------------------------------------------------------------------------------------------------------
void VeiculoPersistencia::validaNovaPlaca(QString placaVerificada)
{
    try{
        //Estou fazendo isso aqui para solucionar um problema, quando o arquivo ainda nao existe
        //ele apresenta um erro, assim ele vai sempre se certificar que o arquivo exista
        std::fstream arquivoVeiculo;
        arquivoVeiculo.open(nomeDoArquivoNoDisco.toStdString().c_str(),
                std::ios::out|std::ios::app);
        arquivoVeiculo.close();

        std::list<projetoLocacao::Veiculo>* listaDeVeiculos;
        listaDeVeiculos = listagemDeVeiculos();
        while(!listaDeVeiculos->empty())
        {
            Veiculo objetoDaLista=listaDeVeiculos->front();//objeto veiculo recebe o primeiro elemento da lista
            if(objetoDaLista.getPlaca() == placaVerificada)
            {
                delete listaDeVeiculos;
                throw QString("Placa ja existente");
            }
            listaDeVeiculos->pop_front();
        }
        delete listaDeVeiculos;
    }catch(...){
        throw QString ("Placa Invalida ou ja existente");
    }
}


}
