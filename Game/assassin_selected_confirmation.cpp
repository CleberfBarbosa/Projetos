#include "assassin_selected_confirmation.h"
#include "ui_assassin_selected_confirmation.h"

assassin_selected_confirmation::assassin_selected_confirmation(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::assassin_selected_confirmation)
{
    QString caminho="C:\\Users\\Cleber\\Documents\\Compiladores\\Game\\";
    ui->setupUi(this);

    QPixmap assa(caminho+"IMG\\Blader(-50%).jpg");
    QPixmap assa_icon(caminho+"IMG\\Char_btn_blader(-50%).gif");
    ui->assassin_img->setPixmap(assa);
    ui->assassin_icon->setPixmap(assa_icon);

    //setando skills icon
    QPixmap skill_atack(caminho+"IMG\\Twin_Moon_Slash_icon.png");
    QPixmap skill_escudo(caminho+"IMG\\Intuition_icon.png");
    QPixmap skill_potion(caminho+"IMG\\potion.png");
    ui->pushButton_skill_atack_icon->setIcon(skill_atack);
    ui->pushButton_skill_escudo_icon->setIcon(skill_escudo);
    ui->pushButton_skill_potion_icon->setIcon(skill_potion);
}

assassin_selected_confirmation::~assassin_selected_confirmation()
{
    delete ui;
}

void assassin_selected_confirmation::on_pushButton_skill_atack_icon_clicked()
{
    ui->skill_description->setText("<html><head/><body><p align='center'><span style= 'font-size:16pt; color:#ffffff;'>"
                                   "Twin Moon Slash - Attack Skill</span></p><p><span style=' font-size:14pt; color:#ffffff;'>"
                                   "Twin moons from dual swords </span></p><p><span style=' font-size:14pt; "
                                   "color:#ffffff;'>that bring death to their target.</span></p></body></html>");
}

void assassin_selected_confirmation::on_pushButton_skill_escudo_icon_clicked()
{
    ui->skill_description->setText("<html><head/><body><p align='center'><span style= 'font-size:18pt; color:#ffffff;'>"
                                   "Intuition - Evasive Skill</span></p><p><span style=' font-size:14pt; color:#ffffff;'>"
                                   "Improve your intuition, and </span></p><p><span style=' font-size:14pt; "
                                   "color:#ffffff;'>increase the perfect evasion rate.</span></p></body></html>");
}

void assassin_selected_confirmation::on_pushButton_skill_potion_icon_clicked()
{
    ui->skill_description->setText("<html><head/><body><p align='center'><span style=' font-size:18pt; color:#ffffff;'>"
                                   "HP Potion</span></p><p align='justify'><span style=' font-size:14pt; "
                                   "color:#ffffff;'>Restore an amount of Health</span></p><p align='justify'><span "
                                   "style=' font-size:14pt; color:#ffffff;'>Points</span></p></body></html>");
}

void assassin_selected_confirmation::on_pushButton_char_screen_clicked()
{
    this->close();
}

void assassin_selected_confirmation::on_pushButton_confirm_warrior_clicked()
{
    setWindowTitle("selected");
    close();
}
