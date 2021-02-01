#include "table.h"
#include "ui_table.h"
#include <QNetworkRequest>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>
#include <QVariantMap>
#include <QDebug>

Table::Table(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Table),
    mNetManager(new QNetworkAccessManager(this)),
    mNetReply(nullptr),
    mDataBuffer(new QByteArray)
{
    ui->setupUi(this);

    //Initialize our API data
    const QUrl API_ENDPOINT("http://localhost:8081/graph");
    QNetworkRequest request;
    request.setUrl(API_ENDPOINT);

    mNetReply = mNetManager->get(request);
    connect(mNetReply,&QIODevice::readyRead,this,&Table::dataReadyRead);
    connect(mNetReply,&QNetworkReply::finished,this,&Table::dataReadFinished);


}


Table::~Table()
{
    delete ui;
}

void Table::on_pushButton_clicked()
{
    //Initialize our API data
    const QUrl API_ENDPOINT("http://localhost:8081/graph");
    QNetworkRequest request;
    request.setUrl(API_ENDPOINT);

    mNetReply = mNetManager->get(request);
    connect(mNetReply,&QIODevice::readyRead,this,&Table::dataReadyRead);
    connect(mNetReply,&QNetworkReply::finished,this,&Table::dataReadFinished);
}

void Table::dataReadyRead()
{
    mDataBuffer->append(mNetReply->readAll());
}


void Table::dataReadFinished()
{
    if( mNetReply->error())
    {
        qDebug() << "Error : " << mNetReply->errorString();
    }else
    {
       qDebug() << "Data fetch finished : " << QString(*mDataBuffer);

       //Turn the data into a json document
       //QJsonDocument doc = QJsonDocument::fromJson(*mDataBuffer);

       QJsonDocument mDoc;
       mDoc = QJsonDocument::fromJson(*mDataBuffer);

       qDebug() << mDoc.object().value("cperson").toArray().size();

       /*
       //What if you get an object from the server
       QJsonDocument objectDoc = QJsonDocument::fromJson(*mDataBuffer);
       QJsonObject obObject = objectDoc.toVariant().toJsonObject();
       */


       //Turn document into json array

       QJsonArray array = mDoc.array();

       tableModel = new QStandardItemModel(this);
       tableModel->setRowCount(array.size());
       tableModel->setColumnCount(5);

       for ( int j =0; j < 3 ; j++)
       {
            QString nome = QString("NOME E COGNOME");
            QModelIndex index0 = tableModel->index(0,j,QModelIndex());
            tableModel->setData(index0,QVariant::fromValue(nome));

            QString chatid = QString("CHATID");
            QModelIndex index1 = tableModel->index(0,j,QModelIndex());
            tableModel->setData(index1,QVariant::fromValue(chatid));

            QString covid = QString("COVID");
            QModelIndex index2 = tableModel->index(0,j,QModelIndex());
            tableModel->setData(index2,QVariant::fromValue(covid));



       }

       for ( int i = 0; i < array.size(); i++)
       {
           QJsonObject object = array.at(i).toObject().value("cperson").toObject();
           QString name = object["name"].toString();
           QString chatid = object["chatid"].toString();
           QString covid = object["covid"].toString();

           for ( int j =0; j < 3 ; j++)
           {
               //QString data = QString ("row %0 , column %1").arg(i).arg(j);


               QModelIndex index0 = tableModel->index(i+1,j,QModelIndex());

               tableModel->setData(index0,QVariant::fromValue(name));

               QModelIndex index1 = tableModel->index(i+1,j+1,QModelIndex());

               tableModel->setData(index0,QVariant::fromValue(chatid));


               QModelIndex index2= tableModel->index(i+1,j+2,QModelIndex());

               tableModel->setData(index2,QVariant::fromValue(covid));

           }

       }

    }
    ui->tableView->setModel(tableModel);

}

void Table::on_tableView_clicked(const QModelIndex &index)
{
    QString data = tableModel->data(index,Qt::DisplayRole).toString();
    qDebug() << "The data is :" << data;
}


