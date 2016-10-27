#ifndef MAINWINDOWDEVOLVENDO_H
#define MAINWINDOWDEVOLVENDO_H
#include <Locacaopersistencia.h>
#include <VeiculoPersistencia.h>
#include <Locacao.h>
#include <Veiculo.h>
#include <QMessageBox>
#include <QMainWindow>

namespace Ui {
class MainWindowDevolvendo;
}

class MainWindowDevolvendo : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindowDevolvendo(QWidget *parent = 0);
    ~MainWindowDevolvendo();
    void preencherCampos(projetoLocacao::Locacao obj);

private slots:
    void on_pushButtonDevolverLocacao_clicked();

private:
    Ui::MainWindowDevolvendo *ui;
    projetoLocacao::VeiculoPersistencia agendaDeVeiculo;
    projetoLocacao::LocacaoPersistencia agendaDeLocacao;
    projetoLocacao::Locacao objDevolver;
    //preciso do objDevolver para que nao haja necessidade de pesquisa-lo novamente
    //e quando eu o usei de outra forma tive problemas os quais nao consegui resolver de outra forma
};

#endif // MAINWINDOWDEVOLVENDO_H
