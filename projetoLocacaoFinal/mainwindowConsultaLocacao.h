#ifndef MAINWINDOWCONSULTALOCACAO_H
#define MAINWINDOWCONSULTALOCACAO_H
#include <Locacao.h>
#include <QMessageBox>
#include <QString>
#include <QMainWindow>

namespace Ui {
class MainWindowConsultaLocacao;
}

class MainWindowConsultaLocacao : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindowConsultaLocacao(QWidget *parent = 0);
    ~MainWindowConsultaLocacao();
    void preencheDadosVeiculo(projetoLocacao::Locacao objLocacao);//preciso para preencher o dados do objeto
    //essa função será chamada em outra classe

private:
    Ui::MainWindowConsultaLocacao *ui;
};

#endif // MAINWINDOWCONSULTALOCACAO_H
