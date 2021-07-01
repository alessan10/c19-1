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
#include <QTabWidget>

Ricerca::Ricerca(Worker &worker, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Ricerca),
    mNetManager(new QNetworkAccessManager(this)),
    mNetReply(nullptr),
    mDataBuffer(new QByteArray)
{
    this->worker = &worker;
    ui->setupUi(this);

    QStringList headers;
    headers << "ID" << "Nome" << "Cognome" << "Età" << "ChatID" << "Covid" << "Anno" << "Mese" << "Giorno" << "Giorno della settimana" << "Paese";
    ui->table->setColumnCount(11);
    ui->table->setHorizontalHeaderLabels(headers);
}

Ricerca::~Ricerca()
{
    delete ui;
}


void Ricerca::on_searchButton_clicked()
{
    QStringList headers;
    headers << "ID" << "Nome" << "Cognome" << "Età" << "ChatID" << "Covid" << "Anno" << "Mese" << "Giorno" << "Giorno della settimana" << "Paese";
    ui->table->setColumnCount(11);
    ui->table->setHorizontalHeaderLabels(headers);


    QString name = ui->nome->text();
    QString surname = ui->cognome->text();

    if (ui->nome->text().isEmpty() || ui->cognome->text().isEmpty())
    {
        QMessageBox::warning(this,"Attenzione","Inserisci nome e cognome.", QMessageBox::Ok);

    }
    else
    {
        cleanUp();
        worker = new Worker();
        mNetReply= nullptr;
        mDataBuffer = new QByteArray();
        mNetManager = new QNetworkAccessManager();

        //Initialize our API data
        const QUrl API_ENDPOINT("http://localhost:8081/search?name="+name+"&surname="+surname);
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
    if( mNetReply->error() || mDataBuffer->isEmpty())
    {
        qDebug() << "Error : " << mNetReply->errorString();
        QMessageBox::warning(this, "Attenzione", "Non è stato trovato alcun risultato.", QMessageBox::Ok);

    }
    else
    {
       qDebug() << "Data fetch finished : " << QString(*mDataBuffer);

       //Turn the data into a json document

       QJsonDocument * mDoc = new QJsonDocument() ;
       *mDoc = QJsonDocument::fromJson(*mDataBuffer);

       qDebug()<< mDoc->object().value("patient").toArray().size();

       //Turn document into json array

       QJsonArray * array = new QJsonArray();
       * array = mDoc->array();

       //for each patient print a row in the table with patient's data
       for ( int i = 0; i < array->size(); i++)
       {
           QJsonObject jsonPatient = array->at(i).toObject().value("patient").toObject();
           Patient p  =  Patient(jsonPatient);
           ui->table->insertRow(i);
           patientToTable(&p, i);
       }

       delete mDoc;
       delete array;
       delete mNetReply;
       delete mNetManager;
       delete mDataBuffer;
       delete worker;

    }
}

void Ricerca::deleteFinished()
{
    QString name = ui->nome->text();
    QString surname = ui->cognome->text();

    if( mNetReply->error() || mDataBuffer->isEmpty())
    {
        qDebug() << "Error : " << mNetReply->errorString();
        QMessageBox::warning(this, "Attenzione", "Non è stato trovato alcun risultato.", QMessageBox::Ok);

    }
    else
    {
        QMessageBox::information(this,"Informazione",
                                 QString("L'utente di nome %1 %2 è stato eliminato correttamente").arg(name).arg(surname),
                                 QMessageBox::Ok);
        cleanUp();
        ui->nome->clear();
        ui->cognome->clear();
    }

       delete mNetReply;
       delete mNetManager;
       delete mDataBuffer;
       delete worker;
}

void Ricerca::on_deleteButton_clicked()
{
    QString name = ui->nome->text();
    QString surname = ui->cognome->text();
    qDebug() << "name: " << name;
    qDebug() << "surname" << surname;

    if (ui->nome->text().isEmpty() || ui->cognome->text().isEmpty())
    {
        QMessageBox::warning(this,"Attenzione","Inserisci nome e cognome.", QMessageBox::Ok);

    }else{

        //Initialize our API data
        worker = new Worker();
        mNetReply= nullptr;
        mDataBuffer = new QByteArray();
        mNetManager = new QNetworkAccessManager();

        const QUrl API_ENDPOINT("http://localhost:8081/delete?name="+name+"&surname="+surname);
        QNetworkRequest request;
        request.setUrl(API_ENDPOINT);

        mNetReply = mNetManager->deleteResource(request);
        connect(mNetReply,&QIODevice::readyRead,this,&Ricerca::dataReadyRead);
        connect(mNetReply,&QNetworkReply::finished,this,&Ricerca::deleteFinished);

    }
}

void Ricerca::cleanUp(){
    int rowsTot = ui->table->rowCount();

    for (int row = 0; row < rowsTot; row++)
        ui->table->removeRow(0);
}

void Ricerca::patientToTable(Patient *p, int row){
    ui->table->setItem(row, ID, new QTableWidgetItem(p->getId()));
    ui->table->setItem(row, Nome, new QTableWidgetItem(p->getName()));
    ui->table->setItem(row, Cognome, new QTableWidgetItem(p->getSurname()));
    ui->table->setItem(row, Eta, new QTableWidgetItem(p->getAge()));
    ui->table->setItem(row, ChatID, new QTableWidgetItem(p->getChatId()));
    ui->table->setItem(row, Covid, new QTableWidgetItem(p->getCovid()));
    ui->table->setItem(row, Anno, new QTableWidgetItem(p->date.getYear()));
    ui->table->setItem(row, Mese, new QTableWidgetItem(p->date.getMonth()));
    ui->table->setItem(row, Giorno, new QTableWidgetItem(p->date.getDay()));
    ui->table->setItem(row, Giorno_della_settimana, new QTableWidgetItem(p->date.getDayOfWeek()));
    ui->table->setItem(row, Paese, new QTableWidgetItem(p->getCountry()));
}

