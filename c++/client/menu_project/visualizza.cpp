#include "visualizza.h"
#include "ui_visualizza.h"
#include "classes.h"

#include <QNetworkRequest>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>
#include <QVariantMap>
#include <QDebug>
#include <QList>
#include <iostream>
#include <QFile>

#include <QTabWidget>

using namespace std;

Visualizza::Visualizza(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Visualizza),
    mNetManager(new QNetworkAccessManager(this)),
    mNetReply(nullptr),
    mDataBuffer(new QByteArray)
{
    ui->setupUi(this);

    QStringList headers;
    headers << "ID" << "Nome" << "Cognome" << "Età" << "ChatID" << "Covid" << "Anno" << "Mese" << "Giorno" << "Giorno della settimana" << "Paese";
    ui->table->setColumnCount(11);
    ui->table->setHorizontalHeaderLabels(headers);
}

Visualizza::~Visualizza()
{
    delete ui;
}

void Visualizza::on_pushButton_clicked()
{
    //Initialize our API data
    const QUrl API_ENDPOINT("http://localhost:8081/graph");
    QNetworkRequest request;
    request.setUrl(API_ENDPOINT);

    mNetReply = mNetManager->get(request);
    connect(mNetReply,&QIODevice::readyRead,this,&Visualizza::dataReadyRead);
    connect(mNetReply,&QNetworkReply::finished,this,&Visualizza::dataReadFinished);

}

void Visualizza::dataReadyRead()
{
    mDataBuffer->append(mNetReply->readAll());
}

void Visualizza::dataReadFinished()
{
    if( mNetReply->error())
    {
        qDebug() << "Error : " << mNetReply->errorString();
    }
    else
    {
       qDebug() << "Data fetch finished : " << QString(*mDataBuffer);

       QJsonDocument mDoc;
       mDoc = QJsonDocument::fromJson(*mDataBuffer);

       qDebug() << mDoc.object().value("patient").toArray().size();

      //Turn document into json array
       QJsonArray array = mDoc.array();
       QList<Patient *> patients_list;
       Patient *p = new Patient();

       for ( int i = 0; i < array.size(); i++)
       {
           QJsonObject object = array.at(i).toObject().value("patient").toObject();

           Patient *p = new Patient(
               object["id"].toString(),
               object["name"].toString(),
               object["surname"].toString(),
               object["age"].toString(),
               object["chatId"].toString(),
               object["covid"].toString(),
               object["year"].toString(),
               object["month"].toString(),
               object["day"].toString(),
               object["weekday"].toString(),
               object["country"].toString()
           );

           patients_list.push_back(p);

           //
           QString tmpPatient =
                   "Id: " + p->getId() +
                   " - Nome: " + p->getName() +
                   " - Cognome: " + p->getSurname() +
                   " - Age: " + p->getAge() +
                   " - ChatID: "  + p->getChatId() +
                   " - Covid: " + p->getCovid() +
                   " - Data: " + p->date.getYear() + " " + p->date.getMonth() + " " + p->date.getDay() + " " + p->date.getDayOfWeek() +
                   " - Country: " + p->getCountry();

           ui->table->insertRow(ui->table->rowCount());
           int row = ui->table->rowCount() -1;

           ui->table->setItem(row, ID, new QTableWidgetItem(p->getId()));

           ui->table->setItem(row, Nome, new QTableWidgetItem(p->getName()));

           ui->table->setItem(row, Cognome, new QTableWidgetItem(p->getSurname()));

           ui->table->setItem(row, Eta, new QTableWidgetItem(p->getAge()));

           ui->table->setItem(row, ChatID, new QTableWidgetItem(p->getChatId()));

           ui->table->setItem(row, Covid, new QTableWidgetItem(p->getCovid()));

           ui->table->setItem(row, Anno, new QTableWidgetItem(p->date.getYear()));

           ui->table->setItem(row, Mese, new QTableWidgetItem(p->date.getMonth()));

           ui->table->setItem(row, Giorno, new QTableWidgetItem(p->date.getDay()));

           ui->table->setItem(row, Giorno_della_settimana, new QTableWidgetItem(p->date.getDayOfWeek()));

           ui->table->setItem(row, Paese, new QTableWidgetItem(p->getCountry()));

       }
       delete p;

    }   
}
