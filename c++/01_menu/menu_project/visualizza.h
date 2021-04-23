#ifndef VISUALIZZA_H
#define VISUALIZZA_H

#include <QDialog>
#include <QWidget>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>

#include "classes.h"

namespace Ui
{
    class Visualizza;
}

class Visualizza : public QDialog
{
    Q_OBJECT

public:
    explicit Visualizza(QWidget *parent = nullptr);
    ~Visualizza();

private slots:
    void on_pushButton_clicked();
    void dataReadyRead();
    void dataReadFinished();

private:
    Ui::Visualizza *ui;
    QNetworkAccessManager * mNetManager;
    QNetworkReply * mNetReply;
    QByteArray * mDataBuffer;
};

#endif // VISUALIZZA_H
