#include "prova.h"
#include "ui_prova.h"

#include <QNetworkRequest>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>
#include <QVariantMap>
#include <QDebug>

Prova::Prova(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Prova),
    mNetManager(new QNetworkAccessManager(this)),
    mNetReply(nullptr),
    mDataBuffer(new QByteArray)
{
    ui->setupUi(this);
}

Prova::~Prova()
{
    delete ui;
}

void Prova::on_pushButton_clicked()
{
    const QUrl API_ENDPOINT("http://localhost:8081/graph");
    QNetworkRequest request;
    request.setUrl(API_ENDPOINT);

    mNetReply = mNetManager->get(request);
    connect(mNetReply,&QIODevice::readyRead,this,&Visualizza::dataReadyRead);
    connect(mNetReply,&QNetworkReply::finished,this,&Visualizza::dataReadFinished);

}

void Prova::dataReadyRead()
{
    mDataBuffer->append(mNetReply->readAll());
}

