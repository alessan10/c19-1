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
        const QUrl API_ENDPOINT("http://localhost:8081/search?name="+name+"%20"+surname);
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
    }

    //https://stackoverflow.com/questions/26504626/custom-placeholder-in-qlineedit
}

