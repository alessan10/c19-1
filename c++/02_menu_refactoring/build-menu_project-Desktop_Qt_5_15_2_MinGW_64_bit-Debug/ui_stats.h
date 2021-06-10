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
#include <QtWidgets/QComboBox>
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
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_6;
    QHBoxLayout *horizontalLayout;
    QPushButton *generateButton;
    QFrame *line_3;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_5;
    QPushButton *positive_country;
    QFrame *line;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_2;
    QComboBox *year_comboBox;
    QPushButton *positive_year;
    QFrame *line_2;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_4;
    QPushButton *positive_age;
    QFrame *line_4;
    QPushButton *pushButton;
    QLabel *imageLabel;

    void setupUi(QDialog *Stats)
    {
        if (Stats->objectName().isEmpty())
            Stats->setObjectName(QString::fromUtf8("Stats"));
        Stats->resize(976, 794);
        verticalLayout_2 = new QVBoxLayout(Stats);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(7);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalLayout_5->setSizeConstraint(QLayout::SetDefaultConstraint);
        horizontalLayout_5->setContentsMargins(-1, -1, -1, 0);
        label_6 = new QLabel(Stats);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_6->sizePolicy().hasHeightForWidth());
        label_6->setSizePolicy(sizePolicy);
        QFont font;
        font.setPointSize(14);
        label_6->setFont(font);
        label_6->setAlignment(Qt::AlignCenter);

        horizontalLayout_5->addWidget(label_6);


        verticalLayout_2->addLayout(horizontalLayout_5);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        generateButton = new QPushButton(Stats);
        generateButton->setObjectName(QString::fromUtf8("generateButton"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(generateButton->sizePolicy().hasHeightForWidth());
        generateButton->setSizePolicy(sizePolicy1);
        QFont font1;
        font1.setPointSize(16);
        generateButton->setFont(font1);
        generateButton->setLayoutDirection(Qt::RightToLeft);
        generateButton->setAutoFillBackground(false);
        generateButton->setIconSize(QSize(50, 50));
        generateButton->setFlat(false);

        horizontalLayout->addWidget(generateButton);


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
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(label_5->sizePolicy().hasHeightForWidth());
        label_5->setSizePolicy(sizePolicy2);
        QFont font2;
        font2.setPointSize(12);
        label_5->setFont(font2);
        label_5->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(label_5);

        positive_country = new QPushButton(Stats);
        positive_country->setObjectName(QString::fromUtf8("positive_country"));
        sizePolicy1.setHeightForWidth(positive_country->sizePolicy().hasHeightForWidth());
        positive_country->setSizePolicy(sizePolicy1);
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
        sizePolicy2.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy2);
        label_2->setFont(font2);
        label_2->setAlignment(Qt::AlignCenter);

        horizontalLayout_3->addWidget(label_2);

        year_comboBox = new QComboBox(Stats);
        year_comboBox->addItem(QString());
        year_comboBox->addItem(QString());
        year_comboBox->setObjectName(QString::fromUtf8("year_comboBox"));
        sizePolicy1.setHeightForWidth(year_comboBox->sizePolicy().hasHeightForWidth());
        year_comboBox->setSizePolicy(sizePolicy1);
        year_comboBox->setFont(font2);

        horizontalLayout_3->addWidget(year_comboBox);

        positive_year = new QPushButton(Stats);
        positive_year->setObjectName(QString::fromUtf8("positive_year"));
        sizePolicy1.setHeightForWidth(positive_year->sizePolicy().hasHeightForWidth());
        positive_year->setSizePolicy(sizePolicy1);
        positive_year->setFont(font2);

        horizontalLayout_3->addWidget(positive_year);


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
        sizePolicy2.setHeightForWidth(label_4->sizePolicy().hasHeightForWidth());
        label_4->setSizePolicy(sizePolicy2);
        label_4->setFont(font2);
        label_4->setAlignment(Qt::AlignCenter);

        horizontalLayout_4->addWidget(label_4);

        positive_age = new QPushButton(Stats);
        positive_age->setObjectName(QString::fromUtf8("positive_age"));
        sizePolicy1.setHeightForWidth(positive_age->sizePolicy().hasHeightForWidth());
        positive_age->setSizePolicy(sizePolicy1);
        positive_age->setFont(font2);

        horizontalLayout_4->addWidget(positive_age);


        verticalLayout_2->addLayout(horizontalLayout_4);

        line_4 = new QFrame(Stats);
        line_4->setObjectName(QString::fromUtf8("line_4"));
        line_4->setFrameShape(QFrame::HLine);
        line_4->setFrameShadow(QFrame::Sunken);

        verticalLayout_2->addWidget(line_4);

        pushButton = new QPushButton(Stats);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        verticalLayout_2->addWidget(pushButton);

        imageLabel = new QLabel(Stats);
        imageLabel->setObjectName(QString::fromUtf8("imageLabel"));
        sizePolicy1.setHeightForWidth(imageLabel->sizePolicy().hasHeightForWidth());
        imageLabel->setSizePolicy(sizePolicy1);
        imageLabel->setMinimumSize(QSize(800, 550));
        imageLabel->setFrameShape(QFrame::Box);
        imageLabel->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(imageLabel);


        retranslateUi(Stats);

        generateButton->setDefault(false);


        QMetaObject::connectSlotsByName(Stats);
    } // setupUi

    void retranslateUi(QDialog *Stats)
    {
        Stats->setWindowTitle(QCoreApplication::translate("Stats", "Dialog", nullptr));
        label_6->setText(QCoreApplication::translate("Stats", "Per creare le statistiche in R devi prima generare un file in fomrato .csv cliccando sul bottone \"GENERA\"!", nullptr));
        generateButton->setText(QCoreApplication::translate("Stats", "Genera", nullptr));
        label_5->setText(QCoreApplication::translate("Stats", "Andamento dei positivi in funzione del paese", nullptr));
        positive_country->setText(QCoreApplication::translate("Stats", "VAI", nullptr));
        label_2->setText(QCoreApplication::translate("Stats", "Andamento dei positivi in base all'anno", nullptr));
        year_comboBox->setItemText(0, QCoreApplication::translate("Stats", "2020", nullptr));
        year_comboBox->setItemText(1, QCoreApplication::translate("Stats", "2021", nullptr));

        positive_year->setText(QCoreApplication::translate("Stats", "VAI", nullptr));
        label_4->setText(QCoreApplication::translate("Stats", "Andamento dei positivi in funzione dell'et\303\240", nullptr));
        positive_age->setText(QCoreApplication::translate("Stats", "VAI", nullptr));
        pushButton->setText(QCoreApplication::translate("Stats", "PROVA", nullptr));
        imageLabel->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Stats: public Ui_Stats {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STATS_H
