#include "selecao_mov.h"
#include "ui_selecao_mov.h"


pvp::pvp(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::pvp),
    music_pvp("C:\\Users\\Cleber\\Documents\\Compiladores\\Game\\Sounds\\pvp\\DungeonTheme-Forgotton Temple B1F.wav"),
    caminho("C:\\Users\\Cleber\\Documents\\Compiladores\\Game\\")
{
    ui->setupUi(this);
    //set_music();
    i=0;
}

pvp::~pvp()
{
    delete ui;
}

void pvp::character_selected(int character){
    if(character==1){//warrior
        this->character=character;
        ui->progressBar_HP->setRange(0,200);
        ui->progressBar_HP->setValue(200);
         //ui->progressBar_HP->setInvertedAppearance(true);
        ui->progressBar_SP->setRange(0,50);
        ui->progressBar_SP->setValue(50);
        //ui->progressBar_SP->setInvertedAppearance(true);
        QPixmap warr(caminho+"IMG\\Warrior(-50%).jpg");
        QPixmap warr_icon(caminho+"IMG\\Char_btn_warrior.gif");
        ui->character_img->setPixmap(warr);
        ui->character_icon->setPixmap(warr_icon);
        QPixmap skill_atack(caminho+"IMG\\atack.png");
        QPixmap skill_escudo(caminho+"IMG\\escudo.png");
        QPixmap skill_potion(caminho+"IMG\\potion.png");
        ui->pushButton_skill_atack_icon->setIcon(skill_atack);
        ui->pushButton_skill_escudo_icon->setIcon(skill_escudo);
        ui->pushButton_skill_potion_icon->setIcon(skill_potion);

        aux = new Personagem("Warrior");

        ui->labelAttackDano->setText(QString::number(aux->getDanoAtaque()));
        ui->labelAttackSp->setText(" - "+ QString::number(aux->getCustoAtaque()));

        ui->labelDefense->setText(QString::number(aux->getPorcentagemDefesa()*100)+" %");
        ui->labelDefenseSp->setText(" + "+ QString::number(aux->getBonusDefesa()));

        ui->labelHeal->setText(QString::number(aux->getCura()));
        ui->labelHealSp->setText(" - "+ QString::number(aux->getCustoCura()));

        delete aux;
    }
    else if(character==2){//wizard
        this->character=character;
        ui->progressBar_HP->setRange(0,50);
        ui->progressBar_HP->setValue(50);
         //ui->progressBar_HP->setInvertedAppearance(true);
        ui->progressBar_SP->setRange(0,150);
        ui->progressBar_SP->setValue(150);
        //ui->progressBar_SP->setInvertedAppearance(true);
        QPixmap warr(caminho+"IMG\\Wizard(-50%).jpg");
        QPixmap warr_icon(caminho+"IMG\\Char_btn_wizard.gif");
        ui->character_img->setPixmap(warr);
        ui->character_icon->setPixmap(warr_icon);
        QPixmap skill_atack(caminho+"IMG\\Fire_Blast_icon.png");
        QPixmap skill_escudo(caminho+"IMG\\Spirit_Intension_icon.png");
        QPixmap skill_potion(caminho+"IMG\\Mass_Heal_icon.png");
        ui->pushButton_skill_atack_icon->setIcon(skill_atack);
        ui->pushButton_skill_escudo_icon->setIcon(skill_escudo);
        ui->pushButton_skill_potion_icon->setIcon(skill_potion);

        aux = new Personagem("Wizard");

        ui->labelAttackDano->setText(QString::number(aux->getDanoAtaque()));
        ui->labelAttackSp->setText(" - "+ QString::number(aux->getCustoAtaque()));

        ui->labelDefense->setText(QString::number(aux->getPorcentagemDefesa()*100)+" %");
        ui->labelDefenseSp->setText(" + "+ QString::number(aux->getBonusDefesa()));

        ui->labelHeal->setText(QString::number(aux->getCura()));
        ui->labelHealSp->setText(" - "+ QString::number(aux->getCustoCura()));

        delete aux;

    }
    else{//assassin
        this->character=character;
        ui->progressBar_HP->setRange(0,100);
        ui->progressBar_HP->setValue(100);
         //ui->progressBar_HP->setInvertedAppearance(true);
        ui->progressBar_SP->setRange(0,100);
        ui->progressBar_SP->setValue(100);
        //ui->progressBar_SP->setInvertedAppearance(true);
        QPixmap warr(caminho+"IMG\\Blader(-50%).jpg");
        QPixmap warr_icon(caminho+"IMG\\Char_btn_blader.gif");
        ui->character_img->setPixmap(warr);
        ui->character_icon->setPixmap(warr_icon);
        QPixmap skill_atack(caminho+"IMG\\Twin_Moon_Slash_icon.png");
        QPixmap skill_escudo(caminho+"IMG\\Intuition_icon.png");
        QPixmap skill_potion(caminho+"IMG\\potion.png");
        ui->pushButton_skill_atack_icon->setIcon(skill_atack);
        ui->pushButton_skill_escudo_icon->setIcon(skill_escudo);
        ui->pushButton_skill_potion_icon->setIcon(skill_potion);

        aux = new Personagem("Assassin");

        ui->labelAttackDano->setText(QString::number(aux->getDanoAtaque()));
        ui->labelAttackSp->setText(" - "+ QString::number(aux->getCustoAtaque()));

        ui->labelDefense->setText(QString::number(aux->getPorcentagemDefesa()*100)+" %");
        ui->labelDefenseSp->setText(" + "+ QString::number(aux->getBonusDefesa()));

        ui->labelHeal->setText(QString::number(aux->getCura()));
        ui->labelHealSp->setText(" - "+ QString::number(aux->getCustoCura()));

        delete aux;
    }
}

