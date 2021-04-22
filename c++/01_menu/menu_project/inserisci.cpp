#include "inserisci.h"
#include "ui_inserisci.h"
#include "worker.h"
#include "date.h"

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

void Inserisci::on_save_button_clicked(QAbstractButton *button)
{

    if (ui->nome->text().isEmpty() || ui->cognome->text().isEmpty() ||
            (!ui->radio_positivo->isChecked()) && (!ui->radio_negativo->isChecked()) ||
            ui->calendar->selectedDate().isNull() ||
            ui->eta->text().isEmpty() ||
            ui->paese->text().isEmpty())
    {
        int ret = QMessageBox::warning(this,"Attenzione","Inserisci tutti i campi.",
                                        QMessageBox::Ok);

        if ( ret == QMessageBox::Ok)
        {
            qDebug() << "User clicked on OK";
        }


    }
    else
    {
        QString name = ui->nome->text();
        name.replace(" ",""); //rimuoviamo eventuali spazi
        QString surname = ui->cognome->text();
        surname.replace(" ",""); //rimuoviamo eventuali spazi

        QString fullname = name+" "+surname;
        qDebug() << "Fullname" <<fullname;
        QString covid;

        ui->radio_positivo->isChecked()? covid = "positivo" : covid = "negativo";

        QDate calend = ui->calendar->selectedDate() ;
        QDate &cld = calend;
        date.conversion(cld);

        QString country = ui->paese->text();

        QString age = ui->eta->text();

        qDebug() << "Inserisci::save -->  NOME = " <<  name;
        qDebug() << "Inserisci::save -->  COGNOME = " <<  surname;
        qDebug() << "Inserisci::save --> COVID = " << covid;
        qDebug() << "Inserisci::save --> Giorno = " << date.day;
        qDebug() << "Inserisci::save --> Mese = " << date.month;
        qDebug() << "Inserisci::save --> Anno = " << date.year;
        qDebug() << "Inserisci::save --> Paese = " << country;
        qDebug() << "Inserisci::save --> Eta = " << age;

        cleanUp();

        QJsonObject json;
        json["name"] = QString(fullname);
        json["chatid"] = QString("-");
        json["covid"] =QString(covid);
        json["weekday"] =QString(date.dayOfWeek);
        json["day"] = QString(date.day);
        json["month"] = QString(date.month);
        json["year"] =QString(date.year);
        json["country"] =QString(country);
        json["age"] =QString(age);

        qDebug() << json;
        QJsonDocument doc(json);
        QByteArray data = doc.toJson();

        QNetworkAccessManager *mgr = new QNetworkAccessManager(this);
        const QUrl url(QStringLiteral("http://localhost:8081/add"));
        QNetworkRequest request(url);
        request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

//        QByteArray data("{\"name\":\"value1\",\"covid\":\"value2\"}");
        QNetworkReply *reply = mgr->post(request, data);

        QObject::connect(reply, &QNetworkReply::finished, [=]()
        {
            if(reply->error() == QNetworkReply::NoError)
            {
                QString contents = QString::fromUtf8(reply->readAll());
                qDebug() << contents;
                //se non ci sono errori mostra un dialog
                QMessageBox::information(this,"Info","Utente inserito con successo.", QMessageBox::Ok);
            }
            else
            {
                QString err = reply->errorString();
                qDebug() << err;
            }
            reply->deleteLater();
        });
    }
}

void Inserisci::cleanUp(){
    this->ui->nome->setText("");
    this->ui->cognome->setText("");
    this->ui->paese->setText("");
    this->ui->eta->setText("");
}
