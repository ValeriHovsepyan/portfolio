#include "mainwindow.h"
#include <QApplication>
#include <QTcpServer>
#include <QTcpSocket>
#include <QJsonDocument>
#include <QJsonObject>
#include <QMessageBox>
#include "server.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Server server;
    server.startServer();
    return a.exec();
}
