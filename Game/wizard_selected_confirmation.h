#ifndef WIZARD_SELECTED_CONFIRMATION_H
#define WIZARD_SELECTED_CONFIRMATION_H

#include <QDialog>

namespace Ui {
class wizard_selected_confirmation;
}

class wizard_selected_confirmation : public QDialog
{
    Q_OBJECT

public:
    explicit wizard_selected_confirmation(QWidget *parent = 0);
    ~wizard_selected_confirmation();

private slots:
    void on_pushButton_char_screen_2_clicked();

    void on_pushButton_confirm_wizard_clicked();

    void on_pushButton_skill_atack_icon_2_clicked();

    void on_pushButton_skill_escudo_icon_2_clicked();

    void on_pushButton_skill_potion_icon_2_clicked();

private:
    Ui::wizard_selected_confirmation *ui;
};

#endif // WIZARD_SELECTED_CONFIRMATION_H
