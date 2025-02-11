#include "server.h"
#include <QHostAddress>
#include <QJsonParseError>
#include <QSqlDatabase>
#include <QtSql>
#include <QMessageBox>

Server::Server(QObject *parent)
    : QTcpServer(parent)
{
}

void Server::startServer()
{
    this->listen(QHostAddress::Any, 12345);
}

void Server::incomingConnection(qintptr socketDescriptor)
{
    QTcpSocket *clientSocket = new QTcpSocket(this);
    if (clientSocket->setSocketDescriptor(socketDescriptor))
    {
        clients.append(clientSocket);
        connect(clientSocket, &QTcpSocket::readyRead, this, &Server::onReadyRead);
        connect(clientSocket, &QTcpSocket::disconnected, this, &Server::onDisconnected);
    }
    else
    {
        delete clientSocket;
    }
}

void Server::onReadyRead()
{
    QTcpSocket *clientSocket = qobject_cast<QTcpSocket *>(sender());
    if (!clientSocket) return;

    QByteArray requestData = clientSocket->readAll();

    QJsonParseError parseError;
    QJsonDocument doc = QJsonDocument::fromJson(requestData, &parseError);

    if (parseError.error != QJsonParseError::NoError)
    {
        return;
    }

    QJsonObject request = doc.object();
    QString type = request["type"].toString();

    QJsonObject response;

    if (type == "login")
    {
        response = login(request["password"].toString());
    }
    else if(type == "signIn")
    {
        signIn(request["password"].toString(), request["username"].toString(), response);
    }
    else if(type == "changePassword")
    {
        chagnePassword(request["username"].toString(), response);
    }
    else if(type == "setNewPassword")
    {
        setNewPassword(request["password"].toString(), request["username"].toString(), response);
    }
    sendResponse(clientSocket, response);
}

void Server::onDisconnected()
{
    QTcpSocket *clientSocket = qobject_cast<QTcpSocket *>(sender());
    if (!clientSocket) return;

    clients.removeAll(clientSocket);
    clientSocket->deleteLater();
}

void Server::sendResponse(QTcpSocket *clientSocket, const QJsonObject &response)
{
    QJsonDocument responseDoc(response);
    QByteArray responseData = responseDoc.toJson(QJsonDocument::Compact);
    clientSocket->write(responseData);
    clientSocket->flush();
}

QJsonObject Server::login(QString password)
{
    QJsonObject response;
    QSqlDatabase usersDb = QSqlDatabase::addDatabase("QSQLITE");
    usersDb.setDatabaseName("C:/Users/Valeri/Downloads/sqlite-tools-win-x64-3470200/LoginAppUsers.db");

    if (!usersDb.open())
    {
        return QJsonObject();
    }

    QSqlQuery findQuery;
    findQuery.prepare("SELECT username FROM users WHERE password = :Password");
    findQuery.bindValue(":Password", password);

    if (!findQuery.exec())
    {
        return QJsonObject();
    }

    if (findQuery.next())
    {
        response["status"] = "success";
        response["message"] = "Login successful!";
        response["type"] = "login";
    }
    else
    {
        response["status"] = "error";
        response["message"] = "Invalid username or password.";
    }

    return response;
}

void Server::setNewPassword(QString password, QString username, QJsonObject &response)
{
    QSqlDatabase usersDb = QSqlDatabase::addDatabase("QSQLITE");
    usersDb.setDatabaseName("C:/Users/Valeri/Downloads/sqlite-tools-win-x64-3470200/LoginAppUsers.db");

    if (!usersDb.open())
    {
        return;
    }

    QSqlQuery findQuery;
    findQuery.prepare("SELECT password FROM users WHERE password = :Password");
    findQuery.bindValue(":Password", password);

    if (!findQuery.exec())
    {
        return;
    }

    if(findQuery.next())
    {
        response["status"] = "error";
        response["message"] = "New password cannot coincide with old password";
    }
    else
    {
        QSqlQuery updateQuery;
        updateQuery.prepare("UPDATE users SET password = :Password WHERE username = :Username");
        updateQuery.bindValue(":Username", username);
        updateQuery.bindValue(":Password", password);

        if (!updateQuery.exec())
        {
            return;
        }

        response["status"] = "success";
        response["message"] = "Password changed for the accaunt + " + username;
        response["type"] = "resetPassword";

        usersDb.close();
    }
}

void Server::chagnePassword(QString username, QJsonObject &response)
{
    QSqlDatabase usersDb = QSqlDatabase::addDatabase("QSQLITE");
    usersDb.setDatabaseName("C:/Users/Valeri/Downloads/sqlite-tools-win-x64-3470200/LoginAppUsers.db");

    if (!usersDb.open())
    {
        return;
    }

    QSqlQuery findQuery;
    findQuery.prepare("SELECT username FROM users WHERE username = :Username");
    findQuery.bindValue(":Username", username);

    if (!findQuery.exec())
    {
        return;
    }

    if (findQuery.next())
    {
        response["status"] = "success";
        response["type"] = "chagnePassword";
    }
    else
    {
        response["status"] = "error";
        response["message"] = "No such user";
    }
}

void Server::signIn(QString password, QString username, QJsonObject &response)
{
    QSqlDatabase usersDb = QSqlDatabase::addDatabase("QSQLITE");
    usersDb.setDatabaseName("C:/Users/Valeri/Downloads/sqlite-tools-win-x64-3470200/LoginAppUsers.db");

    if (!usersDb.open())
    {
        return;
    }

    QSqlQuery findQuery;
    findQuery.prepare("SELECT username FROM users WHERE username = :Username");
    findQuery.bindValue(":Username", username);

    if (!findQuery.exec())
    {
        return;
    }
    if(findQuery.next())
    {
        response["status"] = "error";
        response["message"] = "User already exist";
    }
    else
    {
        QSqlQuery insertQuery;
        insertQuery.prepare("INSERT INTO users(username, password) VALUES (:Username, :Password)");
        insertQuery.bindValue(":Username", username);
        insertQuery.bindValue(":Password", password);

        if (!insertQuery.exec())
        {
            response["status"] = "error";
            response["message"] = "Falied tp register user";
        }
        else
        {
            QString message = username + " has been successfully registered.";

            response["status"] = "success";
            response["message"] = message;
            response["type"] = "signIn";
        }
    }
}
