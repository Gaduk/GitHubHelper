#include "networkmanager.h"
#include <QtWidgets/QFileDialog>


NetworkManager::NetworkManager()
{

}

void NetworkManager::downloadRepository(const QString* username, const QString* repoName)
{
    QString savePath = QFileDialog::getSaveFileName(nullptr, "Save", *repoName, "ZIP Files (*.zip)");

    if(!savePath.isEmpty()) {
        QUrl url("https://api.github.com/repos/" + *username + "/" + *repoName + "/zipball"); //скачивает только ветку main
        QNetworkRequest request(url);
        QNetworkReply *reply = networkAccessManager.get(request);
        QObject::connect(reply, &QNetworkReply::finished, [=]() {
            if (reply->error() == QNetworkReply::NoError) {
                QFile file(savePath);
                if (file.open(QIODevice::WriteOnly)) {
                    file.write(reply->readAll()); // Запись данных архива в файл
                    file.close();
                    qDebug() << "Archive is saved at " << savePath;
                }
                else qDebug() << "Error: file is not saved";
            }
            else qDebug() << "Error: " << reply->errorString();
        });
    }
}
std::shared_ptr<QJsonDocument> NetworkManager::getRepositoriesData(const QString* username)
{
    QString url = "https://api.github.com/users/" + *username + "/repos";
    return getData(&url);
}
std::shared_ptr<QJsonDocument> NetworkManager::getUserData(const QString* username)
{
    QString url = "https://api.github.com/users/" + *username;
    return getData(&url);
}
std::shared_ptr<QJsonDocument> NetworkManager::getData(const QString* url)
{
    std::shared_ptr<QJsonDocument>data;

    QNetworkRequest request(*url);

    QString accessToken = "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";
    request.setRawHeader("Authorization", ("Bearer " + accessToken).toUtf8());

    QNetworkReply *reply = networkAccessManager.get(request);
    QEventLoop loop;
    QObject::connect(reply, &QNetworkReply::finished, &loop, &QEventLoop::quit);
    loop.exec();
    if (reply->error() == QNetworkReply::NoError) {
        QByteArray responseData = reply->readAll();
        QJsonDocument jsonDocument = QJsonDocument::fromJson(responseData);
        data = std::make_unique<QJsonDocument>(jsonDocument);
    }
    else qDebug() << "Error: " << reply->errorString();
    reply->deleteLater();
    return data;
}
