#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWindow w;
    w.resize(500, 300);
    w.setWindowTitle("GitHub Helper");
    w.setWindowIcon(QIcon(":/res/res/GitHubLogo.jpg"));
    w.show();




    return a.exec();
}
