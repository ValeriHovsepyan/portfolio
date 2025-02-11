#ifndef CLIENT_H
#define CLIENT_H

#include <QTcpSocket>
#include <QJsonObject>
#include <QObject>

class Client : public QObject
{
    Q_OBJECT

private:
    explicit Client(QObject *parent = nullptr);
public:
    ~Client();

    bool connectToServer();

    void sendRequest(QJsonObject Request);

    void handleResponse(QJsonObject &ResponseJson);

    static Client& getClass();

    void disconnect();

    Client& operator=(const Client& other) = delete;
    Client& operator=(const Client&& other) = delete;

    Client(const Client& other) = delete;
    Client(const Client&& other) = delete;

private slots:
    void onErrorOccurred(QAbstractSocket::SocketError error);

private:
    QTcpSocket *socket;
};

#endif // CLIENT_H
