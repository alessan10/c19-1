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
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_Visualizza
{
public:
    QVBoxLayout *verticalLayout;
    QTableWidget *table;
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
        table = new QTableWidget(Visualizza);
        table->setObjectName(QString::fromUtf8("table"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(table->sizePolicy().hasHeightForWidth());
        table->setSizePolicy(sizePolicy);
        QFont font;
        font.setPointSize(12);
        table->setFont(font);
        table->setLayoutDirection(Qt::LeftToRight);
        table->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);
        table->setSelectionMode(QAbstractItemView::NoSelection);
        table->setTextElideMode(Qt::ElideMiddle);
        table->setVerticalScrollMode(QAbstractItemView::ScrollPerItem);
        table->setSortingEnabled(true);

        verticalLayout->addWidget(table);

        label = new QLabel(Visualizza);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font1;
        font1.setPointSize(14);
        label->setFont(font1);
        label->setLayoutDirection(Qt::LeftToRight);
        label->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label);

        pushButton = new QPushButton(Visualizza);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setFont(font);
        pushButton->setLayoutDirection(Qt::LeftToRight);

        verticalLayout->addWidget(pushButton);

        buttonBox = new QDialogButtonBox(Visualizza);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setEnabled(true);
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(buttonBox->sizePolicy().hasHeightForWidth());
        buttonBox->setSizePolicy(sizePolicy1);
        QFont font2;
        font2.setPointSize(8);
        buttonBox->setFont(font2);
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
        label->setText(QCoreApplication::translate("Visualizza", "Per visualizzare il contenuto del database, clicca su \"Visualizza\"", nullptr));
        pushButton->setText(QCoreApplication::translate("Visualizza", "Visualizza", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Visualizza: public Ui_Visualizza {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VISUALIZZA_H
