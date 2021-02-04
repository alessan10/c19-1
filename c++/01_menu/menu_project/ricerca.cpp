#include "ricerca.h"
#include "ui_ricerca.h"
#include "worker.h"

#include <QNetworkRequest>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>
#include <QVariantMap>
#include <QDebug>
#include <QUrlQuery>
#include <QMessageBox>

Ricerca::Ricerca(Worker &worker , QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Ricerca),
    mNetManager(new QNetworkAccessManager(this)),
    mNetReply(nullptr),
    mDataBuffer(new QByteArray),
    worker(nullptr)
{
    this->worker = &worker;
    ui->setupUi(this);
}

Ricerca::~Ricerca()
{
    delete ui;
}
/*
void Ricerca::on_pushButton_clicked()
{
    //QString name = "Kian";
    //QString surname = "Kemmer";
    worker->get("http://localhost:8081/search?name=Kian%20Kemmer");
    //worker.get("http://localhost:8081/search?name="+name+"%20"+surname);
    connect(mNetReply,&QIODevice::readyRead,this,&Ricerca::dataReadyRead);
    connect(mNetReply,&QNetworkReply::finished,this,&Ricerca::dataReadFinished);
}*/

void Ricerca::on_pushButton_clicked()
{
    ui->listWidget->clear();
    QString name = ui->nome->text();
    QString surname = ui->cognome->text();

    if (ui->nome->text().isEmpty() || ui->cognome->text().isEmpty()){

        QMessageBox::warning(this,"Attenzione","Inserisci nome e cognome.", QMessageBox::Ok);

    }else{

        //Initialize our API data
        const QUrl API_ENDPOINT("http://localhost:8081/search?name="+name+"%20"+surname);
        QNetworkRequest request;
        request.setUrl(API_ENDPOINT);

        mNetReply = mNetManager->get(request);
        connect(mNetReply,&QIODevice::readyRead,this,&Ricerca::dataReadyRead);
        connect(mNetReply,&QNetworkReply::finished,this,&Ricerca::dataReadFinished);
    }
}


void Ricerca::dataReadyRead()
{
    mDataBuffer->append(mNetReply->readAll());
}


void Ricerca::dataReadFinished()
{
    if( mNetReply->error())
    {
        qDebug() << "Error : " << mNetReply->errorString();
    }else
    {
       qDebug() << "Data fetch finished : " << QString(*mDataBuffer);

       //Turn the data into a json document
       //QJsonDocument doc = QJsonDocument::fromJson(*mDataBuffer);

       QJsonDocument mDoc;
       mDoc = QJsonDocument::fromJson(*mDataBuffer);

       qDebug() << mDoc.object().value("cperson").toArray().size();

       /*
       //What if you get an object from the server
       QJsonDocument objectDoc = QJsonDocument::fromJson(*mDataBuffer);
       QJsonObject obObject = objectDoc.toVariant().toJsonObject();
       */


       //Turn document into json array

       QJsonArray array = mDoc.array();

       for ( int i = 0; i < array.size(); i++)
       {

           //QJsonObject object = array.at(i).toObject();
           //QJsonObject object1 = object["cperson"].toObject();

           QJsonObject object = array.at(i).toObject().value("cperson").toObject();
           QString fullname = object["name"].toString();
           QString chatid = object["chatid"].toString();
           QString covid = object["covid"].toString();
           QString weekday = object["weekday"].toString();
           QString day = object["day"].toString();
           QString month = object["month"].toString();
           QString year = object["year"].toString();

           ui->listWidget->addItem("["+ QString::number(i+1) + "] " + "Nome: " + fullname + " - ChatID: "  + chatid + " - Covid: " + covid + " - Data: " + weekday + " " + day + " " + month + " " + year);
           //ui->label->("["+ QString::number(i+1) + "] " + name + chatid + covid );
           //ui->label_2->setText("Dati ricevuti");
           //ui->tableView->(name +  chatid + covid);
            //rimetti qtableview
           QString c0 = mDoc.object().value("cperson").toArray().at(i).toObject().value("name").toString();
           qDebug() << c0;

       }

    }
}

void Ricerca::on_button_elimina_clicked()
{
    QString name = ui->nome->text();
    QString surname = ui->cognome->text();

    //Initialize our API data
    const QUrl API_ENDPOINT("http://localhost:8081/delete?name="+name+"%20"+surname);
    QNetworkRequest request;
    request.setUrl(API_ENDPOINT);

    mNetReply = mNetManager->get(request);
    connect(mNetReply,&QIODevice::readyRead,this,&Ricerca::dataReadyRead);
    connect(mNetReply,&QNetworkReply::finished,this,&Ricerca::dataReadFinished);
}
