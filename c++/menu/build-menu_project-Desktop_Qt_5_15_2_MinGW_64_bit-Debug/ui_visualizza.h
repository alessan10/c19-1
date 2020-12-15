/********************************************************************************
** Form generated from reading UI file 'visualizza.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VISUALIZZA_H
#define UI_VISUALIZZA_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Visualizza
{
public:
    QDialogButtonBox *buttonBox;
    QLabel *label;
    QPushButton *pushButton;
    QLabel *label_2;

    void setupUi(QDialog *Visualizza)
    {
        if (Visualizza->objectName().isEmpty())
            Visualizza->setObjectName(QString::fromUtf8("Visualizza"));
        Visualizza->resize(956, 649);
        Visualizza->setSizeGripEnabled(true);
        Visualizza->setModal(false);
        buttonBox = new QDialogButtonBox(Visualizza);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setEnabled(true);
        buttonBox->setGeometry(QRect(590, 590, 341, 32));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(buttonBox->sizePolicy().hasHeightForWidth());
        buttonBox->setSizePolicy(sizePolicy);
        QFont font;
        font.setPointSize(8);
        buttonBox->setFont(font);
        buttonBox->setFocusPolicy(Qt::NoFocus);
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        buttonBox->setCenterButtons(false);
        label = new QLabel(Visualizza);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 40, 531, 31));
        QFont font1;
        font1.setPointSize(14);
        label->setFont(font1);
        pushButton = new QPushButton(Visualizza);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(830, 50, 93, 28));
        label_2 = new QLabel(Visualizza);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(240, 190, 431, 201));

        retranslateUi(Visualizza);
        QObject::connect(buttonBox, SIGNAL(accepted()), Visualizza, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), Visualizza, SLOT(reject()));

        QMetaObject::connectSlotsByName(Visualizza);
    } // setupUi

    void retranslateUi(QDialog *Visualizza)
    {
        Visualizza->setWindowTitle(QCoreApplication::translate("Visualizza", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("Visualizza", "Per visualizzare tutto il grafico, clicca su Visualizza", nullptr));
        pushButton->setText(QCoreApplication::translate("Visualizza", "Visualizza", nullptr));
        label_2->setText(QCoreApplication::translate("Visualizza", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Visualizza: public Ui_Visualizza {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VISUALIZZA_H
