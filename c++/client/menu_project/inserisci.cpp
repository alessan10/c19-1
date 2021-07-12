#include "inserisci.h"
#include "ui_inserisci.h"
#include "classes.h"

#include <QNetworkRequest>
#include <QNetworkAccessManager>
#include <QNetworkReply>
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

Inserisci::Inserisci( QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Inserisci),
    mNetManager(new QNetworkAccessManager(this)),
    mNetReply(nullptr),
    mDataBuffer(new QByteArray)
{
    ui->setupUi(this);
}

Inserisci::~Inserisci()
{
   delete ui;
}

void Inserisci::on_save_button_clicked()
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

        Patient *pat = new Patient();
        Patient &p = *(pat);
        p.setName(name);
        p.setSurname(surname);

        p.setChatId("-");

        ui->radio_positivo->isChecked()? p.setCovid("positivo") : p.setCovid("negativo");

        QDate calend = ui->calendar->selectedDate() ;
        QDate &cld = calend;
        p.date.conversion(cld);

        p.setCountry(ui->paese->text());

        p.setAge(ui->eta->text());

        QJsonObject jsonToPost = p.toJson();

        delete pat;

        qDebug() << jsonToPost;
        QJsonDocument doc(jsonToPost);
        QByteArray data = doc.toJson();

        QNetworkAccessManager *mgr = new QNetworkAccessManager(this);
        const QUrl url(QStringLiteral("http://localhost:8081/add"));
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
                QMessageBox::information(this,"Info","Utente inserito con successo.", QMessageBox::Ok);
                        cleanUp();
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

