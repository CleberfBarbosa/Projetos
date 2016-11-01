#include "warrior_selected_confirmation.h"
#include "ui_warrior_selected_confirmation.h"

warrior_selected_confirmation::warrior_selected_confirmation(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::warrior_selected_confirmation)
{
    ui->setupUi(this);

    QString caminho="C:\\Users\\Cleber\\Documents\\Compiladores\\Game\\";

    QPixmap warr(caminho+"IMG\\Warrior(-50%).jpg");
    QPixmap warr_icon(caminho+"IMG\\Char_btn_warrior(-50%).gif");
    ui->warrior_img->setPixmap(warr);
    ui->warrior_icon->setPixmap(warr_icon);

    //setando skills icon
    QPixmap skill_atack(caminho+"IMG\\atack.png");
    QPixmap skill_escudo(caminho+"IMG\\escudo.png");
    QPixmap skill_potion(caminho+"IMG\\potion.png");
    ui->pushButton_skill_atack_icon->setIcon(skill_atack);
    ui->pushButton_skill_escudo_icon->setIcon(skill_escudo);
    ui->pushButton_skill_potion_icon->setIcon(skill_potion);

    //limpando label skills descriptions
    limpar_labels();
}

warrior_selected_confirmation::~warrior_selected_confirmation()
{
    delete ui;
}

void warrior_selected_confirmation::on_pushButton_skill_atack_icon_clicked()
{
    limpar_labels();
    ui->skill_description->setText("<html><head/><body><p align='center'><span style= 'font-size:18pt; color:#ffffff;'>"
                                         "Rising Shot - Attack Skill</span></p><p><span style=' font-size:14pt; color:#ffffff;'>"
                                         "Swing a sword upward to make a </span></p><p><span style=' font-size:14pt; color:#ffffff;'>"
                                         "target lose its balance.</span></p></body></html>");
}

void warrior_selected_confirmation::on_pushButton_skill_escudo_icon_clicked()
{
    limpar_labels();
    ui->skill_description->setText("<html><head/><body><p align='center'><span style=' font-size:18pt; color:#ffffff;'>"
                                   "Iron Skin - Protection Skill</span></p><p align='justify'><span style=' font-size:14pt; "
                                   "color:#ffffff;'>Increase one's defense with the </span></p><p align='justify'><span "
                                   "style=' font-size:14pt; color:#ffffff;'>force. Strengthen Body</span></p></body></html>");
}

void warrior_selected_confirmation::on_pushButton_skill_potion_icon_clicked()
{
    limpar_labels();
    ui->skill_description->setText("<html><head/><body><p align='center'><span style=' font-size:18pt; color:#ffffff;'>"
                                   "HP Potion</span></p><p align='justify'><span style=' font-size:14pt; "
                                   "color:#ffffff;'>Restore an amount of Health</span></p><p align='justify'><span "
                                   "style=' font-size:14pt; color:#ffffff;'>Points</span></p></body></html>");
}

void warrior_selected_confirmation::limpar_labels(){
    ui->skill_description->setText("");
}

void warrior_selected_confirmation::on_pushButton_char_screen_clicked()
{
    this->close();
}

void warrior_selected_confirmation::on_pushButton_confirm_warrior_clicked()
{
    this->setWindowTitle("selected");
    close();
}
