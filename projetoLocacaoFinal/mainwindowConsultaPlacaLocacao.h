#ifndef MAINWINDOWCONSULTAPLACALOCACAO_H
#define MAINWINDOWCONSULTAPLACALOCACAO_H
#include <mainwindowConsultaLocacao.h>
#include <Locacaopersistencia.h>
#include <QMessageBox>
#include <QString>
#include <Locacao.h>
#include <QMainWindow>

namespace Ui {
class MainWindowConsultaPlacaLocacao;
}

class MainWindowConsultaPlacaLocacao : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindowConsultaPlacaLocacao(QWidget *parent = 0);
    ~MainWindowConsultaPlacaLocacao();

private slots:
    void on_pushButtonOk_clicked();

private:
    Ui::MainWindowConsultaPlacaLocacao *ui;
    MainWindowConsultaLocacao consultaLocacao;
    projetoLocacao::LocacaoPersistencia agendaDeLocacao;

};

#endif // MAINWINDOWCONSULTAPLACALOCACAO_H
