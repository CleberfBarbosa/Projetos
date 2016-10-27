#ifndef MAINWINDOWCLIENTE_H
#define MAINWINDOWCLIENTE_H
#include <mainwindowNovoCliente.h>
#include <QMainWindow>
#include<QMessageBox>
#include <Cliente.h>
#include <ClientePersistencia.h>
#include<mainwindowGRIDCliente.h>

namespace Ui {
class MainWindowCliente;
}

class MainWindowCliente : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindowCliente(QWidget *parent = 0);
    ~MainWindowCliente();

private slots:
    void on_pushButtonCadastrar_clicked();

    void on_pushButtonAlterar_clicked();

    void on_pushButtonExcluir_clicked();

    void on_pushButtonConsultar_clicked();

    void on_pushButtonListar_clicked();

private:
    Ui::MainWindowCliente *ui;
    MainWindowNovoCliente irNovoCliente;
    projetoLocacao::ClientePersistencia arquivoDeClientes;
    MainWindowGRIDCliente irListaDeClientes;
};

#endif // MAINWINDOWCLIENTE_H
