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
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_Visualizza
{
public:
    QVBoxLayout *verticalLayout;
    QListWidget *listWidget;
    QLabel *label;
    QPushButton *pushButton;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *Visualizza)
    {
        if (Visualizza->objectName().isEmpty())
            Visualizza->setObjectName(QString::fromUtf8("Visualizza"));
        Visualizza->resize(997, 649);
        Visualizza->setLayoutDirection(Qt::RightToLeft);
        Visualizza->setSizeGripEnabled(true);
        Visualizza->setModal(false);
        verticalLayout = new QVBoxLayout(Visualizza);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        listWidget = new QListWidget(Visualizza);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));
        listWidget->setLayoutDirection(Qt::LeftToRight);

        verticalLayout->addWidget(listWidget);

        label = new QLabel(Visualizza);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font;
        font.setPointSize(14);
        label->setFont(font);
        label->setLayoutDirection(Qt::LeftToRight);

        verticalLayout->addWidget(label);

        pushButton = new QPushButton(Visualizza);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setLayoutDirection(Qt::LeftToRight);

        verticalLayout->addWidget(pushButton);

        buttonBox = new QDialogButtonBox(Visualizza);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setEnabled(true);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(buttonBox->sizePolicy().hasHeightForWidth());
        buttonBox->setSizePolicy(sizePolicy);
        QFont font1;
        font1.setPointSize(8);
        buttonBox->setFont(font1);
        buttonBox->setFocusPolicy(Qt::NoFocus);
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        buttonBox->setCenterButtons(false);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(Visualizza);
        QObject::connect(buttonBox, SIGNAL(accepted()), Visualizza, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), Visualizza, SLOT(reject()));

        QMetaObject::connectSlotsByName(Visualizza);
    } // setupUi

    void retranslateUi(QDialog *Visualizza)
    {
        Visualizza->setWindowTitle(QCoreApplication::translate("Visualizza", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("Visualizza", "Per visualizzare il contenuto del database e generare il file delle statistiche per R, clicca su Visualizza", nullptr));
        pushButton->setText(QCoreApplication::translate("Visualizza", "Visualizza", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Visualizza: public Ui_Visualizza {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VISUALIZZA_H
