/********************************************************************************
** Form generated from reading UI file 'inserisci.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INSERISCI_H
#define UI_INSERISCI_H

#include <QtCore/QDate>
#include <QtCore/QLocale>
#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCalendarWidget>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_Inserisci
{
public:
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer;
    QLabel *label;
    QHBoxLayout *horizontalLayout;
    QLineEdit *nome;
    QLineEdit *cognome;
    QHBoxLayout *horizontalLayout_2;
    QLineEdit *eta;
    QLineEdit *paese;
    QFrame *line;
    QSpacerItem *verticalSpacer_2;
    QLabel *label_2;
    QGridLayout *gridLayout_2;
    QRadioButton *radio_negativo;
    QRadioButton *radio_positivo;
    QGridLayout *gridLayout;
    QCalendarWidget *calendar;
    QDialogButtonBox *save_button;

    void setupUi(QDialog *Inserisci)
    {
        if (Inserisci->objectName().isEmpty())
            Inserisci->setObjectName(QString::fromUtf8("Inserisci"));
        Inserisci->resize(1159, 685);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Inserisci->sizePolicy().hasHeightForWidth());
        Inserisci->setSizePolicy(sizePolicy);
        Inserisci->setBaseSize(QSize(0, 0));
        verticalLayout = new QVBoxLayout(Inserisci);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalSpacer = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout->addItem(verticalSpacer);

        label = new QLabel(Inserisci);
        label->setObjectName(QString::fromUtf8("label"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy1);
        QFont font;
        font.setPointSize(12);
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        nome = new QLineEdit(Inserisci);
        nome->setObjectName(QString::fromUtf8("nome"));
        QFont font1;
        font1.setPointSize(14);
        nome->setFont(font1);
        nome->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(nome);

        cognome = new QLineEdit(Inserisci);
        cognome->setObjectName(QString::fromUtf8("cognome"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(cognome->sizePolicy().hasHeightForWidth());
        cognome->setSizePolicy(sizePolicy2);
        cognome->setFont(font1);
        cognome->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(cognome);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        eta = new QLineEdit(Inserisci);
        eta->setObjectName(QString::fromUtf8("eta"));
        eta->setFont(font1);
        eta->setInputMethodHints(Qt::ImhDigitsOnly);
        eta->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(eta);

        paese = new QLineEdit(Inserisci);
        paese->setObjectName(QString::fromUtf8("paese"));
        paese->setFont(font1);
        paese->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(paese);


        verticalLayout->addLayout(horizontalLayout_2);

        line = new QFrame(Inserisci);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line);

        verticalSpacer_2 = new QSpacerItem(20, 10, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout->addItem(verticalSpacer_2);

        label_2 = new QLabel(Inserisci);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        sizePolicy1.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy1);
        label_2->setFont(font);
        label_2->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label_2);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        radio_negativo = new QRadioButton(Inserisci);
        radio_negativo->setObjectName(QString::fromUtf8("radio_negativo"));
        sizePolicy.setHeightForWidth(radio_negativo->sizePolicy().hasHeightForWidth());
        radio_negativo->setSizePolicy(sizePolicy);
        radio_negativo->setFont(font1);

        gridLayout_2->addWidget(radio_negativo, 1, 0, 1, 1);

        radio_positivo = new QRadioButton(Inserisci);
        radio_positivo->setObjectName(QString::fromUtf8("radio_positivo"));
        sizePolicy.setHeightForWidth(radio_positivo->sizePolicy().hasHeightForWidth());
        radio_positivo->setSizePolicy(sizePolicy);
        radio_positivo->setFont(font1);
        radio_positivo->setLayoutDirection(Qt::LeftToRight);

        gridLayout_2->addWidget(radio_positivo, 0, 0, 1, 1);


        verticalLayout->addLayout(gridLayout_2);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        calendar = new QCalendarWidget(Inserisci);
        calendar->setObjectName(QString::fromUtf8("calendar"));
        sizePolicy.setHeightForWidth(calendar->sizePolicy().hasHeightForWidth());
        calendar->setSizePolicy(sizePolicy);
        calendar->setFocusPolicy(Qt::StrongFocus);
        calendar->setLayoutDirection(Qt::LeftToRight);
        calendar->setLocale(QLocale(QLocale::Italian, QLocale::Italy));
        calendar->setMinimumDate(QDate(2020, 1, 1));
        calendar->setFirstDayOfWeek(Qt::Monday);
        calendar->setGridVisible(true);
        calendar->setVerticalHeaderFormat(QCalendarWidget::NoVerticalHeader);

        gridLayout->addWidget(calendar, 0, 0, 1, 1);


        verticalLayout->addLayout(gridLayout);

        save_button = new QDialogButtonBox(Inserisci);
        save_button->setObjectName(QString::fromUtf8("save_button"));
        save_button->setEnabled(true);
        sizePolicy.setHeightForWidth(save_button->sizePolicy().hasHeightForWidth());
        save_button->setSizePolicy(sizePolicy);
        QFont font2;
        font2.setPointSize(8);
        save_button->setFont(font2);
        save_button->setMouseTracking(false);
        save_button->setFocusPolicy(Qt::NoFocus);
        save_button->setLayoutDirection(Qt::RightToLeft);
        save_button->setOrientation(Qt::Horizontal);
        save_button->setStandardButtons(QDialogButtonBox::Save);
        save_button->setCenterButtons(false);

        verticalLayout->addWidget(save_button);


        retranslateUi(Inserisci);

        QMetaObject::connectSlotsByName(Inserisci);
    } // setupUi

    void retranslateUi(QDialog *Inserisci)
    {
        Inserisci->setWindowTitle(QCoreApplication::translate("Inserisci", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("Inserisci", "Inserisci i dati del paziente:", nullptr));
        nome->setPlaceholderText(QCoreApplication::translate("Inserisci", "Nome", nullptr));
        cognome->setPlaceholderText(QCoreApplication::translate("Inserisci", "Cognome", nullptr));
        eta->setPlaceholderText(QCoreApplication::translate("Inserisci", "Et\303\240", nullptr));
        paese->setPlaceholderText(QCoreApplication::translate("Inserisci", "Paese", nullptr));
        label_2->setText(QCoreApplication::translate("Inserisci", "Seleziona l'esito del tampone al COVID-19 e la data in cui \303\250 stato effettuato:", nullptr));
        radio_negativo->setText(QCoreApplication::translate("Inserisci", "Negativo", nullptr));
        radio_positivo->setText(QCoreApplication::translate("Inserisci", "Positivo", nullptr));
#if QT_CONFIG(whatsthis)
        save_button->setWhatsThis(QCoreApplication::translate("Inserisci", "<html><head/><body><p><br/></p></body></html>", nullptr));
#endif // QT_CONFIG(whatsthis)
    } // retranslateUi

};

namespace Ui {
    class Inserisci: public Ui_Inserisci {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INSERISCI_H
