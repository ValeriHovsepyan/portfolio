#ifndef SIGNINMENU_H
#define SIGNINMENU_H

#include <QDialog>

namespace Ui {
class SignInMenu;
}

class SignInMenu : public QDialog
{
    Q_OBJECT

public:
    explicit SignInMenu(QWidget *parent = nullptr);
    ~SignInMenu();

private slots:
    void on_pushButtonCOnfirm_clicked();

private:
    Ui::SignInMenu *ui;
};

#endif // SIGNINMENU_H
