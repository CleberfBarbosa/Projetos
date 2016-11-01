#include "duelo.h"
#include "ui_duelo.h"

duelo::duelo(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::duelo),
    music("C:\\Users\\Cleber\\Documents\\Compiladores\\Game\\Sounds\\pvp\\DungeonTheme-Forgotton Temple B1F.wav"),
    caminho("C:\\Users\\Cleber\\Documents\\Compiladores\\Game\\")
{
    ui->setupUi(this);
    hor=0;
    min=0;
    seg=0;
    setWindowTitle("[0"+QString::number(hor)+":0"+QString::number(min)+":0"+QString::number(seg)+"] - PvP");
    lendoArquivo();
    gerandoTela();

}

duelo::~duelo()
{
    disconnect(curr_timer,SIGNAL(timeout()),this,SLOT(current_time()));
    disconnect(timer, SIGNAL(timeout()), this, SLOT(music_end()));
    delete ui;
}

void duelo::set_music(){
    int num=rand() % 22;//0~21 / 22musicas;
    QStringList lista;
    lista <<"DungeonTheme-Forgotton Temple B1F.wav"
         <<"DungeonTheme-Maquinas Outpost.wav"
        <<"DungeonTheme-Panic Cave.wav"
       <<"DungeonTheme-Q_a_korea.wav"
      <<"DungeonTheme-Q_al.wav"
     <<"DungeonTheme-Q_bad_girl.wav"
    <<"DungeonTheme-Q_beautiful.wav"
    <<"DungeonTheme-Q_jindale.wav"
    <<"DungeonTheme-Q_jng_o.wav"
    <<"DungeonTheme-Q_letter.wav"
    <<"DungeonTheme-Q_smoke_city.wav"
    <<"DungeonTheme-Q_sun.wav"
    <<"DungeonTheme-Q_the_fiction.wav"
    <<"Headquarters.wav"
    <<"MapTheme-Fort. Ruina.wav"
    <<"MapTheme-Mutant Forest.wav"
    <<"MapTheme-NostalgicForest.wav"
    <<"MapTheme-Pontus Ferrum.wav"
    <<"MapTheme-Tierra Gloriosa.wav"
    <<"Pain of War.wav"
    <<"The 1st Battle.wav"
    <<"UITheme-Mission Battle.wav";
    QStringList tempo;
    tempo   <<"235000"//3:55
           <<"228000"//3:48
          <<"163000"//2:43
         <<"30000"//0:30
        <<"73000"//1:13
       <<"38000"//0:38
      <<"36000"//0:36
     <<"61000"//1:01
    <<"31000"//0:31
    <<"28000"//0:28
    <<"41000"//0:41
    <<"38000"//0:38
    <<"38000"//0:38
    <<"62000"//1:02
    <<"285000"//4:45
    <<"166000"//2:46
    <<"181000"//3:01
    <<"144000"//2:24
    <<"130000"//2:10
    <<"152000"//2:32
    <<"131000"//2:11
    <<"157000";//2:37
    music.play(caminho+"Sounds\\pvp\\" + lista[num]);
    timer = new QTimer(this);
    connect( timer, SIGNAL(timeout()), this, SLOT(music_end()));
    timer->start(tempo[num].toInt());
}

void duelo::music_end(){
    disconnect(timer, SIGNAL(timeout()), this, SLOT(music_end()));
    music.stop();
    set_music();
}

void duelo::start_timer_count(){
    hor=0;
    min=0;
    seg=0;
    curr_timer= new QTimer(this);
    connect(curr_timer,SIGNAL(timeout()),this,SLOT(current_time()));
    curr_timer->start(1000);
}

void duelo::current_time(){
    seg++;
    if(seg==60){
        min++;
        seg=0;
    }
    if(min==60){
        hor++;
        min=0;
    }
    if(hor<10){
        if(min<10){
            if(seg<10)
                setWindowTitle("[0"+QString::number(hor)+":0"+QString::number(min)+":0"+QString::number(seg)+"] - PvP");
            else
                setWindowTitle("[0"+QString::number(hor)+":0"+QString::number(min)+":"+QString::number(seg)+"] - PvP");
        }
        else
            setWindowTitle("[0"+QString::number(hor)+":"+QString::number(min)+":"+QString::number(seg)+"] - PvP");
    }
    else
        setWindowTitle("["+QString::number(hor)+":"+QString::number(min)+":"+QString::number(seg)+"] - PvP");
}

