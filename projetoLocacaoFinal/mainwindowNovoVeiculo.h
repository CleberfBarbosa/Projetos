#ifndef MAINWINDOWNOVOVEICULO_H
#define MAINWINDOWNOVOVEICULO_H
#include <Veiculo.h>
#include <VeiculoPersistencia.h>
#include <QMainWindow>
#include <QString>
namespace Ui {
class MainWindowNovoVeiculo;
}

class MainWindowNovoVeiculo : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindowNovoVeiculo(QWidget *parent = 0);
    ~MainWindowNovoVeiculo();

private slots:
    void on_pushButtonSalvarVeiculo_clicked();

    void on_checkBoxDisponivel_clicked(bool checked);

private:
    Ui::MainWindowNovoVeiculo *ui;
    projetoLocacao::VeiculoPersistencia agendaVeiculos;//é necessario usar esse objeto pois vou precisar
    bool situacaoDoVeiculo;
    //utilizei um atributo booleano para pode usar o checkbox pois nao conheço outra forma para utiliza-lo

};

#endif // MAINWINDOWNOVOVEICULO_H
