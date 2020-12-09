/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actioninserisci;
    QAction *actionRicerca;
    QAction *actionElimina;
    QAction *actionAbout_Our_Project;
    QAction *actionExit;
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label;
    QMenuBar *menubar;
    QMenu *menuOperazioni;
    QMenu *menuHelp;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(903, 646);
        actioninserisci = new QAction(MainWindow);
        actioninserisci->setObjectName(QString::fromUtf8("actioninserisci"));
        actionRicerca = new QAction(MainWindow);
        actionRicerca->setObjectName(QString::fromUtf8("actionRicerca"));
        actionElimina = new QAction(MainWindow);
        actionElimina->setObjectName(QString::fromUtf8("actionElimina"));
        actionAbout_Our_Project = new QAction(MainWindow);
        actionAbout_Our_Project->setObjectName(QString::fromUtf8("actionAbout_Our_Project"));
        actionExit = new QAction(MainWindow);
        actionExit->setObjectName(QString::fromUtf8("actionExit"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setPixmap(QPixmap(QString::fromUtf8("C:/Users/alexm/Desktop/page-GraphDatabase1.png")));
        label_2->setAlignment(Qt::AlignHCenter|Qt::AlignTop);
        label_2->setMargin(-100);

        verticalLayout->addWidget(label_2);

        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        QFont font;
        font.setPointSize(20);
        label_3->setFont(font);

        verticalLayout->addWidget(label_3);

        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout->addWidget(label);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 903, 21));
        menuOperazioni = new QMenu(menubar);
        menuOperazioni->setObjectName(QString::fromUtf8("menuOperazioni"));
        menuHelp = new QMenu(menubar);
        menuHelp->setObjectName(QString::fromUtf8("menuHelp"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuOperazioni->menuAction());
        menubar->addAction(menuHelp->menuAction());
        menuOperazioni->addAction(actioninserisci);
        menuOperazioni->addAction(actionRicerca);
        menuOperazioni->addAction(actionElimina);
        menuOperazioni->addSeparator();
        menuOperazioni->addAction(actionExit);
        menuHelp->addAction(actionAbout_Our_Project);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        actioninserisci->setText(QCoreApplication::translate("MainWindow", "Inserisci", nullptr));
        actionRicerca->setText(QCoreApplication::translate("MainWindow", "Ricerca", nullptr));
        actionElimina->setText(QCoreApplication::translate("MainWindow", "Elimina", nullptr));
        actionAbout_Our_Project->setText(QCoreApplication::translate("MainWindow", "About Our Project", nullptr));
        actionExit->setText(QCoreApplication::translate("MainWindow", "Exit", nullptr));
        label_2->setText(QString());
        label_3->setText(QCoreApplication::translate("MainWindow", "Benvenuto nel programma di gestione.......", nullptr));
        label->setText(QString());
        menuOperazioni->setTitle(QCoreApplication::translate("MainWindow", "File", nullptr));
        menuHelp->setTitle(QCoreApplication::translate("MainWindow", "Help", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
