#include "mainwindow.h"
#include "ui_mainwindow.h"

//variavel global da musica

//primeira musica \\Character_Screen_Music.wav
//MapTheme_Pontus_Ferrum                                    mais frenetica
//DungeonTheme_Volcanic_Citadel                             mais calma
//DungeonTheme_FrozenTower_of_Undead_B3F                    mais macabra
//MapTheme_NostalgicForest                                  mais feliz/conquista
QString caminho="C:\\Users\\Cleber\\Documents\\Compiladores\\Game\\";
QSound *music = new QSound(caminho+"Sounds\\CharacterScreen\\MapTheme_Pontus_Ferrum.wav");

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    player(1)
{
    ui->setupUi(this);

    //setando imagens dos personagens
    QPixmap assa(caminho+"IMG\\Blader.jpg");
    QPixmap warr(caminho+"IMG\\Warrior.jpg");
    QPixmap wiz(caminho+"IMG\\Wizard.jpg");
    ui->assassin->setPixmap(assa);
    ui->assassin->setGeometry(620,0,300,600);
    ui->warrior->setGeometry(0,0,300,600);
    ui->warrior->setPixmap(warr);
    ui->wizard->setGeometry(310,0,300,600);
    ui->wizard->setPixmap(wiz);

    //setando botoes
    QPixmap warr_btn(caminho+"IMG\\Char_btn_warrior.gif");
    QPixmap wiz_btn(caminho+"IMG\\Char_btn_wizard.gif");
    QPixmap assa_btn(caminho+"IMG\\Char_btn_blader.gif");
    ui->pushButton_warrior_btn->setIcon(warr_btn);
    ui->pushButton_assassin_btn->setIcon(assa_btn);
    ui->pushButton_wiz_btn->setIcon(wiz_btn);

    //iniciando musica
    music->setLoops(-1);//loop infinito
    music->play();

    setWindowTitle("Character Selection - Player0"+QString::number(player));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_warrior_btn_clicked()
{
    //this->setWindowTitle("Warrior Selected");
    warrior_selected_confirmation *window= new warrior_selected_confirmation(this);
    window->exec();
    if(window->windowTitle()==QString("selected")){
        //chamar nova mainwindow e esconder essa
        //parando a musica da tela de selecao
        //music->stop();
        pvp *arena= new pvp(this);
        this->setHidden(true);
        arena->character_selected(1);
        arena->set_player(player);
        arena->limpar();
        arena->exec();
        if(arena->windowTitle()==QString("fim")){
            this->setHidden(false);
            //player2
            player++;
            call_duelo();
        }
    }
}

void MainWindow::on_pushButton_wiz_btn_clicked()
{
    //this->setWindowTitle("Wizard Selected");
    wizard_selected_confirmation *window= new wizard_selected_confirmation(this);
    window->exec();
    if(window->windowTitle()==QString("selected")){
        //chamar nova mainwindow e esconder essa
        //parando a musica da tela de selecao
        //music->stop();
        pvp *arena= new pvp(this);
        this->setHidden(true);
        arena->character_selected(2);
        arena->set_player(player);
        arena->limpar();
        arena->exec();
        if(arena->windowTitle()==QString("fim")){
            this->setHidden(false);
            //player2
            player++;
            call_duelo();
        }
    }
}

void MainWindow::on_pushButton_assassin_btn_clicked()
{
    //this->setWindowTitle("Assassin Selected");
    assassin_selected_confirmation *window= new assassin_selected_confirmation(this);
    window->exec();
    if(window->windowTitle()==QString("selected")){
        //chamar nova mainwindow e esconder essa
        //parando a musica da tela de selecao
        //music->stop();
        pvp *arena= new pvp(this);
        this->setHidden(true);
        arena->character_selected(3);
        arena->set_player(player);
        arena->limpar();
        arena->exec();
        if(arena->windowTitle()==QString("fim")){
            this->setHidden(false);
            //player2
            player++;
            call_duelo();
        }
    }
}

void MainWindow::call_duelo(){
    setWindowTitle("Character Selection - Player0"+QString::number(player));
    if(player>=3){
        block_butons();
        music->stop();
        duelo *duelo_window = new duelo(this);
        duelo_window->start_timer_count();
        duelo_window->set_music();
        duelo_window->batalha();
        //duelo_window->showMaximized();
        duelo_window->setFocus();
        duelo_window->exec();
        player=1;
        block_butons();
        setWindowTitle("Character Selection - Player0"+QString::number(player));
        duelo_window->stopping_music();
        delete duelo_window;
    }
}

void MainWindow::block_butons(){
    if(ui->pushButton_warrior_btn->isEnabled() && ui->pushButton_wiz_btn->isEnabled() && ui->pushButton_assassin_btn->isEnabled()){
        ui->pushButton_warrior_btn->setEnabled(false);
        ui->pushButton_wiz_btn->setEnabled(false);
        ui->pushButton_assassin_btn->setEnabled(false);
    }
    else{
        ui->pushButton_warrior_btn->setEnabled(true);
        ui->pushButton_wiz_btn->setEnabled(true);
        ui->pushButton_assassin_btn->setEnabled(true);
    }
}
