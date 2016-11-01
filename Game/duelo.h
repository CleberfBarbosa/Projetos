#ifndef DUELO_H
#define DUELO_H

#include <QDialog>
#include <stdlib.h>
#include <time.h>
#include <QSound>
#include <QTimer>
#include <fstream>
#include <QMessageBox>
#include <personagem.h>
#include <unistd.h>
#include <windows.h>
#include <stdio.h>

namespace Ui {
class duelo;
}

class duelo : public QDialog
{
    Q_OBJECT

public:
    explicit duelo(QWidget *parent = 0);
    ~duelo();
    void set_music();
    void start_timer_count();
    void stopping_music();
    void lendoArquivo();
    void gerandoTela();
    void batalha();
    void setandoProgressBar();
    void verificaVencedor();

    void ataqueSemDefesa(Personagem *atacante, Personagem *vitima);
    void ataqueComDefesa(Personagem *atacante,Personagem *defensor);
    void defesa(Personagem *defensor);
    void cura(Personagem *curando);

private slots:
    void music_end();
    void current_time();


    void on_pushButtonProximaRodada_clicked();

private:
    Personagem *player1, *player2;
    Ui::duelo *ui;
    QTimer *timer;
    QTimer *curr_timer;
    QString caminho;
    QSound music;
    int hor,min,seg;
    bool controle = false;
};

#endif // DUELO_H
