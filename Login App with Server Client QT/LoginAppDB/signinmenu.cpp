#include "signinmenu.h"
#include "ui_signinmenu.h"
#include <QSqlDatabase>
#include <QtSql>
#include <QMessageBox>
#include "mainwindow.h"
#include "client.h"

SignInMenu::SignInMenu(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::SignInMenu)
{
    ui->setupUi(this);
}

SignInMenu::~SignInMenu()
{
    delete ui;
}

void SignInMenu::on_pushButtonCOnfirm_clicked()
{
    QString Username = ui->lineEditUsername->text();
    QString Password = ui->lineEditPassword->text();

    ui->lineEditUsername->setText("");
    ui->lineEditPassword->setText("");

    Client& client = Client::getClass();

    client.connectToServer();

    QJsonObject request;

    request["username"] = Username;

    request["password"] = Password;

    request["type"] = "signIn";

    client.sendRequest(request);

    QJsonObject response;

    client.handleResponse(response);

    client.disconnect();

    if (response.contains("status"))
    {
        QString status = response["status"].toString();
        QString message = response["message"].toString();

        if (status == "success")
        {
            QString message = Username + " has been successfully registered.";
            QMessageBox::information(this, "SignIn", message);

            MainWindow mainWindow;
            mainWindow.show();

            this->close();
        }
        else
        {
            QMessageBox::critical(this, "SignIn", "Failed to register the user.");
        }
    }
}