void duelo::stopping_music(){
    disconnect(timer, SIGNAL(timeout()), this, SLOT(music_end()));
    timer->stop();
    disconnect(curr_timer,SIGNAL(timeout()),this,SLOT(current_time()));
    curr_timer->stop();
    music.stop();
}

void duelo::lendoArquivo(){ //aqui ele le o arquivo e ja pega a lista de movimentos do personagem
    std::string classe;
    std::fstream arquivo1,arquivo2;
    arquivo1.open("player1.txt",std::fstream::in);
    arquivo2.open("player2.txt",std::fstream::in);

    getline(arquivo1,classe);
    //verificação do personagem do player 1
    if(classe == "Warrior"){
        player1 = new Personagem("Warrior");
    }else if(classe == "Wizard"){
        player1 = new Personagem("Wizard");
    }else if(classe == "Assassin"){
        player1 = new Personagem("Assassin");
    }else{
        QMessageBox *msg=new QMessageBox(this);
        msg->setText("Erro: classe invalida para player01.");
        msg->setWindowTitle("ERRO!");
        msg->setIcon(QMessageBox::Critical);
        msg->exec();
        exit(0);
    }

    getline(arquivo2,classe);
    //verificação do personagem do player 2
    if(classe == "Warrior"){
        player2 = new Personagem("Warrior");
    }else if(classe == "Wizard"){
        player2 = new Personagem("Wizard");
    }else if(classe == "Assassin"){
        player2 = new Personagem("Assassin");
    }else{
        QMessageBox *msg=new QMessageBox(this);
        msg->setText("Erro: classe invalida para player01.");
        msg->setWindowTitle("ERRO!");
        msg->setIcon(QMessageBox::Critical);
        msg->exec();
        exit(0);
    }

    //----Preenchendo a lista de comandos-----------------------------------
    std::string movimento;
    while(!arquivo1.eof()){
        getline(arquivo1,movimento);
        player1->movimentos.push(movimento);
    }
    while(!arquivo2.eof()){
        getline(arquivo2,movimento);
        player2->movimentos.push(movimento);
    }
    arquivo1.close();
    arquivo2.close();
}

void duelo::gerandoTela(){
    //----Setando os valores da tela-------------------------------

    ui->progressBar_player01_HP->setRange(0,player1->getHpMax());
    ui->progressBar_player01_SP->setRange(0,player1->getSpMax());
    QPixmap person1(caminho+"IMG\\TelaCombate\\"+QString::fromStdString(player1->getClasse())+".jpg");
    QPixmap person1_icon(caminho+"IMG\\TelaCombate\\btn"+QString::fromStdString(player1->getClasse())+".gif");
    ui->label_player01_img->setPixmap(person1);
    ui->label_player01_class_icon->setPixmap(person1_icon);

    ui->progressBar_player02_HP->setRange(0,player2->getHpMax());
    ui->progressBar_player02_SP->setRange(0,player2->getSpMax());
    QPixmap person2(caminho+"IMG\\TelaCombate\\"+QString::fromStdString(player2->getClasse())+".jpg");
    QPixmap person2_icon(caminho+"IMG\\TelaCombate\\btn"+QString::fromStdString(player2->getClasse())+".gif");
    ui->label_player02_img->setPixmap(person2);
    ui->label_player02_class_icon->setPixmap(person2_icon);

    setandoProgressBar();
}

void duelo::setandoProgressBar(){
    ui->progressBar_player01_HP->setValue(player1->getHp());
    ui->progressBar_player01_SP->setValue(player1->getSp());

    ui->progressBar_player02_HP->setValue(player2->getHp());
    ui->progressBar_player02_SP->setValue(player2->getSp());
}

void duelo::verificaVencedor(){
    if(float(player1->getHp()/float(player1->getHpMax())) > float(player2->getHp())/float(player2->getHpMax()))
        ui->labelVencedor->setText("PLAYER 1 VENCEU");
    else if(float(player2->getHp()/float(player2->getHpMax())) > float(player1->getHp())/float(player1->getHpMax()))
        ui->labelVencedor->setText("PLAYER 2 VENCEU");
    else
        ui->labelVencedor->setText("EMPATE");
}

