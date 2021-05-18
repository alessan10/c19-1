#include "modifica.h"
#include "ui_modifica.h"
#include "worker.h"
#include "classes.h"

#include <QNetworkRequest>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>
#include <QVariantMap>
#include <QDebug>
#include <QUrlQuery>
#include <QMessageBox>
#include <QPushButton>
#include <QDate>
#include <QStringBuilder>

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
        QMessageBox::warning(this,"Attenzione","Non è stato trovato nessun utente!", QMessageBox::Ok);
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
            QJsonObject object = array.at(i).toObject().value("patient").toObject();

            QString name = object["name"].toString();
            QString surname = object["surname"].toString();
            QString age = object["age"].toString();
            QString covid = object["covid"].toString();
            QString year = object["year"].toString();
            QString month = object["month"].toString();
            QString day = object["day"].toString();
            QString weekday = object["weekday"].toString();
            QString country = object["country"].toString();

            //QString c0 = mDoc.object().value("patient").toArray().at(i).toObject().value("name").toString();
            //qDebug() << c0;

            ui->new_nome->setText(name);
            ui->new_cognome->setText(surname);
            ui->new_eta->setText(age);
            ui->new_paese->setText(country);

            int iday = day.toInt() -1;
            ui->new_day->setCurrentIndex(iday);

            ui->new_month->setCurrentText(month);
            ui->new_year->setCurrentText(year);
            ui->new_weekday->setCurrentText(weekday);

            ui->new_covid->setCurrentText(covid);

        }
    }
}

void Modifica::on_button_modifica_clicked()
{
    Patient p;

    QString new_name = ui->new_nome->text();
    QString new_surname = ui->new_cognome->text();

    p.setName(new_name);
    p.setSurname(new_surname);

    p.getName();
    p.getSurname();

    //qDebug() << "New name: " << p.getName();
    //qDebug() << "New surname: " << p.getSurname();

    QString new_age = ui->new_eta->text();
    p.setAge(new_age);

    QString new_country = ui->new_paese->text();
    p.setCountry(new_country);

    QString new_year = ui->new_year->currentText();
    p.date.setYear(new_year);
    QString new_month = ui->new_month->currentText();
    p.date.setMonth(new_month);
    QString new_day = ui->new_day->currentText();
    p.date.setDay(new_day);
    QString new_weekday = ui->new_weekday->currentText();
    p.date.setDayOfWeek(new_weekday);

    QString new_covid = ui->new_covid->currentText();
    p.setCovid(new_covid);

    QJsonObject json;
    //json["id"] = QString(p.getId());
    json["name"] = QString(p.getName());
    json["surname"] = QString(p.getSurname());
    json["age"] =QString(p.getAge());
    //json["chatid"] = QString(p.getChatId());
    json["covid"] =QString(p.getCovid());
    json["year"] =QString(p.date.getYear());
    json["month"] = QString(p.date.getMonth());
    json["day"] = QString(p.date.getDay());
    json["weekday"] =QString(p.date.getDayOfWeek());
    json["country"] =QString(p.getCountry());

    qDebug() << "new data: " << json;

    QJsonDocument doc(json);
    QByteArray data = doc.toJson();

    QNetworkAccessManager *mgr = new QNetworkAccessManager(this);
    const QUrl url(QStringLiteral("http://localhost:8081/update"));
    QNetworkRequest request(url);
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    QNetworkReply *reply = mgr->post(request, data);

    QObject::connect(reply, &QNetworkReply::finished, [=]()
    {
        if(reply->error() == QNetworkReply::NoError)
        {
            QString contents = QString::fromUtf8(reply->readAll());
            qDebug() << contents;
            //se non ci sono errori mostra un dialog
            QMessageBox::information(this,"Info","I dati dell'utente sono stati modificati correttamente.", QMessageBox::Ok);
        }
        else
        {
            QString err = reply->errorString();
            QMessageBox::warning(this,"Attenzione","Update fallito.", QMessageBox::Ok);
            qDebug() << err;
        }
        reply->deleteLater();
    });
    cleanUp();

}

void Modifica::cleanUp(){
    this->ui->nome->setText("");
    this->ui->cognome->setText("");

    this->ui->new_nome->setText("");
    this->ui->new_cognome->setText("");
    this->ui->new_eta->setText("");
    this->ui->new_paese->setText("");

    this->ui->new_day->clear();
    this->ui->new_month->clear();
    this->ui->new_year->clear();
    this->ui->new_weekday->clear();
    this->ui->new_covid->clear();
}
