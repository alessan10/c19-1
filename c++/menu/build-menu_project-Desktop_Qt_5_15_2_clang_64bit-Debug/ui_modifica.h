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
    QLineEdit *lineEdit;
    QLabel *label_2;
    QLineEdit *lineEdit_2;
    QFrame *line_2;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_4;
    QLineEdit *lineEdit_4;
    QLabel *label_5;
    QLineEdit *lineEdit_3;
    QFrame *line_3;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_6;
    QComboBox *comboBox_5;
    QLabel *label_7;
    QComboBox *comboBox;
    QLabel *label_8;
    QComboBox *comboBox_4;
    QLabel *label_9;
    QComboBox *comboBox_2;
    QFrame *line_4;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_10;
    QComboBox *comboBox_3;
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
        QFont font1;
        font1.setPointSize(12);
        label_3->setFont(font1);

        horizontalLayout_3->addWidget(label_3);

        lineEdit = new QLineEdit(Modifica);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        horizontalLayout_3->addWidget(lineEdit);

        label_2 = new QLabel(Modifica);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setFont(font1);

        horizontalLayout_3->addWidget(label_2);

        lineEdit_2 = new QLineEdit(Modifica);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));

        horizontalLayout_3->addWidget(lineEdit_2);


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
        label_4->setFont(font1);

        horizontalLayout_4->addWidget(label_4);

        lineEdit_4 = new QLineEdit(Modifica);
        lineEdit_4->setObjectName(QString::fromUtf8("lineEdit_4"));

        horizontalLayout_4->addWidget(lineEdit_4);

        label_5 = new QLabel(Modifica);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setFont(font1);

        horizontalLayout_4->addWidget(label_5);

        lineEdit_3 = new QLineEdit(Modifica);
        lineEdit_3->setObjectName(QString::fromUtf8("lineEdit_3"));

        horizontalLayout_4->addWidget(lineEdit_3);


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
        label_6->setFont(font1);

        horizontalLayout_5->addWidget(label_6);

        comboBox_5 = new QComboBox(Modifica);
        comboBox_5->addItem(QString());
        comboBox_5->addItem(QString());
        comboBox_5->addItem(QString());
        comboBox_5->addItem(QString());
        comboBox_5->addItem(QString());
        comboBox_5->addItem(QString());
        comboBox_5->addItem(QString());
        comboBox_5->addItem(QString());
        comboBox_5->addItem(QString());
        comboBox_5->addItem(QString());
        comboBox_5->addItem(QString());
        comboBox_5->addItem(QString());
        comboBox_5->addItem(QString());
        comboBox_5->addItem(QString());
        comboBox_5->addItem(QString());
        comboBox_5->addItem(QString());
        comboBox_5->addItem(QString());
        comboBox_5->addItem(QString());
        comboBox_5->addItem(QString());
        comboBox_5->addItem(QString());
        comboBox_5->addItem(QString());
        comboBox_5->addItem(QString());
        comboBox_5->addItem(QString());
        comboBox_5->addItem(QString());
        comboBox_5->addItem(QString());
        comboBox_5->addItem(QString());
        comboBox_5->addItem(QString());
        comboBox_5->addItem(QString());
        comboBox_5->addItem(QString());
        comboBox_5->addItem(QString());
        comboBox_5->addItem(QString());
        comboBox_5->setObjectName(QString::fromUtf8("comboBox_5"));
        comboBox_5->setFont(font1);

        horizontalLayout_5->addWidget(comboBox_5);

        label_7 = new QLabel(Modifica);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setFont(font1);

        horizontalLayout_5->addWidget(label_7);

        comboBox = new QComboBox(Modifica);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setFont(font1);

        horizontalLayout_5->addWidget(comboBox);

        label_8 = new QLabel(Modifica);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setFont(font1);

        horizontalLayout_5->addWidget(label_8);

        comboBox_4 = new QComboBox(Modifica);
        comboBox_4->addItem(QString());
        comboBox_4->addItem(QString());
        comboBox_4->setObjectName(QString::fromUtf8("comboBox_4"));
        comboBox_4->setFont(font1);

        horizontalLayout_5->addWidget(comboBox_4);

        label_9 = new QLabel(Modifica);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setFont(font1);

        horizontalLayout_5->addWidget(label_9);

        comboBox_2 = new QComboBox(Modifica);
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->setObjectName(QString::fromUtf8("comboBox_2"));
        comboBox_2->setFont(font1);

        horizontalLayout_5->addWidget(comboBox_2);


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
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label_10->sizePolicy().hasHeightForWidth());
        label_10->setSizePolicy(sizePolicy1);
        label_10->setFont(font1);

        horizontalLayout_6->addWidget(label_10);

        comboBox_3 = new QComboBox(Modifica);
        comboBox_3->addItem(QString());
        comboBox_3->addItem(QString());
        comboBox_3->setObjectName(QString::fromUtf8("comboBox_3"));
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(comboBox_3->sizePolicy().hasHeightForWidth());
        comboBox_3->setSizePolicy(sizePolicy2);
        comboBox_3->setFont(font1);

        horizontalLayout_6->addWidget(comboBox_3);


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
        label_2->setText(QCoreApplication::translate("Modifica", "Cognome", nullptr));
        label_4->setText(QCoreApplication::translate("Modifica", "Et\303\240", nullptr));
        label_5->setText(QCoreApplication::translate("Modifica", "Paese", nullptr));
        label_6->setText(QCoreApplication::translate("Modifica", "Giorno", nullptr));
        comboBox_5->setItemText(0, QCoreApplication::translate("Modifica", "1", nullptr));
        comboBox_5->setItemText(1, QCoreApplication::translate("Modifica", "2", nullptr));
        comboBox_5->setItemText(2, QCoreApplication::translate("Modifica", "3", nullptr));
        comboBox_5->setItemText(3, QCoreApplication::translate("Modifica", "4", nullptr));
        comboBox_5->setItemText(4, QCoreApplication::translate("Modifica", "5", nullptr));
        comboBox_5->setItemText(5, QCoreApplication::translate("Modifica", "6", nullptr));
        comboBox_5->setItemText(6, QCoreApplication::translate("Modifica", "7", nullptr));
        comboBox_5->setItemText(7, QCoreApplication::translate("Modifica", "8", nullptr));
        comboBox_5->setItemText(8, QCoreApplication::translate("Modifica", "9", nullptr));
        comboBox_5->setItemText(9, QCoreApplication::translate("Modifica", "10", nullptr));
        comboBox_5->setItemText(10, QCoreApplication::translate("Modifica", "11", nullptr));
        comboBox_5->setItemText(11, QCoreApplication::translate("Modifica", "12", nullptr));
        comboBox_5->setItemText(12, QCoreApplication::translate("Modifica", "13", nullptr));
        comboBox_5->setItemText(13, QCoreApplication::translate("Modifica", "14", nullptr));
        comboBox_5->setItemText(14, QCoreApplication::translate("Modifica", "15", nullptr));
        comboBox_5->setItemText(15, QCoreApplication::translate("Modifica", "16", nullptr));
        comboBox_5->setItemText(16, QCoreApplication::translate("Modifica", "17", nullptr));
        comboBox_5->setItemText(17, QCoreApplication::translate("Modifica", "18", nullptr));
        comboBox_5->setItemText(18, QCoreApplication::translate("Modifica", "19", nullptr));
        comboBox_5->setItemText(19, QCoreApplication::translate("Modifica", "20", nullptr));
        comboBox_5->setItemText(20, QCoreApplication::translate("Modifica", "21", nullptr));
        comboBox_5->setItemText(21, QCoreApplication::translate("Modifica", "22", nullptr));
        comboBox_5->setItemText(22, QCoreApplication::translate("Modifica", "23", nullptr));
        comboBox_5->setItemText(23, QCoreApplication::translate("Modifica", "24", nullptr));
        comboBox_5->setItemText(24, QCoreApplication::translate("Modifica", "25", nullptr));
        comboBox_5->setItemText(25, QCoreApplication::translate("Modifica", "26", nullptr));
        comboBox_5->setItemText(26, QCoreApplication::translate("Modifica", "27", nullptr));
        comboBox_5->setItemText(27, QCoreApplication::translate("Modifica", "28", nullptr));
        comboBox_5->setItemText(28, QCoreApplication::translate("Modifica", "29", nullptr));
        comboBox_5->setItemText(29, QCoreApplication::translate("Modifica", "30", nullptr));
        comboBox_5->setItemText(30, QCoreApplication::translate("Modifica", "31", nullptr));

        label_7->setText(QCoreApplication::translate("Modifica", "Mese", nullptr));
        comboBox->setItemText(0, QCoreApplication::translate("Modifica", "Jan", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("Modifica", "Feb", nullptr));
        comboBox->setItemText(2, QCoreApplication::translate("Modifica", "Mar", nullptr));
        comboBox->setItemText(3, QCoreApplication::translate("Modifica", "Apr", nullptr));
        comboBox->setItemText(4, QCoreApplication::translate("Modifica", "May", nullptr));
        comboBox->setItemText(5, QCoreApplication::translate("Modifica", "Jun", nullptr));
        comboBox->setItemText(6, QCoreApplication::translate("Modifica", "Jul", nullptr));
        comboBox->setItemText(7, QCoreApplication::translate("Modifica", "Aug", nullptr));
        comboBox->setItemText(8, QCoreApplication::translate("Modifica", "Sep", nullptr));
        comboBox->setItemText(9, QCoreApplication::translate("Modifica", "Oct", nullptr));
        comboBox->setItemText(10, QCoreApplication::translate("Modifica", "Nov", nullptr));
        comboBox->setItemText(11, QCoreApplication::translate("Modifica", "Dec", nullptr));

        label_8->setText(QCoreApplication::translate("Modifica", "Anno", nullptr));
        comboBox_4->setItemText(0, QCoreApplication::translate("Modifica", "2020", nullptr));
        comboBox_4->setItemText(1, QCoreApplication::translate("Modifica", "2021", nullptr));

        label_9->setText(QCoreApplication::translate("Modifica", "Giorno settimanale", nullptr));
        comboBox_2->setItemText(0, QCoreApplication::translate("Modifica", "Mon", nullptr));
        comboBox_2->setItemText(1, QCoreApplication::translate("Modifica", "Tue", nullptr));
        comboBox_2->setItemText(2, QCoreApplication::translate("Modifica", "Wed", nullptr));
        comboBox_2->setItemText(3, QCoreApplication::translate("Modifica", "Thu", nullptr));
        comboBox_2->setItemText(4, QCoreApplication::translate("Modifica", "Fri", nullptr));
        comboBox_2->setItemText(5, QCoreApplication::translate("Modifica", "Sat", nullptr));
        comboBox_2->setItemText(6, QCoreApplication::translate("Modifica", "Sun", nullptr));

        label_10->setText(QCoreApplication::translate("Modifica", "Covid", nullptr));
        comboBox_3->setItemText(0, QCoreApplication::translate("Modifica", "positivo", nullptr));
        comboBox_3->setItemText(1, QCoreApplication::translate("Modifica", "negativo", nullptr));

        button_modifica->setText(QCoreApplication::translate("Modifica", "Modifica", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Modifica: public Ui_Modifica {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MODIFICA_H
