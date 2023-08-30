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
    QString username = this->username;
    QList selectedItems = ui->tableWidget->selectedItems();
    if(!selectedItems.empty())
    {
        QString repoName = ui->tableWidget->selectedItems()[0]->text();
        networkManager.downloadRepository(username, repoName);
    }
}
void MainWindow::on_findButton_clicked()
{
    QString username = ui->nameEdit->text();
    this->username = username;

    std::shared_ptr<QByteArray> repositoriesData = networkManager.getRepositoriesData(username);
    if(repositoriesData != nullptr)
        setRepositoriesData(repositoriesData);
    else clearTable();

    std::shared_ptr<QByteArray> userData = networkManager.getUserData(username);
    if(userData != nullptr)
        setUserData(userData);
    else setDefaultUserData();
}

void MainWindow::setRepositoriesData(std::shared_ptr<QByteArray> repositoriesData)
{
    QJsonDocument jsonDocument = QJsonDocument::fromJson(*repositoriesData);
    QJsonArray repoArray = jsonDocument.array();
    int rowIndex = 0;
    QTableWidget* table = ui->tableWidget;
    clearTable();
    for(const QJsonValue &repoValue : repoArray) {
        QJsonObject repoObject = repoValue.toObject();
        QString repoName = repoObject["name"].toString();
        qDebug() << "Repository Name: " << repoName;

        QTableWidgetItem *itemName = new QTableWidgetItem(repoName);

        ui->tableWidget->insertRow(rowIndex);
        table->setItem(rowIndex, 0, itemName);
    }
}
void MainWindow::setUserData(std::shared_ptr<QByteArray> userData)
{
    QJsonDocument jsonDocument = QJsonDocument::fromJson(*userData);
    QJsonObject jsonObject = jsonDocument.object();
    QString username = jsonObject["login"].toString();
    QString avatarUrl = jsonObject["avatar_url"].toString();
    QByteArray avatarByteArray = *networkManager.getData(avatarUrl);
    QPixmap pixmap;
    pixmap.loadFromData(avatarByteArray);

    ui->username->setText(username);
    ui->avatar->setPixmap(pixmap);
}

void MainWindow::setDefaultUserData()
{
    ui->username->setText("User");
    QPixmap pixmap(":/res/res/GitHubLogo.svg");
    ui->avatar->setPixmap(pixmap);
}
void MainWindow::clearTable()
{
    ui->tableWidget->clearContents();
    ui->tableWidget->setRowCount(0);
}
