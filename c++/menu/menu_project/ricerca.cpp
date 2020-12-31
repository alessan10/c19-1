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

Ricerca::Ricerca(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Ricerca),
    mNetManager(new QNetworkAccessManager(this)),
    mNetReply(nullptr),
    mDataBuffer(new QByteArray)
{
    ui->setupUi(this);
}

Ricerca::~Ricerca()
{
    delete ui;
}

void Ricerca::on_pushButton_clicked()
{
    //QCoreApplication a(argc, argv);

    Worker worker;

    worker.get("http://localhost:8081/search?name=Odie%20Von");

    //QByteArray data;
    //data.append("name=Odie%20Von");
    //data.append("&");
    //data.append("param2=Von");

   // worker.post("http://localhost:8081/search",data);


    //return a.exec();

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

       QJsonDocument mDoc;
       mDoc = QJsonDocument::fromJson(*mDataBuffer);

       qDebug() << mDoc.object().value("cperson").toArray().size();

       //Turn document into json array
       QJsonArray array = mDoc.array();

       for ( int i = 0; i < array.size(); i++)
       {
           QJsonObject object = array.at(i).toObject().value("cperson").toObject();
           QString name = object["name"].toString();
           QString chatid = object["chatid"].toString();
           QString covid = object["covid"].toString();

           ui->listWidget->addItem("["+ QString::number(i+1) + "] " + "Nome: " + name + " - ChatID: "  + chatid + " - Covid: " + covid );
           //ui->label->("["+ QString::number(i+1) + "] " + name + chatid + covid );
           //ui->label_2->setText("Dati ricevuti");
           //ui->tableView->(name +  chatid + covid);

           QString c0 = mDoc.object().value("cperson").toArray().at(i).toObject().value("name").toString();
           qDebug() << c0;

       }

    }
}
