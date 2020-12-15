/********************************************************************************
** Form generated from reading UI file 'inserisci.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INSERISCI_H
#define UI_INSERISCI_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QRadioButton>

QT_BEGIN_NAMESPACE

class Ui_Inserisci
{
public:
    QDialogButtonBox *buttonBox;
    QLabel *label;
    QRadioButton *radioButton;
    QRadioButton *radioButton_2;
    QLabel *label_2;
    QLineEdit *lineEdit;

    void setupUi(QDialog *Inserisci)
    {
        if (Inserisci->objectName().isEmpty())
            Inserisci->setObjectName(QString::fromUtf8("Inserisci"));
        Inserisci->resize(739, 550);
        buttonBox = new QDialogButtonBox(Inserisci);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(370, 490, 341, 32));
        QFont font;
        font.setPointSize(12);
        buttonBox->setFont(font);
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        label = new QLabel(Inserisci);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(40, 90, 221, 31));
        QFont font1;
        font1.setPointSize(20);
        label->setFont(font1);
        radioButton = new QRadioButton(Inserisci);
        radioButton->setObjectName(QString::fromUtf8("radioButton"));
        radioButton->setGeometry(QRect(200, 330, 121, 41));
        radioButton->setFont(font1);
        radioButton_2 = new QRadioButton(Inserisci);
        radioButton_2->setObjectName(QString::fromUtf8("radioButton_2"));
        radioButton_2->setGeometry(QRect(400, 330, 131, 41));
        radioButton_2->setFont(font1);
        label_2 = new QLabel(Inserisci);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(50, 200, 511, 71));
        label_2->setFont(font1);
        lineEdit = new QLineEdit(Inserisci);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(310, 90, 401, 31));
        QFont font2;
        font2.setPointSize(14);
        lineEdit->setFont(font2);

        retranslateUi(Inserisci);
        QObject::connect(buttonBox, SIGNAL(accepted()), Inserisci, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), Inserisci, SLOT(reject()));

        QMetaObject::connectSlotsByName(Inserisci);
    } // setupUi

    void retranslateUi(QDialog *Inserisci)
    {
        Inserisci->setWindowTitle(QCoreApplication::translate("Inserisci", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("Inserisci", "Nome e Cognome:", nullptr));
        radioButton->setText(QCoreApplication::translate("Inserisci", "Positivo", nullptr));
        radioButton_2->setText(QCoreApplication::translate("Inserisci", "Negativo", nullptr));
        label_2->setText(QCoreApplication::translate("Inserisci", "Seleziona l'esito del tampone al COVID-19:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Inserisci: public Ui_Inserisci {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INSERISCI_H