void pvp::set_music(){//set a random music
    srand(time(NULL));
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
    //
    //music_pvp.play("C:\\Projetos\\Test\\Sounds\\pvp\\" + lista[num]);
    //music_pvp.play("C:\\Projetos\\Test\\Sounds\\FX_Death_1.wav");
//    i=0;
    music_pvp.play(caminho+"Sounds\\pvp\\" + lista[num]);
    timer = new QTimer();
    connect( timer, SIGNAL(timeout()), this, SLOT(music_end()));
    timer->start(10000);

//    if(music_pvp.isFinished()){
//        setWindowTitle("Terminou");
//    }
//    else{
//        setWindowTitle("Nao Terminou"/*+QString::number(++i)*/);
//    }
}

void pvp::music_end(){
//    if(music_pvp.isFinished()){
//        setWindowTitle("Terminou");
//    }
//    else{
//        setWindowTitle("Nao Terminou"+QString::number(++i));
//    }
}


void pvp::on_pushButton_skill_atack_icon_clicked()
{
    i++;
   QString texto="";
   texto+= ui->label_movimentos->text();
   ui->label_movimentos->setText(texto+"Attack\n");
   if(i==10){
       ui->pushButton_skill_atack_icon->setEnabled(false);
       ui->pushButton_skill_escudo_icon->setEnabled(false);
       ui->pushButton_skill_potion_icon->setEnabled(false);
   }
}

void pvp::on_pushButton_skill_escudo_icon_clicked()
{
    i++;
   QString texto="";
   texto+= ui->label_movimentos->text();
   ui->label_movimentos->setText(texto+"Defense\n");
   if(i==10){
       ui->pushButton_skill_atack_icon->setEnabled(false);
       ui->pushButton_skill_escudo_icon->setEnabled(false);
       ui->pushButton_skill_potion_icon->setEnabled(false);
   }
}

void pvp::on_pushButton_skill_potion_icon_clicked()
{
    i++;
   QString texto="";
   texto+= ui->label_movimentos->text();
   ui->label_movimentos->setText(texto+"Heal\n");
   if(i==10){
       ui->pushButton_skill_atack_icon->setEnabled(false);
       ui->pushButton_skill_escudo_icon->setEnabled(false);
       ui->pushButton_skill_potion_icon->setEnabled(false);
   }
}

void pvp::on_pushButton_limpar_clicked()
{
    i=0;
    ui->pushButton_skill_atack_icon->setEnabled(true);
    ui->pushButton_skill_escudo_icon->setEnabled(true);
    ui->pushButton_skill_potion_icon->setEnabled(true);
    ui->label_movimentos->clear();
}

void pvp::on_pushButton_Confirm_clicked()
{
    std::fstream arquivo;
    if(player==1)
        arquivo.open("player1.txt",std::fstream::out);
    else
        arquivo.open("player2.txt",std::fstream::out);
    if(character==1)
        arquivo<<"Warrior\n";
    else if(character==2)
        arquivo<<"Wizard\n";
    else
        arquivo<<"Assassin\n";
    arquivo<<ui->label_movimentos->text().toStdString();
    arquivo.close();
    //chamar prox janela
    setWindowTitle("fim");
    close();
}

void pvp::set_player(int player){
    this->player=player;
}

void pvp::limpar(){
    on_pushButton_limpar_clicked();
}
