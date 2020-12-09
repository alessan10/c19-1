/********************************************************************************
** Form generated from reading UI file 'elimina.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ELIMINA_H
#define UI_ELIMINA_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>

QT_BEGIN_NAMESPACE

class Ui_Elimina
{
public:
    QDialogButtonBox *buttonBox;
    QLineEdit *lineEdit;
    QLabel *label;

    void setupUi(QDialog *Elimina)
    {
        if (Elimina->objectName().isEmpty())
            Elimina->setObjectName(QString::fromUtf8("Elimina"));
        Elimina->resize(621, 485);
        buttonBox = new QDialogButtonBox(Elimina);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(260, 430, 341, 32));
        QFont font;
        font.setPointSize(12);
        buttonBox->setFont(font);
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        lineEdit = new QLineEdit(Elimina);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(120, 210, 371, 31));
        QFont font1;
        font1.setPointSize(14);
        lineEdit->setFont(font1);
        label = new QLabel(Elimina);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 50, 571, 101));
        QFont font2;
        font2.setPointSize(18);
        label->setFont(font2);

        retranslateUi(Elimina);
        QObject::connect(buttonBox, SIGNAL(accepted()), Elimina, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), Elimina, SLOT(reject()));

        QMetaObject::connectSlotsByName(Elimina);
    } // setupUi

    void retranslateUi(QDialog *Elimina)
    {
        Elimina->setWindowTitle(QCoreApplication::translate("Elimina", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("Elimina", "Inserisci Nome e Cognome del soggetto da eliminare:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Elimina: public Ui_Elimina {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ELIMINA_H
