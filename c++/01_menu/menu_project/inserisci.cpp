#include "inserisci.h"
#include "ui_inserisci.h"
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

Inserisci::Inserisci(Worker &worker, QWidget *parent) :
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

        Patient p;
        p.setFullName(name+" "+ surname);
        qDebug() << "Fullname" <<p.getFullName();

        p.setChatId("-");
        //QString covid;
        ui->radio_positivo->isChecked()? p.setCovid("positivo") : p.setCovid("negativo");

        QDate calend = ui->calendar->selectedDate() ;
        QDate &cld = calend;
        p.date.conversion(cld);


        //QString country = ui->paese->text();
        p.setCountry(ui->paese->text());

        //QString age = ui->eta->text();
        p.setAge(ui->eta->text());

        qDebug() << "Inserisci::save -->  NOME e COGNOME= " <<  p.getFullName();
        qDebug() << "Inserisci::save --> COVID = " << p.getCovid();
        qDebug() << "Inserisci::save --> Giorno = " << p.date.getDay();
        qDebug() << "Inserisci::save --> Mese = " << p.date.getMonth();
        qDebug() << "Inserisci::save --> Anno = " << p.date.getYear();
        qDebug() << "Inserisci::save --> Paese = " << p.getCountry();
        qDebug() << "Inserisci::save --> Eta = " << p.getAge();

        cleanUp();

        QJsonObject json;
        json["name"] = QString(p.getFullName());
        json["chatid"] = QString(p.getChatId());
        json["covid"] =QString(p.getCovid());
        json["weekday"] =QString(p.date.getDayOfWeek());
        json["day"] = QString(p.date.getDay());
        json["month"] = QString(p.date.getMonth());
        json["year"] =QString(p.date.getYear());
        json["country"] =QString(p.getCountry());
        json["age"] =QString(p.getAge());

        qDebug() << json;
        QJsonDocument doc(json);
        QByteArray data = doc.toJson();

        QNetworkAccessManager *mgr = new QNetworkAccessManager(this);
        const QUrl url(QStringLiteral("http://localhost:8081/add"));
        QNetworkRequest request(url);
        request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

        //QByteArray data("{\"name\":\"value1\",\"covid\":\"value2\"}");
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
