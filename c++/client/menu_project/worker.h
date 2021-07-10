#ifndef WORKER_H
#define WORKER_H

#include <QObject>
#include <QDebug>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QAuthenticator>
#include <QNetworkProxy>
#include <QJsonObject>


class Worker : public QObject
{
    Q_OBJECT
public:
    explicit Worker(QObject *parent = nullptr);
private slots:

//    virtual void dataReadyRead() = 0;
//    virtual void dataReadFinished() = 0;
private:
    QNetworkAccessManager * mNetManager;
    QNetworkReply * mNetReply;
    QByteArray *mDataBuffer;

};

#endif // WORKER_H
