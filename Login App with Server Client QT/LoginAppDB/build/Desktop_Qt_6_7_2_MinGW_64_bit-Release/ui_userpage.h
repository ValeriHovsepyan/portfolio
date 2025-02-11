/********************************************************************************
** Form generated from reading UI file 'userpage.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_USERPAGE_H
#define UI_USERPAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_UserPage
{
public:
    QLabel *label;
    QPushButton *LogOut;

    void setupUi(QDialog *UserPage)
    {
        if (UserPage->objectName().isEmpty())
            UserPage->setObjectName("UserPage");
        UserPage->resize(572, 390);
        label = new QLabel(UserPage);
        label->setObjectName("label");
        label->setGeometry(QRect(20, 10, 171, 20));
        LogOut = new QPushButton(UserPage);
        LogOut->setObjectName("LogOut");
        LogOut->setGeometry(QRect(200, 270, 93, 29));

        retranslateUi(UserPage);

        QMetaObject::connectSlotsByName(UserPage);
    } // setupUi

    void retranslateUi(QDialog *UserPage)
    {
        UserPage->setWindowTitle(QCoreApplication::translate("UserPage", "Dialog", nullptr));
        label->setText(QString());
        LogOut->setText(QCoreApplication::translate("UserPage", "Log out", nullptr));
    } // retranslateUi

};

namespace Ui {
    class UserPage: public Ui_UserPage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USERPAGE_H
