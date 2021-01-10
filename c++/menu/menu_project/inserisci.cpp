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
}

Inserisci::~Inserisci()
{
    delete ui;
}

void Inserisci::on_buttonBox_clicked(QAbstractButton *button)
{
    QString esito;
    QString name = ui->lineEdit->text();
    /*if (ui->radio_positivo->isChecked() == true && ui->radio_negativo->isChecked() == false){
        esito = "positivo";
    }else esito = "negativo";*/


    QString calendar = ui->calendarWidget->selectedDate().toString();

    qDebug() << "calendar: " << calendar;


}
