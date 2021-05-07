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
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
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
    QPushButton *pushButton;
    QLabel *label_3;
    QListWidget *listWidget;
    QLabel *label_2;
    QPushButton *button_elimina;

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
        font.setPointSize(14);
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
        nome->setFont(font);
        nome->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(nome);

        cognome = new QLineEdit(Ricerca);
        cognome->setObjectName(QString::fromUtf8("cognome"));
        cognome->setFont(font);
        cognome->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(cognome);


        verticalLayout_2->addLayout(horizontalLayout_2);

        pushButton = new QPushButton(Ricerca);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setFont(font);

        verticalLayout_2->addWidget(pushButton);

        label_3 = new QLabel(Ricerca);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setFont(font);
        label_3->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(label_3);

        listWidget = new QListWidget(Ricerca);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));
        QSizePolicy sizePolicy1(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(listWidget->sizePolicy().hasHeightForWidth());
        listWidget->setSizePolicy(sizePolicy1);

        verticalLayout_2->addWidget(listWidget);

        label_2 = new QLabel(Ricerca);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setFont(font);
        label_2->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(label_2);

        button_elimina = new QPushButton(Ricerca);
        button_elimina->setObjectName(QString::fromUtf8("button_elimina"));
        button_elimina->setFont(font);

        verticalLayout_2->addWidget(button_elimina);


        retranslateUi(Ricerca);

        QMetaObject::connectSlotsByName(Ricerca);
    } // setupUi

    void retranslateUi(QDialog *Ricerca)
    {
        Ricerca->setWindowTitle(QCoreApplication::translate("Ricerca", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("Ricerca", "Per cercare i contatti di un soggetto, digita il suo nome e il suo cognome nel box sottostante!", nullptr));
        nome->setPlaceholderText(QCoreApplication::translate("Ricerca", "Nome", nullptr));
        cognome->setPlaceholderText(QCoreApplication::translate("Ricerca", "Cognome", nullptr));
        pushButton->setText(QCoreApplication::translate("Ricerca", "Cerca", nullptr));
        label_3->setText(QCoreApplication::translate("Ricerca", "Il soggetto cercato risulta essere entrato in contatto con i seguenti nominativi:", nullptr));
        label_2->setText(QCoreApplication::translate("Ricerca", "Per eliminare il soggetto cercato, clicca su Elimina", nullptr));
        button_elimina->setText(QCoreApplication::translate("Ricerca", "Elimina", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Ricerca: public Ui_Ricerca {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RICERCA_H
