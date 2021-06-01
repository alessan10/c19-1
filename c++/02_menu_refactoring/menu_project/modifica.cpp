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

QString old_name, old_surname;

void Modifica::on_pushButton_clicked()
{
    //QString name = ui->nome->text();
    //QString surname = ui->cognome->text();

    old_name = ui->nome->text();
    old_surname = ui->cognome->text();

    if (ui->nome->text().isEmpty() || ui->cognome->text().isEmpty())
    {
        QMessageBox::warning(this,"Attenzione","Inserisci nome e cognome.", QMessageBox::Ok);

    }
    else
    {
        //Initialize our API data
        const QUrl API_ENDPOINT("http://localhost:8081/simplesearch?name="+old_name+"&surname="+old_surname);
        //const QUrl API_ENDPOINT("http://localhost:8081/simplesearch?name="+name+"&surname="+surname);
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
        Patient *p = new Patient();

        QJsonObject jsonPatient = array.at(0).toObject().value("patient").toObject();
        *p = Patient(jsonPatient);

        setUiFieldsFromPatient(p);

        delete p;

    }
}

void Modifica::on_button_modifica_clicked()
{
    Patient &p = *(new Patient());
    setPatientFromUiFields(p);
    QJsonObject json = p.toJson();

    qDebug() << "new data: " << json;

    QJsonDocument doc(json);
    QByteArray data = doc.toJson();

    QNetworkAccessManager *mgr = new QNetworkAccessManager(this);
    const QUrl url(QStringLiteral("http://localhost:8081/update?old_name=%1&old_surname=%2").arg(old_name, old_surname));
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

void Modifica::setUiFieldsFromPatient(Patient *p)
{
    ui->new_nome->setText(p->getName());
    ui->new_cognome->setText(p->getSurname());
    ui->new_eta->setText(p->getAge());
    ui->new_paese->setText(p->getCountry());

    int iday = p->date.getDay().toInt() -1;
    ui->new_day->setCurrentIndex(iday);

    ui->new_month->setCurrentText(p->date.getMonth());
    ui->new_year->setCurrentText(p->date.getYear());
    ui->new_weekday->setCurrentText(p->date.getDayOfWeek());

    ui->new_covid->setCurrentText(p->getCovid());

}

void Modifica::setPatientFromUiFields( Patient &p){
    p.setName( ui->new_nome->text());
    p.setSurname( ui->new_cognome->text());
    p.setAge( ui->new_eta->text());
    p.setCountry( ui->new_paese->text());
    p.date.setYear( ui->new_year->currentText());
    p.date.setMonth(ui->new_month->currentText());
    p.date.setDay(ui->new_day->currentText());
    p.date.setDayOfWeek(ui->new_weekday->currentText());
    p.setCovid(ui->new_covid->currentText());
}
