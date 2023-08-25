#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "networkmanager.h"
#include <QMainWindow>
#include <QtNetwork>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_saveButton_clicked();
    void on_findButton_clicked();

private:
    Ui::MainWindow *ui;
    NetworkManager networkManager;

    void setRepositoriesData(std::shared_ptr<QJsonDocument> repositoriesData);
    void setUserData(std::shared_ptr<QJsonDocument> userData);



};
#endif // MAINWINDOW_H
