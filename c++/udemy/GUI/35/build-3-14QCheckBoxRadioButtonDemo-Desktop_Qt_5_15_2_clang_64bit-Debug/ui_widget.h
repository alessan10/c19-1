/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout;
    QCheckBox *windowsCheckbox;
    QCheckBox *macCheckBox;
    QCheckBox *linuxCheckBox;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout_2;
    QCheckBox *beerCheckBox;
    QCheckBox *juiceCheckBox;
    QCheckBox *cofeeCheckBox;
    QGroupBox *groupBox_3;
    QVBoxLayout *verticalLayout_3;
    QRadioButton *aRadioButton;
    QRadioButton *bRadioButton;
    QRadioButton *cRadioButton;
    QPushButton *grabData;
    QPushButton *setStateButton;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(455, 369);
        verticalLayout_4 = new QVBoxLayout(Widget);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        groupBox = new QGroupBox(Widget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        verticalLayout = new QVBoxLayout(groupBox);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        windowsCheckbox = new QCheckBox(groupBox);
        windowsCheckbox->setObjectName(QString::fromUtf8("windowsCheckbox"));

        verticalLayout->addWidget(windowsCheckbox);

        macCheckBox = new QCheckBox(groupBox);
        macCheckBox->setObjectName(QString::fromUtf8("macCheckBox"));

        verticalLayout->addWidget(macCheckBox);

        linuxCheckBox = new QCheckBox(groupBox);
        linuxCheckBox->setObjectName(QString::fromUtf8("linuxCheckBox"));

        verticalLayout->addWidget(linuxCheckBox);


        horizontalLayout->addWidget(groupBox);

        groupBox_2 = new QGroupBox(Widget);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        verticalLayout_2 = new QVBoxLayout(groupBox_2);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        beerCheckBox = new QCheckBox(groupBox_2);
        beerCheckBox->setObjectName(QString::fromUtf8("beerCheckBox"));

        verticalLayout_2->addWidget(beerCheckBox);

        juiceCheckBox = new QCheckBox(groupBox_2);
        juiceCheckBox->setObjectName(QString::fromUtf8("juiceCheckBox"));

        verticalLayout_2->addWidget(juiceCheckBox);

        cofeeCheckBox = new QCheckBox(groupBox_2);
        cofeeCheckBox->setObjectName(QString::fromUtf8("cofeeCheckBox"));

        verticalLayout_2->addWidget(cofeeCheckBox);


        horizontalLayout->addWidget(groupBox_2);


        verticalLayout_4->addLayout(horizontalLayout);

        groupBox_3 = new QGroupBox(Widget);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        verticalLayout_3 = new QVBoxLayout(groupBox_3);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        aRadioButton = new QRadioButton(groupBox_3);
        aRadioButton->setObjectName(QString::fromUtf8("aRadioButton"));

        verticalLayout_3->addWidget(aRadioButton);

        bRadioButton = new QRadioButton(groupBox_3);
        bRadioButton->setObjectName(QString::fromUtf8("bRadioButton"));

        verticalLayout_3->addWidget(bRadioButton);

        cRadioButton = new QRadioButton(groupBox_3);
        cRadioButton->setObjectName(QString::fromUtf8("cRadioButton"));

        verticalLayout_3->addWidget(cRadioButton);


        verticalLayout_4->addWidget(groupBox_3);

        grabData = new QPushButton(Widget);
        grabData->setObjectName(QString::fromUtf8("grabData"));

        verticalLayout_4->addWidget(grabData);

        setStateButton = new QPushButton(Widget);
        setStateButton->setObjectName(QString::fromUtf8("setStateButton"));

        verticalLayout_4->addWidget(setStateButton);


        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "Widget", nullptr));
        groupBox->setTitle(QCoreApplication::translate("Widget", "Choose OS(Exlusive)", nullptr));
        windowsCheckbox->setText(QCoreApplication::translate("Widget", "Windows", nullptr));
        macCheckBox->setText(QCoreApplication::translate("Widget", "Mac", nullptr));
        linuxCheckBox->setText(QCoreApplication::translate("Widget", "Linux", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("Widget", "Choose Drink ( Non Exclusive", nullptr));
        beerCheckBox->setText(QCoreApplication::translate("Widget", "Beer", nullptr));
        juiceCheckBox->setText(QCoreApplication::translate("Widget", "Juice", nullptr));
        cofeeCheckBox->setText(QCoreApplication::translate("Widget", "Cofee", nullptr));
        groupBox_3->setTitle(QCoreApplication::translate("Widget", "Choose Answer", nullptr));
        aRadioButton->setText(QCoreApplication::translate("Widget", "A", nullptr));
        bRadioButton->setText(QCoreApplication::translate("Widget", "B", nullptr));
        cRadioButton->setText(QCoreApplication::translate("Widget", "C", nullptr));
        grabData->setText(QCoreApplication::translate("Widget", "Grab data", nullptr));
        setStateButton->setText(QCoreApplication::translate("Widget", "Set State", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
