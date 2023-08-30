#include "networkmanager.h"
#include <QtWidgets/QFileDialog>


NetworkManager::NetworkManager()
{

}

bool NetworkManager::downloadRepository(const QString& username, const QString& repoName)
{
    QString savePath = QFileDialog::getSaveFileName(nullptr, "Save", repoName, "ZIP Files (*.zip)");

    if(!savePath.isEmpty()) {
        QString url = "https://api.github.com/repos/" + username + "/" + repoName + "/zipball";
        QByteArray data = *getData(url); //скачивает только ветку main

        QFile file(savePath);
        if (file.open(QIODevice::WriteOnly))
        {
            file.write(data); // Запись данных архива в файл
            file.close();
            qDebug() << "Archive is saved at " << savePath;
            return true;
        }
        else
        {
            qDebug() << "Error: file is not saved";
        }
    }
    return false;
}
std::shared_ptr<QByteArray> NetworkManager::getRepositoriesData(const QString& username)
{
    QString url = "https://api.github.com/users/" + username + "/repos";
    return getData(url);
}
std::shared_ptr<QByteArray> NetworkManager::getUserData(const QString& username)
{
    QString url = "https://api.github.com/users/" + username;
    return getData(url);
}
std::shared_ptr<QByteArray> NetworkManager::getData(const QString& url)
{
    std::shared_ptr<QByteArray>data;

    QNetworkRequest request(url);

    QNetworkReply *reply = networkAccessManager.get(request);
    QEventLoop loop;
    QObject::connect(reply, &QNetworkReply::finished, &loop, &QEventLoop::quit);
    loop.exec();
    if (reply->error() == QNetworkReply::NoError)
    {
        QByteArray responseData = reply->readAll();
        data = std::make_shared<QByteArray>(responseData);
    }
    else qDebug() << "Error: " << reply->errorString();
    reply->deleteLater();
    return data;
}
