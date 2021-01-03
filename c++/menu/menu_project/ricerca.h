#ifndef RICERCA_H
#define RICERCA_H

#include <QDialog>
#include <QWidget>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>

#include "worker.h"

namespace Ui {
class Ricerca;
}

class Ricerca : public QDialog
{
    Q_OBJECT

public:
    explicit Ricerca(QWidget *parent = nullptr);
    ~Ricerca();

private slots:
    void on_pushButton_clicked(Worker worker);
    //void dataReadyRead();
    //void dataReadFinished();

private:
    Ui::Ricerca *ui;
    QNetworkAccessManager * mNetManager;
    QNetworkReply * mNetReply;
    QByteArray * mDataBuffer;
};

#endif // RICERCA_H
