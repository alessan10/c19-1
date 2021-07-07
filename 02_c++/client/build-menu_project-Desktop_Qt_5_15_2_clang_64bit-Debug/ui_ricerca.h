/********************************************************************************
** Form generated from reading UI file 'ricerca.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RICERCA_H
#define UI_RICERCA_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_Ricerca
{
public:
    QVBoxLayout *verticalLayout_2;
    QLabel *label;
    QHBoxLayout *horizontalLayout_2;
    QLineEdit *nome;
    QLineEdit *cognome;
    QPushButton *searchButton;
    QSpacerItem *verticalSpacer;
    QLabel *label_3;
    QTableWidget *table;
    QSpacerItem *verticalSpacer_2;
    QLabel *label_2;
    QPushButton *deleteButton;
    QSpacerItem *verticalSpacer_3;

    void setupUi(QDialog *Ricerca)
    {
        if (Ricerca->objectName().isEmpty())
            Ricerca->setObjectName(QString::fromUtf8("Ricerca"));
        Ricerca->resize(1019, 642);
        verticalLayout_2 = new QVBoxLayout(Ricerca);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        label = new QLabel(Ricerca);
        label->setObjectName(QString::fromUtf8("label"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);
        QFont font;
        font.setPointSize(12);
        label->setFont(font);
        label->setLayoutDirection(Qt::LeftToRight);
        label->setTextFormat(Qt::AutoText);
        label->setAlignment(Qt::AlignCenter);
        label->setMargin(0);

        verticalLayout_2->addWidget(label);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        nome = new QLineEdit(Ricerca);
        nome->setObjectName(QString::fromUtf8("nome"));
        QFont font1;
        font1.setPointSize(14);
        nome->setFont(font1);
        nome->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(nome);

        cognome = new QLineEdit(Ricerca);
        cognome->setObjectName(QString::fromUtf8("cognome"));
        cognome->setFont(font1);
        cognome->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(cognome);


        verticalLayout_2->addLayout(horizontalLayout_2);

        searchButton = new QPushButton(Ricerca);
        searchButton->setObjectName(QString::fromUtf8("searchButton"));
        searchButton->setFont(font1);

        verticalLayout_2->addWidget(searchButton);

        verticalSpacer = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        verticalLayout_2->addItem(verticalSpacer);

        label_3 = new QLabel(Ricerca);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setFont(font);
        label_3->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(label_3);

        table = new QTableWidget(Ricerca);
        table->setObjectName(QString::fromUtf8("table"));

        verticalLayout_2->addWidget(table);

        verticalSpacer_2 = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        verticalLayout_2->addItem(verticalSpacer_2);

        label_2 = new QLabel(Ricerca);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setFont(font);
        label_2->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(label_2);

        deleteButton = new QPushButton(Ricerca);
        deleteButton->setObjectName(QString::fromUtf8("deleteButton"));
        deleteButton->setFont(font1);

        verticalLayout_2->addWidget(deleteButton);

        verticalSpacer_3 = new QSpacerItem(20, 10, QSizePolicy::Minimum, QSizePolicy::Minimum);

        verticalLayout_2->addItem(verticalSpacer_3);


        retranslateUi(Ricerca);

        QMetaObject::connectSlotsByName(Ricerca);
    } // setupUi

    void retranslateUi(QDialog *Ricerca)
    {
        Ricerca->setWindowTitle(QCoreApplication::translate("Ricerca", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("Ricerca", "Per cercare i contatti di un soggetto, digita il suo nome e il suo cognome nel box sottostante!", nullptr));
        nome->setPlaceholderText(QCoreApplication::translate("Ricerca", "Nome", nullptr));
        cognome->setPlaceholderText(QCoreApplication::translate("Ricerca", "Cognome", nullptr));
        searchButton->setText(QCoreApplication::translate("Ricerca", "Cerca", nullptr));
        label_3->setText(QCoreApplication::translate("Ricerca", "Il soggetto cercato risulta essere entrato in contatto con:", nullptr));
        label_2->setText(QCoreApplication::translate("Ricerca", "Per eliminare il soggetto cercato, clicca su Elimina", nullptr));
        deleteButton->setText(QCoreApplication::translate("Ricerca", "Elimina", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Ricerca: public Ui_Ricerca {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RICERCA_H