void duelo::ataqueSemDefesa(Personagem *atacante, Personagem *vitima){
    if((atacante->getSp())>=(atacante->getCustoAtaque())){//verificando se o atacante tem sp pra atacar
        //Ataque
        vitima->setHp((vitima->getHp())-(atacante->getDanoAtaque())); //Retira o hp da vitima
        atacante->setSp((atacante->getSp())-(atacante->getCustoAtaque())); //Diminui o sp do atacante

        if(vitima->getHp()<0)vitima->setHp(0);

        if(atacante == player1)
            ui->labelMovimentoP1->setText("Atacando");
        else
            ui->labelMovimentoP2->setText("Atacando");
        setandoProgressBar();

    }else{
        if(atacante == player1)
            ui->labelMovimentoP1->setText("Tentou ataque mas não possuia SP.");
        else
            ui->labelMovimentoP2->setText("Tentou ataque mas não possuia SP.");
    }
}

void duelo::ataqueComDefesa(Personagem *atacante,Personagem *defensor){
    if((atacante->getSp())>=(atacante->getCustoAtaque())){//verificando se o atacante tem sp pra atacar
        //Ataque
        defensor->setHp((defensor->getHp())- (atacante->getDanoAtaque() * defensor->getPorcentagemDefesa())); //Retira o hp da vitima
        atacante->setSp((atacante->getSp())-(atacante->getCustoAtaque())); //Diminui o sp do atacante

        if(defensor->getHp()<0)defensor->setHp(0);

        if(atacante == player1)
            ui->labelMovimentoP1->setText("Atacando");
        else
            ui->labelMovimentoP2->setText("Atacando");
        setandoProgressBar();

    }else{
        if(atacante == player1)
            ui->labelMovimentoP1->setText("Tentou ataque mas não possuia SP.");
        else
            ui->labelMovimentoP2->setText("Tentou ataque mas não possuia SP.");
    }
}

void duelo::defesa(Personagem *defensor){
    //aumenta o sp do defensor
    defensor->setSp(defensor->getSp() + defensor->getBonusDefesa());
    //verifica se o sp do defensor nao passou do limite
    if(defensor->getSp() > defensor->getSpMax()) defensor->setSp(defensor->getSpMax());
    setandoProgressBar();

    //Setando o movimento na label
    if(defensor == player1)
        ui->labelMovimentoP1->setText("O Player está defendendo.");
    else
        ui->labelMovimentoP2->setText("O Player está defendendo.");
}

void duelo::cura(Personagem *curando){
    //cura do player, recupera o hp
    if((curando->getSp())>=(curando->getCustoCura())){//verificando se o player tem sp pra curar
        curando->setHp(curando->getHp() + curando->getCura());
        if(curando->getHp() > curando->getHpMax()) curando->setHp(curando->getHpMax()); //Verifica se o hp do player
        //nao passou do max. se tiver passado ele corrige

        setandoProgressBar();

        //Setando o movimento na label
        if(curando == player1)
            ui->labelMovimentoP1->setText("O Player se curou.");
        else
            ui->labelMovimentoP2->setText("O Player está se curou.");

    }else{
        if(curando == player1)
            ui->labelMovimentoP1->setText("O Player tentou se curar mas não possui SP..");
        else
            ui->labelMovimentoP2->setText("O Player tentou se curar mas não possui SP.");
    }
}



