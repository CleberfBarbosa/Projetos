#ifndef MAINWINDOWLOCACAO_H
#define MAINWINDOWLOCACAO_H
#include <mainwindowValidaCpf.h>
#include <mainwindowVerificaPlacaDevolver.h>
#include <mainwindowConsultaPlacaLocacao.h>
#include <mainwindowGridLocacao.h>
#include <QMainWindow>

namespace Ui {
class MainWindowLocacao;
}

class MainWindowLocacao : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindowLocacao(QWidget *parent = 0);
    ~MainWindowLocacao();

private slots:
    void on_pushButtonLocar_clicked();

    void on_pushButtonDevolver_clicked();

    void on_pushButtonConsultarLocacao_clicked();

    void on_pushButtonListarLocacao_clicked();

private:
    Ui::MainWindowLocacao *ui;
    MainWindowValidaCpf validaCpf;
    MainWindowVerificaPlacaDevolver validaPlaca;
    MainWindowConsultaPlacaLocacao consultaPlaca;
    MainWindowGridLocacao irGridLocacao;
};

#endif // MAINWINDOWLOCACAO_H
