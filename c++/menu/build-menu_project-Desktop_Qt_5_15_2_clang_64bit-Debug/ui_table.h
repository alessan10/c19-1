/********************************************************************************
** Form generated from reading UI file 'table.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TABLE_H
#define UI_TABLE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_Table
{
public:
    QVBoxLayout *verticalLayout;
    QTableView *tableView;
    QPushButton *pushButton;

    void setupUi(QDialog *Table)
    {
        if (Table->objectName().isEmpty())
            Table->setObjectName(QString::fromUtf8("Table"));
        Table->resize(400, 300);
        verticalLayout = new QVBoxLayout(Table);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        tableView = new QTableView(Table);
        tableView->setObjectName(QString::fromUtf8("tableView"));

        verticalLayout->addWidget(tableView);

        pushButton = new QPushButton(Table);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        verticalLayout->addWidget(pushButton);


        retranslateUi(Table);

        QMetaObject::connectSlotsByName(Table);
    } // setupUi

    void retranslateUi(QDialog *Table)
    {
        Table->setWindowTitle(QCoreApplication::translate("Table", "Dialog", nullptr));
        pushButton->setText(QCoreApplication::translate("Table", "Visualizza/Aggiorna", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Table: public Ui_Table {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TABLE_H
