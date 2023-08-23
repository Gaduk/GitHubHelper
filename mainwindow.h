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
};
#endif // MAINWINDOW_H
