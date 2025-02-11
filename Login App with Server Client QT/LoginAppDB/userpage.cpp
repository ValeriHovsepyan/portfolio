#include "userpage.h"
#include "ui_userpage.h"


UserPage::UserPage(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::UserPage)
{
    ui->setupUi(this);
}

UserPage::~UserPage()
{
    delete ui;
}

void UserPage::setUsername(QString Username,  MainWindow* mainWindow)
{
    this->mainWindow = mainWindow;
    this->mainWindow->close();
    this->Username = Username;
    this->ui->label->setText("User: " + this->Username);
}

void UserPage::on_LogOut_clicked()
{
    this->mainWindow->show();
    this->close();
}
