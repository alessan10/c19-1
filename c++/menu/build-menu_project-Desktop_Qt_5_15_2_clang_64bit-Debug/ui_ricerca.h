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
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>

QT_BEGIN_NAMESPACE

class Ui_Ricerca
{
public:
    QDialogButtonBox *buttonBox;
    QLabel *label;
    QLineEdit *lineEdit;

    void setupUi(QDialog *Ricerca)
    {
        if (Ricerca->objectName().isEmpty())
            Ricerca->setObjectName(QString::fromUtf8("Ricerca"));
        Ricerca->resize(679, 468);
        buttonBox = new QDialogButtonBox(Ricerca);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(310, 410, 341, 32));
        QFont font;
        font.setPointSize(12);
        buttonBox->setFont(font);
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        label = new QLabel(Ricerca);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(140, 80, 381, 101));
        QFont font1;
        font1.setPointSize(20);
        label->setFont(font1);
        lineEdit = new QLineEdit(Ricerca);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(150, 190, 351, 41));
        QFont font2;
        font2.setPointSize(14);
        lineEdit->setFont(font2);

        retranslateUi(Ricerca);
        QObject::connect(buttonBox, SIGNAL(accepted()), Ricerca, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), Ricerca, SLOT(reject()));

        QMetaObject::connectSlotsByName(Ricerca);
    } // setupUi

    void retranslateUi(QDialog *Ricerca)
    {
        Ricerca->setWindowTitle(QCoreApplication::translate("Ricerca", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("Ricerca", "Ricerca per Nome e Cognome:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Ricerca: public Ui_Ricerca {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RICERCA_H
