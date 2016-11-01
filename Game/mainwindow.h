#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSound>
#include <warrior_selected_confirmation.h>
#include <wizard_selected_confirmation.h>
#include <assassin_selected_confirmation.h>
#include <selecao_mov.h>
#include <duelo.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void block_butons();

private slots:
    void on_pushButton_warrior_btn_clicked();

    void on_pushButton_wiz_btn_clicked();

    void on_pushButton_assassin_btn_clicked();

    void call_duelo();

private:
    Ui::MainWindow *ui;
    int player;
};

#endif // MAINWINDOW_H
