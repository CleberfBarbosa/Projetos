#ifndef PVP_H
#define PVP_H

#include <QDialog>
#include <QSound>
#include <stdlib.h>
#include <time.h>
#include <QTimer>
#include <fstream>
#include <personagem.h>

namespace Ui {
class pvp;
}

class pvp : public QDialog
{
    Q_OBJECT

public:
    explicit pvp(QWidget *parent = 0);
    ~pvp();
    void character_selected(int character);
    void set_music();
    void set_player(int player);
    void limpar();

private slots:

    void music_end();

    void on_pushButton_skill_atack_icon_clicked();

    void on_pushButton_skill_escudo_icon_clicked();

    void on_pushButton_skill_potion_icon_clicked();

    void on_pushButton_limpar_clicked();

    void on_pushButton_Confirm_clicked();



private:
    Ui::pvp *ui;
    int i;
    QSound music_pvp;
    QTimer* timer;
    QString caminho;
    int character;
    int player;
    Personagem *aux;
};

#endif // PVP_H
