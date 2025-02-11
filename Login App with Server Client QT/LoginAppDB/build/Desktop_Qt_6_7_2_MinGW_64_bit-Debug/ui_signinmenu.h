/********************************************************************************
** Form generated from reading UI file 'signinmenu.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SIGNINMENU_H
#define UI_SIGNINMENU_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_SignInMenu
{
public:
    QGroupBox *groupBox;
    QLabel *Username;
    QLineEdit *lineEditUsername;
    QLabel *Password;
    QLineEdit *lineEditPassword;
    QPushButton *pushButtonCOnfirm;

    void setupUi(QDialog *SignInMenu)
    {
        if (SignInMenu->objectName().isEmpty())
            SignInMenu->setObjectName("SignInMenu");
        SignInMenu->resize(702, 486);
        groupBox = new QGroupBox(SignInMenu);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(190, 110, 261, 241));
        Username = new QLabel(groupBox);
        Username->setObjectName("Username");
        Username->setGeometry(QRect(20, 40, 81, 20));
        lineEditUsername = new QLineEdit(groupBox);
        lineEditUsername->setObjectName("lineEditUsername");
        lineEditUsername->setGeometry(QRect(102, 40, 151, 26));
        Password = new QLabel(groupBox);
        Password->setObjectName("Password");
        Password->setGeometry(QRect(20, 100, 71, 20));
        lineEditPassword = new QLineEdit(groupBox);
        lineEditPassword->setObjectName("lineEditPassword");
        lineEditPassword->setGeometry(QRect(100, 100, 151, 26));
        lineEditPassword->setEchoMode(QLineEdit::EchoMode::Password);
        pushButtonCOnfirm = new QPushButton(groupBox);
        pushButtonCOnfirm->setObjectName("pushButtonCOnfirm");
        pushButtonCOnfirm->setGeometry(QRect(90, 170, 93, 29));

        retranslateUi(SignInMenu);

        QMetaObject::connectSlotsByName(SignInMenu);
    } // setupUi

    void retranslateUi(QDialog *SignInMenu)
    {
        SignInMenu->setWindowTitle(QCoreApplication::translate("SignInMenu", "Dialog", nullptr));
        groupBox->setTitle(QCoreApplication::translate("SignInMenu", "SignIn", nullptr));
        Username->setText(QCoreApplication::translate("SignInMenu", "Username:", nullptr));
        Password->setText(QCoreApplication::translate("SignInMenu", "Password:", nullptr));
        pushButtonCOnfirm->setText(QCoreApplication::translate("SignInMenu", "Confirm", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SignInMenu: public Ui_SignInMenu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SIGNINMENU_H
