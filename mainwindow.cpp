#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QtNetwork>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_saveButton_clicked()
{

}

void MainWindow::on_findButton_clicked()
{
    // Никнейм пользователя на GitHub
    QString username = ui->nameEdit->text();

    // Создание URL для запроса к API GitHub
    QUrl url("https://api.github.com/users/" + username + "/repos");

    // Выполнение GET-запроса к API GitHub
    QNetworkRequest request(url);

    QString accessToken = "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";
    request.setRawHeader("Authorization", ("Bearer " + accessToken).toUtf8());

    QNetworkReply *reply = networkManager.get(request);

    // Обработка ответа на запрос
    QObject::connect(reply, &QNetworkReply::finished, [=]() {
        if (reply->error() == QNetworkReply::NoError) {
            // Обработка данных JSON из ответа
            QByteArray responseData = reply->readAll();
            QJsonDocument jsonDoc = QJsonDocument::fromJson(responseData);
            if (jsonDoc.isArray()) {
                QJsonArray repoArray = jsonDoc.array();
                int rowIndex = 0;
                QTableWidget* table = ui->tableWidget;
                table->clearContents();
                table->setRowCount(0);
                foreach (const QJsonValue &repoValue, repoArray) {
                    QJsonObject repoObject = repoValue.toObject();
                    QString repoName = repoObject["name"].toString();
                    qDebug() << "Repository Name: " << repoName;

                    QTableWidgetItem *itemName = new QTableWidgetItem(repoName);

                    ui->tableWidget->insertRow(rowIndex);
                    table->setItem(rowIndex, 0, itemName);
                }
            }
        } else {
            qDebug() << "Error: " << reply->errorString();
        }
        reply->deleteLater();
    });
}

