#ifndef MAINWINDOWGRIDCLIENTE_H
#define MAINWINDOWGRIDCLIENTE_H
#include <ClientePersistencia.h>
#include <Cliente.h>
#include <CRUDCliente.h>
#include <fstream>
#include <QMainWindow>
#include <QMessageBox>

#include <QMainWindow>

namespace Ui {
class MainWindowGRIDCliente;
}

class MainWindowGRIDCliente : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindowGRIDCliente(QWidget *parent = 0);
    ~MainWindowGRIDCliente();
    void listar(); //Funcao da listagem de Clientes
    void consultarCliente(projetoLocacao::Cliente objeto); //Funcao de consulta de Clientes
    
private:
    Ui::MainWindowGRIDCliente *ui;
    projetoLocacao::ClientePersistencia arquivoDeClientes;
};

#endif // MAINWINDOWGRIDCLIENTE_H
