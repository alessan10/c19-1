#include "inserisci.h"
#include "ui_inserisci.h"
#include "worker.h"

#include <QNetworkRequest>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>
#include <QVariantMap>
#include <QDebug>
#include <QUrlQuery>



Inserisci::Inserisci(Worker &worker ,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Inserisci),
    mNetManager(new QNetworkAccessManager(this)),
    mNetReply(nullptr),
    mDataBuffer(new QByteArray),
    worker(nullptr)
{
    this->worker = &worker;
    ui->setupUi(this);
    ui->calendarWidget->setLocale(QLocale(QLocale::English));
}

Inserisci::~Inserisci()
{
    delete ui;
}

void Inserisci::on_buttonBox_clicked(QAbstractButton *button)
{
    QString esito;
    QString name = ui->lineEdit->text();
    if (ui->radio_positivo->isChecked() == true && ui->radio_negativo->isChecked() == false){
        esito = "positivo";
    }else esito = "negativo";

    QString calendar = ui->calendarWidget->selectedDate().toString();
    QString month;
    QString dayOfWeek;
    switch (ui->calendarWidget->selectedDate().month())
    {
        case 1:
            month = "Jan";
        break;
        case 2:
            month = "Feb";
        break;
        case 3:
            month = "Mar";
        break;
        case 4:
            month = "Apr";
        break;
        case 5:
            month = "May";
        break;
        case 6:
            month = "Jun";
        break;
        case 7:
            month = "Jul";
        break;
        case 8:
            month = "Aug";
        break;
        case 9:
            month = "Sep";
        break;
        case 10:
            month = "Oct";
        break;
        case 11:
            month = "Nov";
        break;
        case 12:
        month = "Dec";
        break;

    }
    switch (ui->calendarWidget->selectedDate().dayOfWeek()) {
    case 1:
        dayOfWeek = "Mon";
    break;
    case 2:
        dayOfWeek = "Tue";
    break;
    case 3:
        dayOfWeek = "Wed";
    break;
    case 4:
        dayOfWeek = "Thu";
    break;
    case 5:
        dayOfWeek = "Fri";
    break;
    case 6:
        dayOfWeek = "Sat";
    break;
    case 7:
        dayOfWeek = "Sun";
    break;

    }
    qInfo() << ui->calendarWidget->selectedDate().year() << month  << ui->calendarWidget->selectedDate().day() << dayOfWeek;
    qInfo() << name << " esito: " <<esito;
}
