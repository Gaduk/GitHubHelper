#ifndef MAINWINDOW_H
#define MAINWINDOW_H

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
    // Создание объекта для выполнения HTTP-запросов
    QNetworkAccessManager networkManager;

    void download_repository(QString username, QString repoName);
    void set_repository_list(QJsonArray repositories_data);
    void set_user_data(QJsonArray user_data);

    QJsonArray get_data(QUrl url);
    QJsonArray get_repository_list(QString username);
    QJsonArray get_user_data(QString username);

};
#endif // MAINWINDOW_H
