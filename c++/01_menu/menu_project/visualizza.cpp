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

           p->setFullName(object["name"].toString());
           p->setChatId(object["chatid"].toString());
           p->setCovid(object["covid"].toString());
           p->date.setDayOfWeek(object["weekday"].toString());
           p->date.setDay(object["day"].toString());
           p->date.setMonth(object["month"].toString());
           p->date.setYear(object["year"].toString());
           p->setCountry(object["country"].toString());
           p->setAge(object["age"].toString());

           patients_list.push_back(p);

           ui->listWidget->addItem("["+ QString::number(i+1) + "] " +
                                   "Nome: " + p->getFullName() +
                                   " - ChatID: "  + p->getChatId() +
                                   " - Covid: " + p->getCovid() +
                                   " - Data: " + p->date.getDayOfWeek() + " " + p->date.getDay() + " " + p->date.getMonth() + " " + p->date.getYear() +
                                   " - Country: " + p->getCountry() +
                                   " - Age: " + p->getAge()
                                   );

           QString c0 = mDoc.object().value("patient").toArray().at(i).toObject().value("name").toString();
           qDebug() << c0;

           //string s = "ciao";
           //cout <<"s: "<< s <<endl;
       }
       delete p;

       QList<Patient*>::iterator i;
       for (i = patients_list.begin(); i != patients_list.end(); ++i){
            (*i)->toString();
       }
    }   
}
