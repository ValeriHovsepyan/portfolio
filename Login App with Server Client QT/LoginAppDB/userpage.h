#ifndef USERPAGE_H
#define USERPAGE_H

#include <QDialog>
#include "mainwindow.h"

namespace Ui {
class UserPage;
}

class UserPage : public QDialog
{
    Q_OBJECT

public:
    explicit UserPage(QWidget *parent = nullptr);
    ~UserPage();

    void setUsername(QString Username,  MainWindow* mainWindow);

private slots:
    void on_LogOut_clicked();

private:
    Ui::UserPage *ui;

    QString Username;

    MainWindow* mainWindow;
};

#endif // USERPAGE_H
