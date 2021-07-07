/********************************************************************************
** Form generated from reading UI file 'modifica.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MODIFICA_H
#define UI_MODIFICA_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_Modifica
{
public:
    QVBoxLayout *verticalLayout_2;
    QLabel *label;
    QHBoxLayout *horizontalLayout_2;
    QLineEdit *nome;
    QLineEdit *cognome;
    QPushButton *pushButton;
    QFrame *line;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QLineEdit *new_nome;
    QSpacerItem *horizontalSpacer;
    QLabel *label_2;
    QLineEdit *new_cognome;
    QFrame *line_2;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_4;
    QLineEdit *new_eta;
    QSpacerItem *horizontalSpacer_2;
    QLabel *label_5;
    QLineEdit *new_paese;
    QFrame *line_3;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_6;
    QComboBox *new_day;
    QSpacerItem *horizontalSpacer_3;
    QFrame *line_5;
    QLabel *label_7;
    QComboBox *new_month;
    QSpacerItem *horizontalSpacer_4;
    QFrame *line_6;
    QLabel *label_8;
    QComboBox *new_year;
    QSpacerItem *horizontalSpacer_5;
    QFrame *line_7;
    QLabel *label_9;
    QComboBox *new_weekday;
    QFrame *line_4;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_10;
    QComboBox *new_covid;
    QPushButton *button_modifica;

    void setupUi(QDialog *Modifica)
    {
        if (Modifica->objectName().isEmpty())
            Modifica->setObjectName(QString::fromUtf8("Modifica"));
        Modifica->resize(1019, 642);
        verticalLayout_2 = new QVBoxLayout(Modifica);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        label = new QLabel(Modifica);
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
        nome = new QLineEdit(Modifica);
        nome->setObjectName(QString::fromUtf8("nome"));
        nome->setFont(font);
        nome->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(nome);

        cognome = new QLineEdit(Modifica);
        cognome->setObjectName(QString::fromUtf8("cognome"));
        cognome->setFont(font);
        cognome->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(cognome);


        verticalLayout_2->addLayout(horizontalLayout_2);

        pushButton = new QPushButton(Modifica);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setFont(font);

        verticalLayout_2->addWidget(pushButton);

        line = new QFrame(Modifica);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout_2->addWidget(line);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_3 = new QLabel(Modifica);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        sizePolicy.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy);
        QFont font1;
        font1.setPointSize(12);
        label_3->setFont(font1);

        horizontalLayout_3->addWidget(label_3);

        new_nome = new QLineEdit(Modifica);
        new_nome->setObjectName(QString::fromUtf8("new_nome"));
        new_nome->setFont(font1);
        new_nome->setAlignment(Qt::AlignCenter);

        horizontalLayout_3->addWidget(new_nome);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        label_2 = new QLabel(Modifica);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy1);
        label_2->setFont(font1);

        horizontalLayout_3->addWidget(label_2);

        new_cognome = new QLineEdit(Modifica);
        new_cognome->setObjectName(QString::fromUtf8("new_cognome"));
        new_cognome->setFont(font1);
        new_cognome->setAlignment(Qt::AlignCenter);

        horizontalLayout_3->addWidget(new_cognome);


        verticalLayout_2->addLayout(horizontalLayout_3);

        line_2 = new QFrame(Modifica);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        verticalLayout_2->addWidget(line_2);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_4 = new QLabel(Modifica);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        sizePolicy1.setHeightForWidth(label_4->sizePolicy().hasHeightForWidth());
        label_4->setSizePolicy(sizePolicy1);
        label_4->setFont(font1);

        horizontalLayout_4->addWidget(label_4);

        new_eta = new QLineEdit(Modifica);
        new_eta->setObjectName(QString::fromUtf8("new_eta"));
        new_eta->setFont(font1);
        new_eta->setAlignment(Qt::AlignCenter);

        horizontalLayout_4->addWidget(new_eta);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_2);

        label_5 = new QLabel(Modifica);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        sizePolicy1.setHeightForWidth(label_5->sizePolicy().hasHeightForWidth());
        label_5->setSizePolicy(sizePolicy1);
        label_5->setFont(font1);

        horizontalLayout_4->addWidget(label_5);

        new_paese = new QLineEdit(Modifica);
        new_paese->setObjectName(QString::fromUtf8("new_paese"));
        new_paese->setFont(font1);
        new_paese->setAlignment(Qt::AlignCenter);
        new_paese->setReadOnly(false);

        horizontalLayout_4->addWidget(new_paese);


        verticalLayout_2->addLayout(horizontalLayout_4);

        line_3 = new QFrame(Modifica);
        line_3->setObjectName(QString::fromUtf8("line_3"));
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);

        verticalLayout_2->addWidget(line_3);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        label_6 = new QLabel(Modifica);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        sizePolicy1.setHeightForWidth(label_6->sizePolicy().hasHeightForWidth());
        label_6->setSizePolicy(sizePolicy1);
        label_6->setFont(font1);

        horizontalLayout_5->addWidget(label_6);

        new_day = new QComboBox(Modifica);
        new_day->addItem(QString());
        new_day->addItem(QString());
        new_day->addItem(QString());
        new_day->addItem(QString());
        new_day->addItem(QString());
        new_day->addItem(QString());
        new_day->addItem(QString());
        new_day->addItem(QString());
        new_day->addItem(QString());
        new_day->addItem(QString());
        new_day->addItem(QString());
        new_day->addItem(QString());
        new_day->addItem(QString());
        new_day->addItem(QString());
        new_day->addItem(QString());
        new_day->addItem(QString());
        new_day->addItem(QString());
        new_day->addItem(QString());
        new_day->addItem(QString());
        new_day->addItem(QString());
        new_day->addItem(QString());
        new_day->addItem(QString());
        new_day->addItem(QString());
        new_day->addItem(QString());
        new_day->addItem(QString());
        new_day->addItem(QString());
        new_day->addItem(QString());
        new_day->addItem(QString());
        new_day->addItem(QString());
        new_day->addItem(QString());
        new_day->addItem(QString());
        new_day->setObjectName(QString::fromUtf8("new_day"));
        new_day->setFont(font1);

        horizontalLayout_5->addWidget(new_day);

        horizontalSpacer_3 = new QSpacerItem(25, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_3);

        line_5 = new QFrame(Modifica);
        line_5->setObjectName(QString::fromUtf8("line_5"));
        line_5->setFrameShape(QFrame::VLine);
        line_5->setFrameShadow(QFrame::Sunken);

        horizontalLayout_5->addWidget(line_5);

        label_7 = new QLabel(Modifica);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        sizePolicy1.setHeightForWidth(label_7->sizePolicy().hasHeightForWidth());
        label_7->setSizePolicy(sizePolicy1);
        label_7->setFont(font1);

        horizontalLayout_5->addWidget(label_7);

        new_month = new QComboBox(Modifica);
        new_month->addItem(QString());
        new_month->addItem(QString());
        new_month->addItem(QString());
        new_month->addItem(QString());
        new_month->addItem(QString());
        new_month->addItem(QString());
        new_month->addItem(QString());
        new_month->addItem(QString());
        new_month->addItem(QString());
        new_month->addItem(QString());
        new_month->addItem(QString());
        new_month->addItem(QString());
        new_month->setObjectName(QString::fromUtf8("new_month"));
        new_month->setFont(font1);

        horizontalLayout_5->addWidget(new_month);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_4);

        line_6 = new QFrame(Modifica);
        line_6->setObjectName(QString::fromUtf8("line_6"));
        line_6->setFrameShape(QFrame::VLine);
        line_6->setFrameShadow(QFrame::Sunken);

        horizontalLayout_5->addWidget(line_6);

        label_8 = new QLabel(Modifica);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        sizePolicy1.setHeightForWidth(label_8->sizePolicy().hasHeightForWidth());
        label_8->setSizePolicy(sizePolicy1);
        label_8->setFont(font1);

        horizontalLayout_5->addWidget(label_8);

        new_year = new QComboBox(Modifica);
        new_year->addItem(QString());
        new_year->addItem(QString());
        new_year->setObjectName(QString::fromUtf8("new_year"));
        new_year->setFont(font1);

        horizontalLayout_5->addWidget(new_year);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_5);

        line_7 = new QFrame(Modifica);
        line_7->setObjectName(QString::fromUtf8("line_7"));
        line_7->setFrameShape(QFrame::VLine);
        line_7->setFrameShadow(QFrame::Sunken);

        horizontalLayout_5->addWidget(line_7);

        label_9 = new QLabel(Modifica);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        sizePolicy1.setHeightForWidth(label_9->sizePolicy().hasHeightForWidth());
        label_9->setSizePolicy(sizePolicy1);
        label_9->setFont(font1);

        horizontalLayout_5->addWidget(label_9);

        new_weekday = new QComboBox(Modifica);
        new_weekday->addItem(QString());
        new_weekday->addItem(QString());
        new_weekday->addItem(QString());
        new_weekday->addItem(QString());
        new_weekday->addItem(QString());
        new_weekday->addItem(QString());
        new_weekday->addItem(QString());
        new_weekday->setObjectName(QString::fromUtf8("new_weekday"));
        new_weekday->setFont(font1);
        new_weekday->setToolTipDuration(0);

        horizontalLayout_5->addWidget(new_weekday);


        verticalLayout_2->addLayout(horizontalLayout_5);

        line_4 = new QFrame(Modifica);
        line_4->setObjectName(QString::fromUtf8("line_4"));
        line_4->setFrameShape(QFrame::HLine);
        line_4->setFrameShadow(QFrame::Sunken);

        verticalLayout_2->addWidget(line_4);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        label_10 = new QLabel(Modifica);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(label_10->sizePolicy().hasHeightForWidth());
        label_10->setSizePolicy(sizePolicy2);
        label_10->setFont(font1);

        horizontalLayout_6->addWidget(label_10);

        new_covid = new QComboBox(Modifica);
        new_covid->addItem(QString());
        new_covid->addItem(QString());
        new_covid->setObjectName(QString::fromUtf8("new_covid"));
        sizePolicy2.setHeightForWidth(new_covid->sizePolicy().hasHeightForWidth());
        new_covid->setSizePolicy(sizePolicy2);
        new_covid->setFont(font1);

        horizontalLayout_6->addWidget(new_covid);


        verticalLayout_2->addLayout(horizontalLayout_6);

        button_modifica = new QPushButton(Modifica);
        button_modifica->setObjectName(QString::fromUtf8("button_modifica"));
        button_modifica->setFont(font);

        verticalLayout_2->addWidget(button_modifica);


        retranslateUi(Modifica);

        QMetaObject::connectSlotsByName(Modifica);
    } // setupUi

    void retranslateUi(QDialog *Modifica)
    {
        Modifica->setWindowTitle(QCoreApplication::translate("Modifica", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("Modifica", "Per modificare i campi di un soggetto, digita il suo nome e il suo cognome nel box sottostante!", nullptr));
        nome->setPlaceholderText(QCoreApplication::translate("Modifica", "Nome", nullptr));
        cognome->setPlaceholderText(QCoreApplication::translate("Modifica", "Cognome", nullptr));
        pushButton->setText(QCoreApplication::translate("Modifica", "Cerca", nullptr));
        label_3->setText(QCoreApplication::translate("Modifica", "Nome", nullptr));
        new_nome->setPlaceholderText(QString());
        label_2->setText(QCoreApplication::translate("Modifica", "Cognome", nullptr));
        label_4->setText(QCoreApplication::translate("Modifica", "Et\303\240", nullptr));
        label_5->setText(QCoreApplication::translate("Modifica", "Paese", nullptr));
        label_6->setText(QCoreApplication::translate("Modifica", "Giorno", nullptr));
        new_day->setItemText(0, QCoreApplication::translate("Modifica", "1", nullptr));
        new_day->setItemText(1, QCoreApplication::translate("Modifica", "2", nullptr));
        new_day->setItemText(2, QCoreApplication::translate("Modifica", "3", nullptr));
        new_day->setItemText(3, QCoreApplication::translate("Modifica", "4", nullptr));
        new_day->setItemText(4, QCoreApplication::translate("Modifica", "5", nullptr));
        new_day->setItemText(5, QCoreApplication::translate("Modifica", "6", nullptr));
        new_day->setItemText(6, QCoreApplication::translate("Modifica", "7", nullptr));
        new_day->setItemText(7, QCoreApplication::translate("Modifica", "8", nullptr));
        new_day->setItemText(8, QCoreApplication::translate("Modifica", "9", nullptr));
        new_day->setItemText(9, QCoreApplication::translate("Modifica", "10", nullptr));
        new_day->setItemText(10, QCoreApplication::translate("Modifica", "11", nullptr));
        new_day->setItemText(11, QCoreApplication::translate("Modifica", "12", nullptr));
        new_day->setItemText(12, QCoreApplication::translate("Modifica", "13", nullptr));
        new_day->setItemText(13, QCoreApplication::translate("Modifica", "14", nullptr));
        new_day->setItemText(14, QCoreApplication::translate("Modifica", "15", nullptr));
        new_day->setItemText(15, QCoreApplication::translate("Modifica", "16", nullptr));
        new_day->setItemText(16, QCoreApplication::translate("Modifica", "17", nullptr));
        new_day->setItemText(17, QCoreApplication::translate("Modifica", "18", nullptr));
        new_day->setItemText(18, QCoreApplication::translate("Modifica", "19", nullptr));
        new_day->setItemText(19, QCoreApplication::translate("Modifica", "20", nullptr));
        new_day->setItemText(20, QCoreApplication::translate("Modifica", "21", nullptr));
        new_day->setItemText(21, QCoreApplication::translate("Modifica", "22", nullptr));
        new_day->setItemText(22, QCoreApplication::translate("Modifica", "23", nullptr));
        new_day->setItemText(23, QCoreApplication::translate("Modifica", "24", nullptr));
        new_day->setItemText(24, QCoreApplication::translate("Modifica", "25", nullptr));
        new_day->setItemText(25, QCoreApplication::translate("Modifica", "26", nullptr));
        new_day->setItemText(26, QCoreApplication::translate("Modifica", "27", nullptr));
        new_day->setItemText(27, QCoreApplication::translate("Modifica", "28", nullptr));
        new_day->setItemText(28, QCoreApplication::translate("Modifica", "29", nullptr));
        new_day->setItemText(29, QCoreApplication::translate("Modifica", "30", nullptr));
        new_day->setItemText(30, QCoreApplication::translate("Modifica", "31", nullptr));

        label_7->setText(QCoreApplication::translate("Modifica", "Mese", nullptr));
        new_month->setItemText(0, QCoreApplication::translate("Modifica", "Jan", nullptr));
        new_month->setItemText(1, QCoreApplication::translate("Modifica", "Feb", nullptr));
        new_month->setItemText(2, QCoreApplication::translate("Modifica", "Mar", nullptr));
        new_month->setItemText(3, QCoreApplication::translate("Modifica", "Apr", nullptr));
        new_month->setItemText(4, QCoreApplication::translate("Modifica", "May", nullptr));
        new_month->setItemText(5, QCoreApplication::translate("Modifica", "Jun", nullptr));
        new_month->setItemText(6, QCoreApplication::translate("Modifica", "Jul", nullptr));
        new_month->setItemText(7, QCoreApplication::translate("Modifica", "Aug", nullptr));
        new_month->setItemText(8, QCoreApplication::translate("Modifica", "Sep", nullptr));
        new_month->setItemText(9, QCoreApplication::translate("Modifica", "Oct", nullptr));
        new_month->setItemText(10, QCoreApplication::translate("Modifica", "Nov", nullptr));
        new_month->setItemText(11, QCoreApplication::translate("Modifica", "Dec", nullptr));

        label_8->setText(QCoreApplication::translate("Modifica", "Anno", nullptr));
        new_year->setItemText(0, QCoreApplication::translate("Modifica", "2020", nullptr));
        new_year->setItemText(1, QCoreApplication::translate("Modifica", "2021", nullptr));

        label_9->setText(QCoreApplication::translate("Modifica", "Giorno settimanale", nullptr));
        new_weekday->setItemText(0, QCoreApplication::translate("Modifica", "Mon", nullptr));
        new_weekday->setItemText(1, QCoreApplication::translate("Modifica", "Tue", nullptr));
        new_weekday->setItemText(2, QCoreApplication::translate("Modifica", "Wed", nullptr));
        new_weekday->setItemText(3, QCoreApplication::translate("Modifica", "Thu", nullptr));
        new_weekday->setItemText(4, QCoreApplication::translate("Modifica", "Fri", nullptr));
        new_weekday->setItemText(5, QCoreApplication::translate("Modifica", "Sat", nullptr));
        new_weekday->setItemText(6, QCoreApplication::translate("Modifica", "Sun", nullptr));

        label_10->setText(QCoreApplication::translate("Modifica", "Covid", nullptr));
        new_covid->setItemText(0, QCoreApplication::translate("Modifica", "positivo", nullptr));
        new_covid->setItemText(1, QCoreApplication::translate("Modifica", "negativo", nullptr));

        button_modifica->setText(QCoreApplication::translate("Modifica", "Modifica", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Modifica: public Ui_Modifica {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MODIFICA_H
