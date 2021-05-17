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

using namespace std;

Visualizza::Visualizza(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Visualizza),
    mNetManager(new QNetworkAccessManager(this)),
    mNetReply(nullptr),
    mDataBuffer(new QByteArray)
{
    ui->setupUi(this);
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

       //Turn the data into a json document
       //QJsonDocument doc = QJsonDocument::fromJson(*mDataBuffer);

       QJsonDocument mDoc;
       mDoc = QJsonDocument::fromJson(*mDataBuffer);

       qDebug() << mDoc.object().value("patient").toArray().size();

       /*
       //What if you get an object from the server
       QJsonDocument objectDoc = QJsonDocument::fromJson(*mDataBuffer);
       QJsonObject obObject = objectDoc.toVariant().toJsonObject();
       */


       //Turn document into json array

       QJsonArray array = mDoc.array();
       QList<Patient *> patients_list;
       Patient *p = new Patient();

       for ( int i = 0; i < array.size(); i++)
       {
           //QJsonObject object = array.at(i).toObject();
           //QJsonObject object1 = object["cperson"].toObject();

           QJsonObject object = array.at(i).toObject().value("patient").toObject();

           /*p->setFullName(object["name"].toString());
           p->setChatId(object["chatid"].toString());
           p->setCovid(object["covid"].toString());
           p->date.setDayOfWeek(object["weekday"].toString());
           p->date.setDay(object["day"].toString());
           p->date.setMonth(object["month"].toString());
           p->date.setYear(object["year"].toString());
           p->setCountry(object["country"].toString());
           p->setAge(object["age"].toString());*/

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
           //

           ui->listWidget->addItem("["+ QString::number(i+1) + "] " +
                                   "Id: " + p->getId() +
                                   " - Nome: " + p->getName() +
                                   " - Cognome: " + p->getSurname() +
                                   " - Age: " + p->getAge() +
                                   " - ChatID: "  + p->getChatId() +
                                   " - Covid: " + p->getCovid() +
                                   " - Data: " + p->date.getYear() + " " + p->date.getMonth() + " " + p->date.getDay() + " " + p->date.getDayOfWeek() +
                                   " - Country: " + p->getCountry()
                                   );

           QString c0 = mDoc.object().value("patient").toArray().at(i).toObject().value("name").toString();
           qDebug() << c0;

       }
       delete p;

       QList<Patient*>::iterator i;
       for (i = patients_list.begin(); i != patients_list.end(); ++i){
            (*i)->toString();
       }


       QFile file("C:/Users/alexm/Downloads/out.csv");
       if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
           return;
       QTextStream out(&file);
       QString stringa = "\"Country\",\"Weekday\",\"Giorno\",\"Mese\",\"Anno\",\"Covid\",\"ChatId\",\"Age\",\"Cognome\",\"Nome\",\"Id\""; //sintassi comprensibile da R: \"text\"
       out << stringa <<"\n";

       //int counter = 0;
       for (i = patients_list.begin(); i != patients_list.end(); ++i){
           //counter ++;
           qDebug() << "toR: " << (*i)->toR() << " toR end";
           out << (*i)->toR() << "\n";
       }
       file.close();
    }   
}
// \"""\",
// "\"" << "\"," <<
