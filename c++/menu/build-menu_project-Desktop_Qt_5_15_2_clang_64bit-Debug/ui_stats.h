/********************************************************************************
** Form generated from reading UI file 'stats.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STATS_H
#define UI_STATS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_Stats
{
public:
    QVBoxLayout *verticalLayout_2;
    QLabel *label;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_6;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton;
    QFrame *line_3;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_5;
    QPushButton *positive_country;
    QFrame *line;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_2;
    QPushButton *positive_month;
    QFrame *line_2;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_4;
    QPushButton *positive_age;
    QFrame *line_4;

    void setupUi(QDialog *Stats)
    {
        if (Stats->objectName().isEmpty())
            Stats->setObjectName(QString::fromUtf8("Stats"));
        Stats->resize(1019, 642);
        verticalLayout_2 = new QVBoxLayout(Stats);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        label = new QLabel(Stats);
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
        label->setMargin(14);

        verticalLayout_2->addWidget(label);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(7);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalLayout_5->setSizeConstraint(QLayout::SetDefaultConstraint);
        horizontalLayout_5->setContentsMargins(-1, -1, -1, 0);
        label_6 = new QLabel(Stats);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Ignored);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label_6->sizePolicy().hasHeightForWidth());
        label_6->setSizePolicy(sizePolicy1);
        label_6->setFont(font);

        horizontalLayout_5->addWidget(label_6);


        verticalLayout_2->addLayout(horizontalLayout_5);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        pushButton = new QPushButton(Stats);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(pushButton->sizePolicy().hasHeightForWidth());
        pushButton->setSizePolicy(sizePolicy2);
        QFont font1;
        font1.setPointSize(16);
        pushButton->setFont(font1);

        horizontalLayout->addWidget(pushButton);


        verticalLayout_2->addLayout(horizontalLayout);

        line_3 = new QFrame(Stats);
        line_3->setObjectName(QString::fromUtf8("line_3"));
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);

        verticalLayout_2->addWidget(line_3);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_5 = new QLabel(Stats);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        QSizePolicy sizePolicy3(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(label_5->sizePolicy().hasHeightForWidth());
        label_5->setSizePolicy(sizePolicy3);
        QFont font2;
        font2.setPointSize(12);
        label_5->setFont(font2);
        label_5->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(label_5);

        positive_country = new QPushButton(Stats);
        positive_country->setObjectName(QString::fromUtf8("positive_country"));
        sizePolicy2.setHeightForWidth(positive_country->sizePolicy().hasHeightForWidth());
        positive_country->setSizePolicy(sizePolicy2);
        positive_country->setFont(font2);

        horizontalLayout_2->addWidget(positive_country);


        verticalLayout_2->addLayout(horizontalLayout_2);

        line = new QFrame(Stats);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout_2->addWidget(line);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_2 = new QLabel(Stats);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        QSizePolicy sizePolicy4(QSizePolicy::Preferred, QSizePolicy::Maximum);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy4);
        label_2->setFont(font2);
        label_2->setAlignment(Qt::AlignCenter);

        horizontalLayout_3->addWidget(label_2);

        positive_month = new QPushButton(Stats);
        positive_month->setObjectName(QString::fromUtf8("positive_month"));
        sizePolicy2.setHeightForWidth(positive_month->sizePolicy().hasHeightForWidth());
        positive_month->setSizePolicy(sizePolicy2);
        positive_month->setFont(font2);

        horizontalLayout_3->addWidget(positive_month);


        verticalLayout_2->addLayout(horizontalLayout_3);

        line_2 = new QFrame(Stats);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        verticalLayout_2->addWidget(line_2);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_4 = new QLabel(Stats);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        sizePolicy3.setHeightForWidth(label_4->sizePolicy().hasHeightForWidth());
        label_4->setSizePolicy(sizePolicy3);
        label_4->setFont(font2);
        label_4->setAlignment(Qt::AlignCenter);

        horizontalLayout_4->addWidget(label_4);

        positive_age = new QPushButton(Stats);
        positive_age->setObjectName(QString::fromUtf8("positive_age"));
        sizePolicy2.setHeightForWidth(positive_age->sizePolicy().hasHeightForWidth());
        positive_age->setSizePolicy(sizePolicy2);
        positive_age->setFont(font2);

        horizontalLayout_4->addWidget(positive_age);


        verticalLayout_2->addLayout(horizontalLayout_4);

        line_4 = new QFrame(Stats);
        line_4->setObjectName(QString::fromUtf8("line_4"));
        line_4->setFrameShape(QFrame::HLine);
        line_4->setFrameShadow(QFrame::Sunken);

        verticalLayout_2->addWidget(line_4);


        retranslateUi(Stats);

        QMetaObject::connectSlotsByName(Stats);
    } // setupUi

    void retranslateUi(QDialog *Stats)
    {
        Stats->setWindowTitle(QCoreApplication::translate("Stats", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("Stats", "Scegli quale statistica vuoi visualizzare tra quelle elencate in basso:", nullptr));
        label_6->setText(QCoreApplication::translate("Stats", "Per creare le statistiche in R devi generare un file .csv cliccando sul bottone in basso!", nullptr));
        pushButton->setText(QCoreApplication::translate("Stats", "GENERA", nullptr));
        label_5->setText(QCoreApplication::translate("Stats", "Andamento dei positivi in funzione del paese", nullptr));
        positive_country->setText(QCoreApplication::translate("Stats", "VAI", nullptr));
        label_2->setText(QCoreApplication::translate("Stats", "Andamento dei positivi in funzione dei mesi", nullptr));
        positive_month->setText(QCoreApplication::translate("Stats", "VAI", nullptr));
        label_4->setText(QCoreApplication::translate("Stats", "Numero di positivi in funzione dell'et\303\240", nullptr));
        positive_age->setText(QCoreApplication::translate("Stats", "VAI", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Stats: public Ui_Stats {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STATS_H
