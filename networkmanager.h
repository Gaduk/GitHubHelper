#ifndef NETWORKMANAGER_H
#define NETWORKMANAGER_H

#include <QtNetwork>

class NetworkManager
{
public:
    NetworkManager();

    void downloadRepository(QString username, QString repoName);
    std::unique_ptr<QJsonDocument> getRepositoriesData(QString* username);
    std::unique_ptr<QJsonDocument> getUserData(QString* username);

private:
    QNetworkAccessManager networkAccessManager;
    std::unique_ptr<QJsonDocument> getData(QString *url);
};

#endif // NETWORKMANAGER_H
