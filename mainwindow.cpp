#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QtNetwork>
#include <QtWidgets/QFileDialog>


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
    QString repoName = ui->tableWidget->selectedItems()[0]->text();
    networkManager.downloadRepository(&username, &repoName);
}

void MainWindow::on_findButton_clicked()
{
    QString username = ui->nameEdit->text();

    std::shared_ptr<QJsonDocument> repositoriesData = networkManager.getRepositoriesData(&username);
    if(repositoriesData != nullptr)
        setRepositoriesData(repositoriesData);

    std::shared_ptr<QJsonDocument> userData = networkManager.getUserData(&username);
    if(userData != nullptr)
        setUserData(userData);
}

void MainWindow::setRepositoriesData(std::shared_ptr<QJsonDocument> repositoriesData)
{
    QJsonArray repoArray = repositoriesData->array();
    int rowIndex = 0;
    QTableWidget* table = ui->tableWidget;
    table->clearContents();
    table->setRowCount(0);
    for(const QJsonValue &repoValue : repoArray) {
        QJsonObject repoObject = repoValue.toObject();
        QString repoName = repoObject["name"].toString();
        qDebug() << "Repository Name: " << repoName;

        QTableWidgetItem *itemName = new QTableWidgetItem(repoName);

        ui->tableWidget->insertRow(rowIndex);
        table->setItem(rowIndex, 0, itemName);
    }
}
void MainWindow::setUserData(std::shared_ptr<QJsonDocument> userData)
{
    QJsonObject jsonObject = userData->object();
    QString username = jsonObject["login"].toString();
    QString avatarUrl = jsonObject["avatar_url"].toString();
    QByteArray avatarByteArray = networkManager.getData(&avatarUrl)->toJson();
    QPixmap pixmap;
    pixmap.loadFromData(avatarByteArray);

    ui->username->setText(username);
    ui->avatar->setPixmap(pixmap);
}

