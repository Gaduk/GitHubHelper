/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.5.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QPushButton *saveButton;
    QTableWidget *tableWidget;
    QLabel *username;
    QPushButton *findButton;
    QLabel *label;
    QLineEdit *nameEdit;
    QLabel *avatar;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->setEnabled(true);
        MainWindow->resize(600, 400);
        MainWindow->setMinimumSize(QSize(600, 400));
        MainWindow->setMaximumSize(QSize(600, 400));
        MainWindow->setAcceptDrops(false);
        MainWindow->setUnifiedTitleAndToolBarOnMac(false);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName("gridLayout");
        saveButton = new QPushButton(centralwidget);
        saveButton->setObjectName("saveButton");
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(saveButton->sizePolicy().hasHeightForWidth());
        saveButton->setSizePolicy(sizePolicy);

        gridLayout->addWidget(saveButton, 12, 4, 1, 1);

        tableWidget = new QTableWidget(centralwidget);
        if (tableWidget->columnCount() < 1)
            tableWidget->setColumnCount(1);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        tableWidget->setObjectName("tableWidget");
        tableWidget->setEnabled(true);
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(tableWidget->sizePolicy().hasHeightForWidth());
        tableWidget->setSizePolicy(sizePolicy1);
        tableWidget->setLayoutDirection(Qt::LeftToRight);
        tableWidget->setAutoFillBackground(false);
        tableWidget->horizontalHeader()->setMinimumSectionSize(150);
        tableWidget->horizontalHeader()->setDefaultSectionSize(150);
        tableWidget->horizontalHeader()->setStretchLastSection(true);

        gridLayout->addWidget(tableWidget, 2, 1, 10, 4);

        username = new QLabel(centralwidget);
        username->setObjectName("username");
        username->setAlignment(Qt::AlignHCenter|Qt::AlignTop);

        gridLayout->addWidget(username, 3, 0, 1, 1);

        findButton = new QPushButton(centralwidget);
        findButton->setObjectName("findButton");
        sizePolicy.setHeightForWidth(findButton->sizePolicy().hasHeightForWidth());
        findButton->setSizePolicy(sizePolicy);

        gridLayout->addWidget(findButton, 12, 3, 1, 1);

        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label, 12, 0, 1, 1);

        nameEdit = new QLineEdit(centralwidget);
        nameEdit->setObjectName("nameEdit");

        gridLayout->addWidget(nameEdit, 12, 1, 1, 2);

        avatar = new QLabel(centralwidget);
        avatar->setObjectName("avatar");
        sizePolicy1.setHeightForWidth(avatar->sizePolicy().hasHeightForWidth());
        avatar->setSizePolicy(sizePolicy1);
        avatar->setMinimumSize(QSize(100, 0));
        avatar->setMaximumSize(QSize(64, 100));
        avatar->setBaseSize(QSize(0, 0));
        avatar->setPixmap(QPixmap(QString::fromUtf8(":/res/res/GitHubLogo.svg")));
        avatar->setScaledContents(true);

        gridLayout->addWidget(avatar, 2, 0, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 600, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        saveButton->setText(QCoreApplication::translate("MainWindow", "Save", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("MainWindow", "Repository name", nullptr));
        username->setText(QCoreApplication::translate("MainWindow", "User", nullptr));
        findButton->setText(QCoreApplication::translate("MainWindow", "Search", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "GitHub user name:", nullptr));
        avatar->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
