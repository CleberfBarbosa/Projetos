#ifndef WARRIOR_SELECTED_CONFIRMATION_H
#define WARRIOR_SELECTED_CONFIRMATION_H

#include <QDialog>

namespace Ui {
class warrior_selected_confirmation;
}

class warrior_selected_confirmation : public QDialog
{
    Q_OBJECT

public:
    explicit warrior_selected_confirmation(QWidget *parent = 0);
    ~warrior_selected_confirmation();
    void limpar_labels();

private slots:
    void on_pushButton_skill_atack_icon_clicked();

    void on_pushButton_skill_escudo_icon_clicked();

    void on_pushButton_skill_potion_icon_clicked();

    void on_pushButton_char_screen_clicked();

    void on_pushButton_confirm_warrior_clicked();

private:
    Ui::warrior_selected_confirmation *ui;
};

#endif // WARRIOR_SELECTED_CONFIRMATION_H
