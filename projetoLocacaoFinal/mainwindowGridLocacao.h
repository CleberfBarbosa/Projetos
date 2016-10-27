#ifndef MAINWINDOWGRIDLOCACAO_H
#define MAINWINDOWGRIDLOCACAO_H
#include <Locacaopersistencia.h>
#include <Locacao.h>
#include <QMainWindow>

namespace Ui {
class MainWindowGridLocacao;
}

class MainWindowGridLocacao : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindowGridLocacao(QWidget *parent = 0);
    ~MainWindowGridLocacao();
    void mostrarGrid();//essa função será chamada em outra classe e serve para preencher e mostrar a grid

private:
    Ui::MainWindowGridLocacao *ui;
    projetoLocacao::LocacaoPersistencia agendaDeLocacao; //preciso dele pois vou usar a funçao de listagem
};

#endif // MAINWINDOWGRIDLOCACAO_H
