#include "resetpassword.h"
#include "ui_resetpassword.h"
#include <QSqlDatabase>
#include <QtSql>
#include <QMessageBox>
#include "mainwindow.h"
#include "client.h"

ResetPassword::ResetPassword(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::ResetPassword)
{
    ui->setupUi(this);
}

ResetPassword::~ResetPassword()
{
    delete ui;
}

void ResetPassword::setUsername(QString Username)
{
    this->Username = Username;
}

void ResetPassword::on_pushButtonConfirm_clicked()
{
    Password = ui->lineEditPassword->text();
    ui->lineEditPassword->setText("");

    Client& client = Client::getClass();

    client.connectToServer();

    QJsonObject request;

    request["username"] = Username;

    request["password"] = Password;

    request["type"] = "setNewPassword";

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
            QMessageBox* msgBox = new QMessageBox(this);
            msgBox->setWindowTitle("Change Password");
            msgBox->setText("Password successfully changed for the account " + Username);
            msgBox->setIcon(QMessageBox::Information);

            connect(msgBox, &QMessageBox::finished, this, [this](int) {
                MainWindow* mainWindow = new MainWindow();
                mainWindow->show();
                this->close();
            });

            msgBox->show();
        }
        else
        {
            QMessageBox::warning(this, "Change Password", "New password cannot coincide with old password");
        }
    }
}

