#ifndef SERVER_H
#define SERVER_H

#include <QTcpServer>
#include <QTcpSocket>
#include <QJsonObject>
#include <QJsonDocument>
#include <QObject>

class Server : public QTcpServer
{
    Q_OBJECT

public:
    explicit Server(QObject *parent = nullptr);
    void startServer();

protected:
    void incomingConnection(qintptr socketDescriptor) override;

private slots:
    void onReadyRead();
    void onDisconnected();
    void sendResponse(QTcpSocket *clientSocket, const QJsonObject &response);

private:
    QList<QTcpSocket *> clients;

    QJsonObject login(QString password);

    void setNewPassword(QString password, QString username, QJsonObject& response);

    void chagnePassword(QString username, QJsonObject& response);

    void signIn(QString password, QString username, QJsonObject& response);
};

#endif // SERVER_H
