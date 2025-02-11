#ifndef RESETPASSWORD_H
#define RESETPASSWORD_H

#include <QDialog>

namespace Ui {
class ResetPassword;
}

class ResetPassword : public QDialog
{
    Q_OBJECT

public:
    explicit ResetPassword(QWidget *parent = nullptr);
    ~ResetPassword();

    void setUsername(QString Username);

private slots:
    void on_pushButtonConfirm_clicked();

private:
    Ui::ResetPassword *ui;

    QString Username;

    QString Password;
};

#endif // RESETPASSWORD_H
