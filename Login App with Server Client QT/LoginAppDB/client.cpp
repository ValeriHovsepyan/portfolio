#include "client.h"
#include <QJsonDocument>
#include <QJsonObject>
#include <QDebug>
#include <QMessageBox>

Client::Client(QObject *parent)
    : QObject(parent),
    socket(new QTcpSocket(this))
{
    connect(socket, &QTcpSocket::errorOccurred, this, &Client::onErrorOccurred);
}

Client::~Client()
{
    if (socket->isOpen())
    {
        socket->disconnectFromHost();
    }
}

bool Client::connectToServer()
{
    socket->connectToHost("192.168.100.101", 12345);
    if (socket->waitForConnected(5000))
    {
        return true;
    }
    else
    {
        return false;
    }
}

void Client::sendRequest(QJsonObject Request)
{
    if (!socket->isOpen())
    {
        qDebug() << "Socket is not connected!";
        return;
    }

    QJsonDocument doc(Request);
    QByteArray requestData = doc.toJson();

    socket->write(requestData);
}

void Client::handleResponse(QJsonObject &ResponseJson)
{
    if (socket->waitForReadyRead(5000))
    {
        QByteArray Response = socket->readAll();

        QJsonParseError parseError;
        QJsonDocument doc = QJsonDocument::fromJson(Response, &parseError);
        if (parseError.error != QJsonParseError::NoError)
        {
            return;
        }

        ResponseJson = doc.object();
    }
}

Client &Client::getClass()
{
    static Client client;
    return client;
}

void Client::disconnect()
{
    if (socket->isOpen())
    {
        socket->disconnectFromHost();
    }
}

void Client::onErrorOccurred(QAbstractSocket::SocketError error)
{
    QMessageBox::critical(nullptr, "Error", "Socket error: " + socket->errorString());
}
