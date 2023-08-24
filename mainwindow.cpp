#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QtNetwork>
#include <QtWidgets/QFileDialog>
#include <qgithubapi.h>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableWidget->setSelectionMode(QAbstractItemView::SingleSelection);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_saveButton_clicked()
{
    QString username = ui->nameEdit->text();
    QList<QTableWidgetItem*> selectedItems = ui->tableWidget->selectedItems();

    if(!selectedItems.isEmpty())
    {
        QString repoName = selectedItems[0]->text();
        download_repository(username, repoName);
    }
}

void MainWindow::on_findButton_clicked()
{
    QString username = ui->nameEdit->text();
    set_repository_list(get_repository_list(username));
    //set_user_data(get_user_data(username));
}

void MainWindow::download_repository(QString username, QString repoName)
{
    QString savePath = QFileDialog::getSaveFileName(nullptr, "Save", repoName, "ZIP Files (*.zip)");

    if(!savePath.isEmpty()) {
        QUrl url("https://api.github.com/repos/" + username + "/"+ repoName + "/zipball"); //скачивает только ветку main
        QNetworkRequest request(url);
        QNetworkReply *reply = networkManager.get(request);
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
void MainWindow::set_repository_list(QJsonArray repositories_data)
{
    int rowIndex = 0;
    QTableWidget* table = ui->tableWidget;
    table->clearContents();
    table->setRowCount(0);
    for (const QJsonValue &repoValue : repositories_data) {
        QJsonObject repoObject = repoValue.toObject();
        QString repoName = repoObject["name"].toString();
        qDebug() << "Repository Name: " << repoName;

        QTableWidgetItem *itemName = new QTableWidgetItem(repoName);
        table->insertRow(rowIndex);
        table->setItem(rowIndex, 0, itemName);
    }
}
void MainWindow::set_user_data(QJsonArray user_data)
{

}
QJsonArray MainWindow::get_repository_list(QString username)
{
    QUrl url("https://api.github.com/users/" + username + "/repos");
    return get_data(url);

}
QJsonArray MainWindow::get_user_data(QString username)
{
    QUrl url("https://api.github.com/users/" + username);
    return get_data(url);
}
QJsonArray MainWindow::get_data(QUrl url)
{
    QNetworkRequest request(url);

    QString accessToken = "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";
    request.setRawHeader("Authorization", ("Bearer " + accessToken).toUtf8());

    QNetworkReply *reply = networkManager.get(request);
    QJsonArray json_array;
    QObject::connect(reply, &QNetworkReply::finished, [=, &json_array]() {
        if(reply->error() == QNetworkReply::NoError) {
            QByteArray responseData = reply->readAll();
            QJsonDocument jsonDoc = QJsonDocument::fromJson(responseData);
            json_array = jsonDoc.array();
        }
        else qDebug() << "Error: " << reply->errorString();
        reply->deleteLater();
    });
    return json_array;
}


