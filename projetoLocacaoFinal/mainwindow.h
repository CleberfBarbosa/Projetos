#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <mainwindowVeiculo.h>
#include <mainwindowNovoCliente.h>
#include <mainwindowGRIDCliente.h>
#include <mainwindowCliente.h>
#include <mainwindowLocacao.h>
#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButtonVeiculo_clicked();

    void on_pushButtonCliente_clicked();

    void on_pushButtonLocacao_clicked();

private:
    Ui::MainWindow *ui;
    MainWindowVeiculo irVeiculo;
    MainWindowCliente irCliente;
    MainWindowLocacao irLocacao;
};

#endif // MAINWINDOW_H
