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
    //download_repository();
}

void MainWindow::on_findButton_clicked()
{
    QString username = ui->nameEdit->text();
    setRepositoriesData(networkManager.getRepositoriesData(&username));
    //set_user_data(get_user_data(&username));
}

void MainWindow::setRepositoriesData(std::unique_ptr<QJsonDocument> repositoriesData) {
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


