#ifndef MAINWINDOWVALIDACPF_H
#define MAINWINDOWVALIDACPF_H
#include <mainwindowLocando.h>
#include <ClientePersistencia.h>
#include <QMainWindow>

namespace Ui {
class MainWindowValidaCpf;
}

class MainWindowValidaCpf : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindowValidaCpf(QWidget *parent = 0);
    ~MainWindowValidaCpf();

private slots:
    void on_pushButtonOk_clicked();

private:
    Ui::MainWindowValidaCpf *ui;
    MainWindowLocando locandoVeiculo;
    projetoLocacao::ClientePersistencia arquivoDeClientes;//para verificar se o usuario existe
};

#endif // MAINWINDOWVALIDACPF_H
