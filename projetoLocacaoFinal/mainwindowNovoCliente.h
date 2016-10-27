#ifndef MAINWINDOWNOVOCLIENTE_H
#define MAINWINDOWNOVOCLIENTE_H
#include<QMessageBox>
#include <Cliente.h>
#include <ClientePersistencia.h>

#include <QMainWindow>

namespace Ui {
class MainWindowNovoCliente;
}

class MainWindowNovoCliente : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindowNovoCliente(QWidget *parent = 0);
    ~MainWindowNovoCliente();

private slots:
    void on_pushButtonSalvar_clicked();

    void on_pushButtonCancelar_clicked();

private:
    Ui::MainWindowNovoCliente *ui;
    projetoLocacao::ClientePersistencia arquivoDeClientes;
};

#endif // MAINWINDOWNOVOCLIENTE_H
