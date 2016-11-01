#include "wizard_selected_confirmation.h"
#include "ui_wizard_selected_confirmation.h"

wizard_selected_confirmation::wizard_selected_confirmation(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::wizard_selected_confirmation)
{
    ui->setupUi(this);

    QString caminho="C:\\Users\\Cleber\\Documents\\Compiladores\\Game\\";

    QPixmap wiz(caminho+"IMG\\Wizard(-50%).jpg");
    QPixmap wiz_icon(caminho+"IMG\\Char_btn_wizard(-50%).gif");
    ui->wizard_img->setPixmap(wiz);
    ui->wizard_icon->setPixmap(wiz_icon);

    //setando skills icon
    QPixmap skill_atack(caminho+"IMG\\Fire_Blast_icon.png");
    QPixmap skill_escudo(caminho+"IMG\\Spirit_Intension_icon.png");
    QPixmap skill_potion(caminho+"IMG\\Mass_Heal_icon.png");
    ui->pushButton_skill_atack_icon_2->setIcon(skill_atack);
    ui->pushButton_skill_escudo_icon_2->setIcon(skill_escudo);
    ui->pushButton_skill_potion_icon_2->setIcon(skill_potion);

    ui->skill_description->setText("");
}

wizard_selected_confirmation::~wizard_selected_confirmation()
{
    delete ui;
}

void wizard_selected_confirmation::on_pushButton_char_screen_2_clicked()
{
    this->close();
}

void wizard_selected_confirmation::on_pushButton_confirm_wizard_clicked()
{
    setWindowTitle("selected");
    close();
}

void wizard_selected_confirmation::on_pushButton_skill_atack_icon_2_clicked()
{
    ui->skill_description->setText("<html><head/><body><p align='center'><span style= 'font-size:18pt; color:#ffffff;'>"
                                   "Fire Blast - Attack Skill</span></p><p><span style=' font-size:14pt; color:#ffffff;'>"
                                   "Summon a spirit of the fire to </span></p><p><span style=' font-size:14pt; "
                                   "color:#ffffff;'>attack a target.</span></p></body></html>");
}

void wizard_selected_confirmation::on_pushButton_skill_escudo_icon_2_clicked()
{
    ui->skill_description->setText("<html><head/><body><p align='center'><span style=' font-size:14pt; color:#ffffff;'>"
                                   "Spirit Intension - Protection Skill</span></p><p><span style='font-size:12pt; "
                                   "color:#ffffff;'>Reinforce the defense strength and </span></p><p><span style=' "
                                   "font-size:12pt; color:#ffffff;'>increase your immunity to attacks."
                                   "</span></p></body></html>");
}

void wizard_selected_confirmation::on_pushButton_skill_potion_icon_2_clicked()
{
    ui->skill_description->setText("<html><head/><body><p align='center'><span style= 'font-size:18pt; color:#ffffff;'>"
                                   "Mass Heal - Heal Skill</span></p><p><span style=' font-size:14pt; color:#ffffff;'>"
                                   "Restore an amount of Health </span></p><p><span style=' font-size:14pt; "
                                   "color:#ffffff;'>Points.</span></p></body></html>");
}
