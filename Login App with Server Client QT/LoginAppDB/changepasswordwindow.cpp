#include "changepasswordwindow.h"
#include "ui_changepasswordwindow.h"
#include <QSqlDatabase>
#include <QtSql>
#include <QMessageBox>
#include "resetpassword.h"
#include "client.h"

ChangePasswordWindow::ChangePasswordWindow(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::ChangePasswordWindow)
{
    ui->setupUi(this);
}

ChangePasswordWindow::~ChangePasswordWindow()
{
    delete ui;
}

void ChangePasswordWindow::on_pushButtonNext_clicked()
{
    QString Username = ui->lineEditUsername->text();

    ui->lineEditUsername->setText("");

    Client& client = Client::getClass();

    client.connectToServer();

    QJsonObject request;

    request["username"] = Username;

    request["type"] = "changePassword";

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
            ResetPassword resetPassword;
            resetPassword.setUsername(Username);
            this->close();
            resetPassword.setModal(true);
            resetPassword.exec();
        }
        else
        {
            ui->lineEditUsername->setText("");
            QString message = "No such username " + Username;
            QMessageBox::warning(this, "SignIn", message);
        }
    }
}
