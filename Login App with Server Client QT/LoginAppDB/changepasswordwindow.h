#ifndef CHANGEPASSWORDWINDOW_H
#define CHANGEPASSWORDWINDOW_H

#include <QDialog>

namespace Ui {
class ChangePasswordWindow;
}

class ChangePasswordWindow : public QDialog
{
    Q_OBJECT

public:
    explicit ChangePasswordWindow(QWidget *parent = nullptr);
    ~ChangePasswordWindow();

private slots:
    void on_pushButtonNext_clicked();

private:
    Ui::ChangePasswordWindow *ui;
};

#endif // CHANGEPASSWORDWINDOW_H
