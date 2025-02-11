/********************************************************************************
** Form generated from reading UI file 'resetpassword.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RESETPASSWORD_H
#define UI_RESETPASSWORD_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_ResetPassword
{
public:
    QLabel *label;
    QLineEdit *lineEditPassword;
    QPushButton *pushButtonConfirm;

    void setupUi(QDialog *ResetPassword)
    {
        if (ResetPassword->objectName().isEmpty())
            ResetPassword->setObjectName("ResetPassword");
        ResetPassword->resize(660, 470);
        label = new QLabel(ResetPassword);
        label->setObjectName("label");
        label->setGeometry(QRect(90, 140, 111, 20));
        lineEditPassword = new QLineEdit(ResetPassword);
        lineEditPassword->setObjectName("lineEditPassword");
        lineEditPassword->setGeometry(QRect(210, 140, 171, 26));
        lineEditPassword->setEchoMode(QLineEdit::EchoMode::Password);
        pushButtonConfirm = new QPushButton(ResetPassword);
        pushButtonConfirm->setObjectName("pushButtonConfirm");
        pushButtonConfirm->setGeometry(QRect(240, 300, 93, 29));

        retranslateUi(ResetPassword);

        QMetaObject::connectSlotsByName(ResetPassword);
    } // setupUi

    void retranslateUi(QDialog *ResetPassword)
    {
        ResetPassword->setWindowTitle(QCoreApplication::translate("ResetPassword", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("ResetPassword", "New Password:", nullptr));
        pushButtonConfirm->setText(QCoreApplication::translate("ResetPassword", "Confirm", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ResetPassword: public Ui_ResetPassword {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RESETPASSWORD_H
