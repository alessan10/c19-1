#include "visualizza.h"
#include "ui_visualizza.h"

#include <QNetworkRequest>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>
#include <QVariantMap>
#include <QDebug>

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
           QString name = object["name"].toString();
           QString chatid = object["chatid"].toString();
           QString covid = object["covid"].toString();

           //ui->listWidget->addItem("["+ QString::number(i+1) + "] " + "Nome: " + name + " - ChatID: "  + chatid + " - Covid: " + covid );
           //ui->label->("["+ QString::number(i+1) + "] " + name + chatid + covid );
           //ui->label_2->setText("Dati ricevuti");
           //ui->tableView->(name +  chatid + covid);

           QString c0 = mDoc.object().value("cperson").toArray().at(i).toObject().value("name").toString();
           qDebug() << c0;

       }

    }
}