void duelo::batalha(){


    if(player1->movimentos.front() == "Attack"){//----------------------PLAYER 1 TENTANDO ATACAR------------------
        player1->movimentos.pop();
        if(player2->movimentos.front() == "Attack"){//------------------PLAYER 2 TAMBEM VAI ATACAR------------------
            player2->movimentos.pop();
            ataqueSemDefesa(player1, player2); //Player 1 ataca player 2
            ataqueSemDefesa(player2, player1); //Player 2 ataca player 1
        }else if(player2->movimentos.front() == "Defense"){//------------PLAYER 2 VAI DEFENDER------------------
            player2->movimentos.pop();
            defesa(player2); //Player 2 se defende
            ataqueComDefesa(player1, player2); //Player 1 ataca player 2
        }else if(player2->movimentos.front() == "Heal"){//---------------PLAYER TENTANDO SE CURAR------------------
            player2->movimentos.pop();
            cura(player2); //player 2 se cura
            ataqueSemDefesa(player1, player2); //player 1 ataca player 2
        }else{//-----------------------------------------FILA DO PLAYER 2 VAZIA OU COM MOV INVALIDO----------------
            ataqueSemDefesa(player1, player2); //Player 1 ataca player 2
            if(player2->movimentos.size() == 1){
                ui->labelMovimentoP2->setText("O Player 2 não possui mais movimentos.");
            }else{
                player2->movimentos.pop();
                ui->labelMovimentoP2->setText("O Player 2 tentou um movimento inválido.");
            }
        }
    }else if(player1->movimentos.front() == "Defense"){//----------------------PLAYER 1 VAI DEFENDER------------------
        player1->movimentos.pop();
        if(player2->movimentos.front() == "Attack"){//------------------PLAYER 2 VAI ATACAR------------------
            player2->movimentos.pop();
            defesa(player1); //Player 1 se defende
            ataqueComDefesa(player2, player1); //Player 2 ataca player 1
        }else if(player2->movimentos.front() == "Defense"){//------------PLAYER 2 TAMBEM VAI DEFENDER------------------
            player2->movimentos.pop();
            defesa(player1); //Player 1 se defende
            defesa(player2); //Player 2 se defende
        }else if(player2->movimentos.front() == "Heal"){//---------------PLAYER TENTANDO SE CURAR------------------
            player2->movimentos.pop();
            defesa(player1); //Player 1 se defende
            cura(player2); //player 2 se cura
        }else{//-----------------------------------------FILA DO PLAYER 2 VAZIA OU COM MOV INVALIDO----------------
            defesa(player1); //Player 1 se defende
            if(player2->movimentos.size() == 1){
                ui->labelMovimentoP2->setText("O Player 2 não possui mais movimentos.");
            }else{
                player2->movimentos.pop();
                ui->labelMovimentoP2->setText("O Player 2 tentou um movimento inválido.");
            }
        }
    }else if(player1->movimentos.front() == "Heal"){//-----------------------------PLAYER 1 VAI CURAR------------------
        player1->movimentos.pop();
        if(player2->movimentos.front() == "Attack"){//------------------PLAYER 2 VAI ATACAR------------------
            player2->movimentos.pop();
            cura(player1); //Player 1 se cura
            ataqueSemDefesa(player2, player1); //Player 2 ataca player 1
        }else if(player2->movimentos.front() == "Defense"){//------------PLAYER 2 VAI DEFENDER------------------
            player2->movimentos.pop();
            cura(player1); //Player 1 se cura
            defesa(player2); //Player 2 se defende
        }else if(player2->movimentos.front() == "Heal"){//---------------PLAYER TENTANDO SE CURAR------------------
            player2->movimentos.pop();
            cura(player1); //Player 1 se cura
            cura(player2); //player 2 se cura
        }else{//-----------------------------------------FILA DO PLAYER 2 VAZIA OU COM MOV INVALIDO----------------
            cura(player1); //Player 1 se cura
            if(player2->movimentos.size() == 1){
                ui->labelMovimentoP2->setText("O Player 2 não possui mais movimentos.");
            }else{
                player2->movimentos.pop();
                ui->labelMovimentoP2->setText("O Player 2 tentou um movimento inválido.");
            }
        }
    }else{//-----------------------------------------FILA DO PLAYER 1 VAZIA OU COM MOV INVALIDO----------------
        if(player1->movimentos.size() == 1){
            ui->labelMovimentoP1->setText("O Player 1 não possui mais movimentos.");
        }else{
            player1->movimentos.pop();
            ui->labelMovimentoP1->setText("O Player 1 tentou um movimento inválido.");
        }
        if(player2->movimentos.front() == "Attack"){//------------------PLAYER 2 VAI ATACAR------------------
            player2->movimentos.pop();
            ataqueSemDefesa(player2, player1); //Player 2 ataca player 1
        }else if(player2->movimentos.front() == "Defense"){//------------PLAYER 2 VAI DEFENDER------------------
            player2->movimentos.pop();
            defesa(player2); //Player 2 se defende
        }else if(player2->movimentos.front() == "Heal"){//---------------PLAYER TENTANDO SE CURAR------------------
            player2->movimentos.pop();
            cura(player2); //player 2 se cura
        }else{//-----------------------------------------FILA DO PLAYER 2 VAZIA OU COM MOV INVALIDO----------------
            if(player2->movimentos.size() == 1){
                ui->labelMovimentoP2->setText("O Player 2 não possui mais movimentos.");
            }else{
                player2->movimentos.pop();
                ui->labelMovimentoP2->setText("O Player 2 tentou um movimento inválido.");
            }
        }
    }
}


void duelo::on_pushButtonProximaRodada_clicked()
{
    if(controle){
        stopping_music();
        close();
    }
        if((player1->movimentos.size() == 1 && player2->movimentos.size() == 1) || player1->getHp()<=0 || player2->getHp()<=0){
            //entra aqui caso as filas de comandos de ambos tenham acabado ou um dos dois
            // tenha ficado sem hp
            verificaVencedor();
            ui->pushButtonProximaRodada->setText("Finalizar Partida");
            controle = true;
        }else{
    batalha();
     }

}


