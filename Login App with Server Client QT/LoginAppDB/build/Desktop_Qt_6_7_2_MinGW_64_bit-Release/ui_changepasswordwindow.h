/********************************************************************************
** Form generated from reading UI file 'changepasswordwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHANGEPASSWORDWINDOW_H
#define UI_CHANGEPASSWORDWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_ChangePasswordWindow
{
public:
    QLabel *label;
    QLineEdit *lineEditUsername;
    QPushButton *pushButtonNext;

    void setupUi(QDialog *ChangePasswordWindow)
    {
        if (ChangePasswordWindow->objectName().isEmpty())
            ChangePasswordWindow->setObjectName("ChangePasswordWindow");
        ChangePasswordWindow->resize(601, 481);
        label = new QLabel(ChangePasswordWindow);
        label->setObjectName("label");
        label->setGeometry(QRect(130, 120, 141, 41));
        lineEditUsername = new QLineEdit(ChangePasswordWindow);
        lineEditUsername->setObjectName("lineEditUsername");
        lineEditUsername->setGeometry(QRect(280, 130, 171, 26));
        pushButtonNext = new QPushButton(ChangePasswordWindow);
        pushButtonNext->setObjectName("pushButtonNext");
        pushButtonNext->setGeometry(QRect(240, 360, 93, 29));

        retranslateUi(ChangePasswordWindow);

        QMetaObject::connectSlotsByName(ChangePasswordWindow);
    } // setupUi

    void retranslateUi(QDialog *ChangePasswordWindow)
    {
        ChangePasswordWindow->setWindowTitle(QCoreApplication::translate("ChangePasswordWindow", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("ChangePasswordWindow", "Enter your username:", nullptr));
        pushButtonNext->setText(QCoreApplication::translate("ChangePasswordWindow", "Next", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ChangePasswordWindow: public Ui_ChangePasswordWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHANGEPASSWORDWINDOW_H
