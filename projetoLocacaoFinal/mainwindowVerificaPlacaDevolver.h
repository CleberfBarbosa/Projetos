#ifndef MAINWINDOWVERIFICAPLACADEVOLVER_H
#define MAINWINDOWVERIFICAPLACADEVOLVER_H
#include <mainwindowDevolvendo.h>
#include <QMessageBox>
#include <Locacaopersistencia.h>
#include <Locacao.h>
#include <QMainWindow>

namespace Ui {
class MainWindowVerificaPlacaDevolver;
}

class MainWindowVerificaPlacaDevolver : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindowVerificaPlacaDevolver(QWidget *parent = 0);
    ~MainWindowVerificaPlacaDevolver();

private slots:
    void on_pushButtonOk_clicked();

private:
    Ui::MainWindowVerificaPlacaDevolver *ui;
    MainWindowDevolvendo devolverVeiculo;
    projetoLocacao::LocacaoPersistencia agendaDeLocacao;//para verificar se a placa existe e se esta locada
};

#endif // MAINWINDOWVERIFICAPLACADEVOLVER_H
