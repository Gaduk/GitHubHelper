#ifndef NETWORKMANAGER_H
#define NETWORKMANAGER_H

#include <QtNetwork>

class NetworkManager
{
public:
    NetworkManager();

    void downloadRepository(const QString* username, const QString* repoName);
    std::shared_ptr<QJsonDocument> getRepositoriesData(const QString* username);
    std::shared_ptr<QJsonDocument> getUserData(const QString* username);
    std::shared_ptr<QJsonDocument> getData(const QString *url);

private:
    QNetworkAccessManager networkAccessManager;

};

#endif // NETWORKMANAGER_H
