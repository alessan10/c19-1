#include "statistiche.h"
#include "ui_statistiche.h"

#include <QNetworkRequest>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>
#include <QVariantMap>
#include <QDebug>

Statistiche::Statistiche(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Statistiche),
    mNetManager(new QNetworkAccessManager(this)),
    mNetReply(nullptr),
    mDataBuffer(new QByteArray)
{
    ui->setupUi(this);
}

Statistiche::~Statistiche()
{
    delete ui;
}

