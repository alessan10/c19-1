#include "modifica.h"
#include "ui_modifica.h"
#include "worker.h"

#include <QNetworkRequest>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>
#include <QVariantMap>
#include <QDebug>
#include <QUrlQuery>
#include <QMessageBox>

Modifica::Modifica(Worker &worker, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Modifica),
    mNetManager(new QNetworkAccessManager(this)),
    mNetReply(nullptr),
    mDataBuffer(new QByteArray),
    worker(nullptr)
{
    this->worker = &worker;
    ui->setupUi(this);
}

Modifica::~Modifica()
{
    delete ui;
}

void Modifica::on_pushButton_clicked()
{
    QString name = ui->nome->text();
    QString surname = ui->cognome->text();

    if (ui->nome->text().isEmpty() || ui->cognome->text().isEmpty())
    {
        QMessageBox::warning(this,"Attenzione","Inserisci nome e cognome.", QMessageBox::Ok);

    }
    else
    {
        //Initialize our API data
        const QUrl API_ENDPOINT("http://localhost:8081/simplesearch?name="+name+"&surname="+surname);
        QNetworkRequest request;
        request.setUrl(API_ENDPOINT);

        mNetReply = mNetManager->get(request);
        connect(mNetReply,&QIODevice::readyRead,this,&Modifica::dataReadyRead);
        connect(mNetReply,&QNetworkReply::finished,this,&Modifica::dataReadFinished);
    }

    //QLineEdit *new_name = new QLineEdit(this);
    //new_name->setPlaceholderText(name);

    //ui->new_name->text() = name
}

void Modifica::dataReadyRead()
{
    mDataBuffer->append(mNetReply->readAll());
}

void Modifica::dataReadFinished()
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

        for ( int i = 0; i < array.size(); i++)
        {
            //QJsonObject object = array.at(i).toObject();
            //QJsonObject object1 = object["patient"].toObject();

            QJsonObject object = array.at(i).toObject().value("patient").toObject();
            //QString id = object["id"].toString();
            QString name = object["name"].toString();
            QString surname = object["surname"].toString();
            QString age = object["age"].toString();
            QString chatid = object["chatid"].toString();
            QString covid = object["covid"].toString();
            QString year = object["year"].toString();
            QString month = object["month"].toString();
            QString day = object["day"].toString();
            QString weekday = object["weekday"].toString();
            QString country = object["country"].toString();

            QString c0 = mDoc.object().value("patient").toArray().at(i).toObject().value("name").toString();
            qDebug() << c0;

            ui->new_nome->setText(name);
            ui->new_cognome->setText(surname);
            ui->new_eta->setText(age);

            ui->new_paese->setText(country);

        }
    }
}
//https://stackoverflow.com/questions/26504626/custom-placeholder-in-qlineedit
/*nome e cognome da fullname
ui->new_cognome->text() = cognome;
ui->new_nome->text() = nome;
ui->new_eta = age;
ui->new_paese->text()=country;
ui->new_day = data->day;
ui->new_month = data->month;
ui->new_year = data->year;
ui->new_weekday = data->weekday;
ui->new_covid = covid;
set as placeholder;*/
