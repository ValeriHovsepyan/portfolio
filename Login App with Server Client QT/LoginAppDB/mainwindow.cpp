#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "signinmenu.h"
#include <QSqlDatabase>
#include <QtSql>
#include <QMessageBox>
#include "userpage.h"
#include "changepasswordwindow.h"
#include <QJsonDocument>
#include <QJsonObject>
#include "client.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButtonSignIn_clicked()
{
    SignInMenu signInWindow;
    signInWindow.setModal(true);
    signInWindow.exec();
}


void MainWindow::on_pushButtonLogin_clicked()
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

    request["type"] = "login";

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
            UserPage userPage;
            this->close();
            userPage.setUsername(Username, this);
            userPage.setModal(true);
            userPage.exec();
        }
        else
        {
            QMessageBox::warning(this, "LogIn", message);
        }
    }
    else
    {
        QMessageBox::warning(this, "LogIn", "Failed to login for accaunt " + Username);
    }
}

void MainWindow::on_pushButtonChangePassword_clicked()
{
    ui->lineEditUsername->setText("");
    ui->lineEditPassword->setText("");
    ChangePasswordWindow changePasswordWindow;
    this->close();
    changePasswordWindow.setModal(true);
    changePasswordWindow.exec();
}
