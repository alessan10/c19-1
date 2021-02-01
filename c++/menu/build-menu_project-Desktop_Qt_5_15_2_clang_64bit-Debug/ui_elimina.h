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
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_Elimina
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLineEdit *lineEdit;
    QPushButton *pushButton;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *Elimina)
    {
        if (Elimina->objectName().isEmpty())
            Elimina->setObjectName(QString::fromUtf8("Elimina"));
        Elimina->resize(951, 627);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Elimina->sizePolicy().hasHeightForWidth());
        Elimina->setSizePolicy(sizePolicy);
        QFont font;
        font.setPointSize(14);
        Elimina->setFont(font);
        verticalLayout = new QVBoxLayout(Elimina);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label = new QLabel(Elimina);
        label->setObjectName(QString::fromUtf8("label"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy1);
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label);

        lineEdit = new QLineEdit(Elimina);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(lineEdit->sizePolicy().hasHeightForWidth());
        lineEdit->setSizePolicy(sizePolicy2);
        lineEdit->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(lineEdit);

        pushButton = new QPushButton(Elimina);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        sizePolicy1.setHeightForWidth(pushButton->sizePolicy().hasHeightForWidth());
        pushButton->setSizePolicy(sizePolicy1);
        pushButton->setFont(font);
        pushButton->setCheckable(false);

        verticalLayout->addWidget(pushButton);

        buttonBox = new QDialogButtonBox(Elimina);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setEnabled(true);
        sizePolicy2.setHeightForWidth(buttonBox->sizePolicy().hasHeightForWidth());
        buttonBox->setSizePolicy(sizePolicy2);
        QFont font1;
        font1.setPointSize(8);
        buttonBox->setFont(font1);
        buttonBox->setFocusPolicy(Qt::NoFocus);
        buttonBox->setLayoutDirection(Qt::LeftToRight);
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::NoButton);
        buttonBox->setCenterButtons(false);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(Elimina);

        QMetaObject::connectSlotsByName(Elimina);
    } // setupUi

    void retranslateUi(QDialog *Elimina)
    {
        Elimina->setWindowTitle(QCoreApplication::translate("Elimina", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("Elimina", "Inserisci Nome e Cognome della persona da eliminare:", nullptr));
        lineEdit->setPlaceholderText(QCoreApplication::translate("Elimina", "ad esempio: Paolo Rossi", nullptr));
        pushButton->setText(QCoreApplication::translate("Elimina", "Elimina", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Elimina: public Ui_Elimina {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ELIMINA_H
