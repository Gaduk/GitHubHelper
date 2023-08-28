#ifndef NETWORKMANAGER_H
#define NETWORKMANAGER_H

#include <QtNetwork>

class NetworkManager
{
public:
    NetworkManager();

    bool downloadRepository(const QString& username, const QString& repoName);
    std::shared_ptr<QByteArray> getRepositoriesData(const QString& username);
    std::shared_ptr<QByteArray> getUserData(const QString& username);
    std::shared_ptr<QByteArray> getData(const QString& url);

private:
    QNetworkAccessManager networkAccessManager;

};

#endif // NETWORKMANAGER_H
