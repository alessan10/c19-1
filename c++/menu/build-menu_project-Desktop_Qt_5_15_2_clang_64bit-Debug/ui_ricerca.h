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
    QLineEdit *name;
    QLineEdit *surname;
    QPushButton *pushButton;
    QListWidget *listWidget;

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
        name = new QLineEdit(Ricerca);
        name->setObjectName(QString::fromUtf8("name"));
        name->setFont(font);
        name->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(name);

        surname = new QLineEdit(Ricerca);
        surname->setObjectName(QString::fromUtf8("surname"));
        surname->setFont(font);
        surname->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(surname);


        verticalLayout_2->addLayout(horizontalLayout_2);

        pushButton = new QPushButton(Ricerca);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setFont(font);

        verticalLayout_2->addWidget(pushButton);

        listWidget = new QListWidget(Ricerca);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));
        QSizePolicy sizePolicy1(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(listWidget->sizePolicy().hasHeightForWidth());
        listWidget->setSizePolicy(sizePolicy1);

        verticalLayout_2->addWidget(listWidget);


        retranslateUi(Ricerca);

        QMetaObject::connectSlotsByName(Ricerca);
    } // setupUi

    void retranslateUi(QDialog *Ricerca)
    {
        Ricerca->setWindowTitle(QCoreApplication::translate("Ricerca", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("Ricerca", "Per cercare i contatti di un soggetto, digita il suo nome e il suo cognome nel box sottostante!", nullptr));
        name->setPlaceholderText(QCoreApplication::translate("Ricerca", "Nome", nullptr));
        surname->setPlaceholderText(QCoreApplication::translate("Ricerca", "Cognome", nullptr));
        pushButton->setText(QCoreApplication::translate("Ricerca", "Cerca", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Ricerca: public Ui_Ricerca {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RICERCA_H
