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
    QAction *actionAbout_Our_Project;
    QAction *actionExit;
    QAction *actionVisualizza_Database;
    QAction *actionVisualizza_Statistiche;
    QAction *actionModifica_Dati_Paziente;
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLabel *label_2;
    QMenuBar *menubar;
    QMenu *menuOperazioni;
    QMenu *menuHelp;
    QMenu *menuModifica;
    QMenu *menuModifica_2;
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
        actionAbout_Our_Project = new QAction(MainWindow);
        actionAbout_Our_Project->setObjectName(QString::fromUtf8("actionAbout_Our_Project"));
        actionExit = new QAction(MainWindow);
        actionExit->setObjectName(QString::fromUtf8("actionExit"));
        actionVisualizza_Database = new QAction(MainWindow);
        actionVisualizza_Database->setObjectName(QString::fromUtf8("actionVisualizza_Database"));
        actionVisualizza_Statistiche = new QAction(MainWindow);
        actionVisualizza_Statistiche->setObjectName(QString::fromUtf8("actionVisualizza_Statistiche"));
        actionModifica_Dati_Paziente = new QAction(MainWindow);
        actionModifica_Dati_Paziente->setObjectName(QString::fromUtf8("actionModifica_Dati_Paziente"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setAlignment(Qt::AlignHCenter|Qt::AlignTop);

        verticalLayout->addWidget(label);

        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        QFont font;
        font.setPointSize(14);
        label_2->setFont(font);
        label_2->setAlignment(Qt::AlignCenter);
        label_2->setMargin(0);

        verticalLayout->addWidget(label_2);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 903, 21));
        menuOperazioni = new QMenu(menubar);
        menuOperazioni->setObjectName(QString::fromUtf8("menuOperazioni"));
        menuHelp = new QMenu(menubar);
        menuHelp->setObjectName(QString::fromUtf8("menuHelp"));
        menuModifica = new QMenu(menubar);
        menuModifica->setObjectName(QString::fromUtf8("menuModifica"));
        menuModifica_2 = new QMenu(menubar);
        menuModifica_2->setObjectName(QString::fromUtf8("menuModifica_2"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuOperazioni->menuAction());
        menubar->addAction(menuModifica_2->menuAction());
        menubar->addAction(menuModifica->menuAction());
        menubar->addAction(menuHelp->menuAction());
        menuOperazioni->addAction(actioninserisci);
        menuOperazioni->addAction(actionRicerca);
        menuOperazioni->addSeparator();
        menuOperazioni->addAction(actionExit);
        menuHelp->addAction(actionAbout_Our_Project);
        menuModifica->addAction(actionVisualizza_Database);
        menuModifica->addAction(actionVisualizza_Statistiche);
        menuModifica_2->addAction(actionModifica_Dati_Paziente);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        actioninserisci->setText(QCoreApplication::translate("MainWindow", "Inserisci", nullptr));
        actionRicerca->setText(QCoreApplication::translate("MainWindow", "Ricerca/Elimina", nullptr));
        actionAbout_Our_Project->setText(QCoreApplication::translate("MainWindow", "About Our Project", nullptr));
        actionExit->setText(QCoreApplication::translate("MainWindow", "Exit", nullptr));
        actionVisualizza_Database->setText(QCoreApplication::translate("MainWindow", "Visualizza Database", nullptr));
        actionVisualizza_Statistiche->setText(QCoreApplication::translate("MainWindow", "Visualizza Statistiche", nullptr));
        actionModifica_Dati_Paziente->setText(QCoreApplication::translate("MainWindow", "Modifica Dati Paziente", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Clicca in alto a sinistra su File e seleziona un'operazione per iniziare!", nullptr));
        menuOperazioni->setTitle(QCoreApplication::translate("MainWindow", "File", nullptr));
        menuHelp->setTitle(QCoreApplication::translate("MainWindow", "Help", nullptr));
        menuModifica->setTitle(QCoreApplication::translate("MainWindow", "Visualizza", nullptr));
        menuModifica_2->setTitle(QCoreApplication::translate("MainWindow", "Modifica", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
