#ifndef MAINWINDOWLOCANDO_H
#define MAINWINDOWLOCANDO_H
#include <Veiculo.h>
#include <VeiculoPersistencia.h>
#include <Locacaopersistencia.h>
#include <QMessageBox>
#include <list>
#include <QMainWindow>

namespace Ui {
class MainWindowLocando;
}

class MainWindowLocando : public QMainWindow
{
    Q_OBJECT

public:
    void pegaCliente(QString nome); //aqui ele vai preencher alguns campos que nao devem ser alterados
    //e vai preencher a tablegrid
    explicit MainWindowLocando(QWidget *parent = 0);
    ~MainWindowLocando();

private slots:
    void on_pushButtonSalvarLocacao_clicked();

private:
    Ui::MainWindowLocando *ui;
    projetoLocacao::VeiculoPersistencia agendaDeVeiculo;
    projetoLocacao::LocacaoPersistencia agendaDeLocacao;
    QString nomeDado;//usei um atributo pq eu quero que depois que o usuario entre como o cpf
    //ele nao possa mudar o nome do cliente
};

#endif // MAINWINDOWLOCANDO_H
