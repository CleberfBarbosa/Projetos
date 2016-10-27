#include "Locacaopersistencia.h"




namespace projetoLocacao{

//-------------------------------------------------------------------------------------------------------------
//Aqui vamos dar nome ao arquivo
//sempre que criamos um objeto do veiculo persistencia em alguma lugar damos um nome ao arquivo

LocacaoPersistencia::LocacaoPersistencia(QString nomeDoArquivoNoDisco):
    nomeDoArquivoNoDisco(nomeDoArquivoNoDisco)
{
}





//--------------------------------------------------------------------------------------------------------

void LocacaoPersistencia::locar(Locacao objeto){
    try{
        //Crio um identificado de arquivo que é o arquivoLocacao nesse caso ele pode abrir o arquivo apenas
        //para escrita pois é um ofstream
        std::ofstream arquivoLocacao;

        //Aqui eu abro o arquivo para escrita, e com o app eu estou dizendo que nao quero que apague nada
        //caso o arquivo exista, ele vai escrever no fim do arquivo
        //dentro do parenteses fica o nome que o arquivo deve ter, porem o nome do arquivo deve ser em char
        //entao eu converto de QString para string e de string para char
        arquivoLocacao.open(nomeDoArquivoNoDisco.toStdString().c_str(),
                std::ios::out|std::ios::app);

        //Verifica se o arquivo foi aberto
        if(!arquivoLocacao.is_open()){
            throw QString ("Arquivo de veiculos nao foi aberto");
        };

        //com o objeto eu chamo o desmaterializar assim ele transforma o objeto em uma QString
        //porem arquivos nao reconhecem QString entao eu o converto para string e como o comando <<
        //eu o gravo no arquivo e dou um \n para pular para a proxima linha
        arquivoLocacao<<objeto.desmaterializarLocacao().toStdString()+"\n";
        arquivoLocacao.close();//fecho o arquivo
    }catch(...){
        throw QString("Erro no metodo incluir");
    }

}




//--------------------------------------------------------------------------------------------------------
/*
 * Nessa função ele irá receber um objeto e simplesmente exclui-lo do arquivo
 * ele cria uma pilha com todos os objetos do arquivo e procura pela placa x
 * enquanto ele procura placa por placa ele vai as gravando, quando ele verificar que a placa
 * do elemento que está na pilha é a mesma do objeto que foi passado por paramentro ele o pula
 * fazendo com que ele fique fora do arquivo assim ele está excluido da agenda
 */
void LocacaoPersistencia::devolver(Locacao objeto)
{
    try{
        //declara um ponteiro para um pilha do tipo locação
        std::stack<projetoLocacao::Locacao>*pilhaDeLocacao;
        //chamo o metodo listagem que me retorna uma pilha de objetos com todos os elementos gravados
        //no arquivo
        pilhaDeLocacao=listagemDeLocacao();
        std::ofstream arquivoLocacao;//crio um identificador de arquivo para escrita

        //abro um arquivo somente para escrita sem app para que tudo que estava no arquivo
        //caso ele exista tenha sido apagado
        arquivoLocacao.open(nomeDoArquivoNoDisco.toStdString().c_str(),
                std::ios::out);
        //Verifica se o arquivo foi aberto
        if(!arquivoLocacao.is_open()){
            delete pilhaDeLocacao;
            throw QString ("Arquivo de veiculos nao foi aberto");
        };
        //enquanto ouver algum elemento na pilha ele vai repetir
        while(!pilhaDeLocacao->empty())
        {
            Locacao objDaPilha = pilhaDeLocacao->top();//objeto recebe o primeiro elemento da pilha
            //comparo a placa do objeto que foi passado por parametro com o que foi pego da pilha
            //caso eles nao sejam iguais eu vou grava-lo no arquivo
            if(objeto.getPlacaDoVeiculo()!=objDaPilha.getPlacaDoVeiculo())
            {
                //com o objeto eu chamo o desmaterializar assim ele transforma o objeto em uma QString
                //porem arquivos nao reconhecem QString entao eu o converto para string e como o comando <<
                //eu o gravo no arquivo e dou um \n para pular para a proxima linha
                arquivoLocacao<<objeto.desmaterializarLocacao().toStdString()+"\n";
            }
            pilhaDeLocacao->pop(); //retiro o primeiro elemento da lista
        }
        delete pilhaDeLocacao; //deleto a pilha
        arquivoLocacao.close();//fecho o arquivo
    }catch(...){
    throw QString("Placa não existe ou não está locada");
}
}





//--------------------------------------------------------------------------------------------------------
/*
 * crio um ponteiro para uma lista do tipo Veiculo
 * depois chamo o metodo de listagem que me devolve um endereço de memoria para uma lista de Veiculos
 * e faço meu ponteiro lista receber e retorno da função listagem
 */
Locacao LocacaoPersistencia::consultarLocacao(QString placa)
{
    try{
        std::stack<projetoLocacao::Locacao>* pilhaDeLocacoes;
        pilhaDeLocacoes = listagemDeLocacao();

        while(!pilhaDeLocacoes->empty())
        {//enquanto houver elementos na pilha ele repete
            Locacao objLocacao=pilhaDeLocacoes->top();//o objeto recebe o primeiro elemento da pilha

            //caso o elemento que foi pego da pilha seja o elemento cuja a placa está sendo procurada
            //ele deleta a pilha e retorna o objeto que foi encontrado
            if(objLocacao.getPlacaDoVeiculo()==placa)
            {
                delete pilhaDeLocacoes;
                return objLocacao;
            }
            pilhaDeLocacoes->pop();
        }
        //se chegar aqui é pq o elemento procurado nao existe entao ele deleta o ponteiro e lança uma execção
        delete pilhaDeLocacoes;
        throw QString ("Não foi encontrado");
    }catch(...){
    throw QString("Placa não existe ou não está locada");
}
}


//--------------------------------------------------------------------------------------------------------
std::stack<projetoLocacao::Locacao>* LocacaoPersistencia::listagemDeLocacao(){
    try{
        //crio um ponteiro para um pilha do tipo locação
        std::stack<projetoLocacao::Locacao>* pilhaDeLocacoes;
        //crio por new uma pilha para a qual meu ponteiro vai apontar, crio ela por new pq vou precisar dela
        //depois, e se nao for assim ela vai desaparecer qnd passar pelo fecha chaves
        pilhaDeLocacoes = new std::stack<projetoLocacao::Locacao>();
        std::ifstream arquivoLocacao;
        //Aqui eu abro o arquivo para leitura
        //dentro do parenteses fica o nome que o arquivo deve ter, porem o nome do arquivo deve ser em char
        //entao eu converto de QString para string e de string para char
        arquivoLocacao.open(nomeDoArquivoNoDisco.toStdString().c_str());

        if(!arquivoLocacao.is_open()){//verifica se o arquivo foi aberto normalmente
            delete pilhaDeLocacoes;
            //A Pilha foi criada, o processo não foi concluido,
            //ao retornar sera criado outro alocamento de memoria se nao for dado o delete
            throw QString("Arquivo de Locacoes nao foi aberto");
        }
        std::string linha;
        getline(arquivoLocacao, linha);//pego a linha do arquivo e guardo na string linha
        while(!arquivoLocacao.eof())
        {
            //enquanto o arquivo nao estiver vazio ele repete
            Locacao objeto;
            objeto.materializarLocacao(QString::fromStdString(linha));//transformo a string linha em QString
            //para passar por atributo
            pilhaDeLocacoes->push(objeto); //Pega o objeto e coloca na pilha
            getline(arquivoLocacao, linha);//pega o proximo elemento do arquivo
        }
        arquivoLocacao.close();//fecha o arquivo
        return pilhaDeLocacoes;//retorna a pilha
    }catch(std::bad_alloc&){
        throw QString("Pilha não foi criada");
    }
}

}
