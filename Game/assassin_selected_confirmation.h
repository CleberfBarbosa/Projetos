#ifndef ASSASSIN_SELECTED_CONFIRMATION_H
#define ASSASSIN_SELECTED_CONFIRMATION_H

#include <QDialog>

namespace Ui {
class assassin_selected_confirmation;
}

class assassin_selected_confirmation : public QDialog
{
    Q_OBJECT

public:
    explicit assassin_selected_confirmation(QWidget *parent = 0);
    ~assassin_selected_confirmation();

private slots:
    void on_pushButton_skill_atack_icon_clicked();

    void on_pushButton_skill_escudo_icon_clicked();

    void on_pushButton_skill_potion_icon_clicked();

    void on_pushButton_char_screen_clicked();

    void on_pushButton_confirm_warrior_clicked();

private:
    Ui::assassin_selected_confirmation *ui;
};

#endif // ASSASSIN_SELECTED_CONFIRMATION_H
