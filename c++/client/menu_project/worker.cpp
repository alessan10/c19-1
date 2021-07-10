#include "worker.h"
#include <QNetworkRequest>

#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>

Worker::Worker(QObject *parent) :
    QObject(parent),
    mNetManager(new QNetworkAccessManager(this)),
    mNetReply(nullptr),
    mDataBuffer(new QByteArray)
{
//    connect(mNetManager,&QNetworkAccessManager::authenticationRequired,this,&Worker::authenticationRequired);
//    connect(mNetManager,&QNetworkAccessManager::encrypted,this,&Worker::encrypted);
//    connect(mNetManager,&QNetworkAccessManager::preSharedKeyAuthenticationRequired,this,&Worker::preSharedKeyAuthenticationRequired);
//    connect(mNetManager,&QNetworkAccessManager::proxyAuthenticationRequired,this,&Worker::proxyAuthenticationRequired);
//    connect(mNetManager,&QNetworkAccessManager::sslErrors,this,&Worker::sslErrors);
}

//void Worker::get(QString location)
//{
//    qInfo() << "Getting from server...";
//    QNetworkReply* reply = mNetManager->get(QNetworkRequest(QUrl(location)));
//    connect(reply,&QIODevice::readyRead,this,&Worker::readyRead);
//    connect(reply, &QNetworkReply::finished, this,&Worker::dataReadFinished );
//    qInfo()<< "Done";

//}

//void Worker::post(QString location, QByteArray data)
//{
//    qInfo() << "Posting to server...";
//    QNetworkRequest request = QNetworkRequest(QUrl(location));
//    request.setHeader(QNetworkRequest::ContentTypeHeader,"text/plain");

//    QNetworkReply* reply = mNetManager->post(request,data);
//    connect(reply,&QNetworkReply::readyRead,this,&Worker::readyRead);
//}



//void Worker::readyRead()
//{
//    qInfo() << "Entro in readyRead";
//    qInfo() << "ReadyRead";

//    QNetworkReply* reply = qobject_cast<QNetworkReply*>(sender());
//    mDataBuffer->append(reply->readAll());
//    if(reply) qInfo() << reply->readAll();
//}

//void Worker::dataReadFinished(){
//    QNetworkReply* reply = qobject_cast<QNetworkReply*>(sender());
//    if(reply->error()){
//        qDebug() << "Error: " << reply->errorString();
//    }
//    qDebug() << "Data fetch finished : " << QString(*mDataBuffer);
//    QJsonDocument mDoc;
//    mDoc = QJsonDocument::fromJson(*mDataBuffer);

//    qDebug() <<mDoc.object().value("cperson").toArray().size();

//    QJsonArray array = mDoc.array();

//    for(int i = 0; i < array.size(); i++)
//    {
//        QJsonObject object = array.at(i).toObject().value("cperson").toObject();
//        QString name = object["name"].toString();
//        QString chatid = object["chatid"].toString();
//        QString covid = object["covid"].toString();

//        QString c0 = mDoc.object().value("cperson").toArray().at(i).toObject().value("name").toString();
//        qDebug() << c0;
//    }


//}

//void Worker::authenticationRequired(QNetworkReply *reply, QAuthenticator *authenticator)
//{
//    Q_UNUSED(reply);
//    Q_UNUSED(authenticator);
//    qInfo() << "authenticationRequired";
//}

//void Worker::encrypted(QNetworkReply *reply)
//{
//    Q_UNUSED(reply);
//    qInfo() << "encrypted";
//}

//void Worker::finished(QNetworkReply *reply)
//{
//    Q_UNUSED(reply);
//    qInfo() << "finished";
//}



//void Worker::preSharedKeyAuthenticationRequired(QNetworkReply *reply, QSslPreSharedKeyAuthenticator *authenticator)
//{
//    Q_UNUSED(reply);
//    Q_UNUSED(authenticator);
//    qInfo() << "preSharedKeyAuthenticationRequired";
//}

//void Worker::proxyAuthenticationRequired(const QNetworkProxy &proxy, QAuthenticator *authenticator)
//{
//    Q_UNUSED(proxy);
//    Q_UNUSED(authenticator);
//    qInfo() << "proxyAuthenticationRequired";
//}

//void Worker::sslErrors(QNetworkReply *reply, const QList<QSslError> &errors)
//{
//    Q_UNUSED(reply);
//    Q_UNUSED(errors);
//    qInfo() << "sslErrors";
//}




