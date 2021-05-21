#include "stats.h"
#include "ui_stats.h"

//#include "stdafx.h"
#include <QNetworkRequest>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>
#include <QVariantMap>
#include <QDebug>
#include <QList>
#include <iostream>
#include <QFile>
#include <QMessageBox>
using namespace std;

Stats::Stats(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Stats),
    mNetManager(new QNetworkAccessManager(this)),
    mNetReply(nullptr),
    mDataBuffer(new QByteArray)
{
    ui->setupUi(this);
}

Stats::~Stats()
{
    delete ui;
}

void Stats::on_generateButton_clicked()
{

    const QUrl API_ENDPOINT("http://localhost:8081/graph");
    QNetworkRequest request;
    request.setUrl(API_ENDPOINT);

    mNetReply = mNetManager->get(request);
    connect(mNetReply,&QIODevice::readyRead,this,&Stats::dataReadyRead);
    connect(mNetReply,&QNetworkReply::finished,this,&Stats::dataReadFinished);

}

void Stats::dataReadyRead()
{
    mDataBuffer->append(mNetReply->readAll());
}

void Stats::dataReadFinished()
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

           QString stringa =
                   "Id: " + p->getId() +
                   " - Nome: " + p->getName() +
                   " - Cognome: " + p->getSurname() +
                   " - Age: " + p->getAge() +
                   " - ChatID: "  + p->getChatId() +
                   " - Covid: " + p->getCovid() +
                   " - Data: " + p->date.getYear() + " " + p->date.getMonth() + " " + p->date.getDay() + " " + p->date.getDayOfWeek() +
                   " - Country: " + p->getCountry();

           qDebug() << "My string: \n" << stringa << "\n End my string \n";

           QString c0 = mDoc.object().value("patient").toArray().at(i).toObject().value("name").toString();
           qDebug() << c0;

       }
       delete p;

       QList<Patient*>::iterator i;
       for (i = patients_list.begin(); i != patients_list.end(); ++i){
            (*i)->toString();
       }


       QFile file("C:/Users/alexm/Downloads/out.csv");
       if (!file.open(QIODevice::WriteOnly | QIODevice::Text)){
           QMessageBox::warning(this, "Attenzione", "Non è stato possibile generare il file!",
                                QMessageBox::Close);
           return;
       } else {
           QMessageBox::information(this, "Attenzione", "Il file è stato creato correttamente!",
                                    QMessageBox::Ok);
           QTextStream out(&file);
           QString stringa = "\"Country\",\"Weekday\",\"Anno\",\"Mese\",\"Giorno\",\"ChatId\",\"Covid\",\"Age\",\"Cognome\",\"Nome\",\"Id\""; //sintassi comprensibile da R: \"text\"
           //QString stringa = "\"Country\",\"Weekday\",\"Giorno\",\"Mese\",\"Anno\",\"Covid\",\"ChatId\",\"Age\",\"Cognome\",\"Nome\",\"Id\""; //sintassi comprensibile da R: \"text\"
           out << stringa <<"\n";

           for (i = patients_list.begin(); i != patients_list.end(); ++i){
               qDebug() << "toR: " << (*i)->toR() << " toR end";
               out << (*i)->toR() << "\n";
           }
           file.close();
       }



    }
}
// \"""\",
// "\"" << "\"," <<
