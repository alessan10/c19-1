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
    void patientToTable(Patient *p, int row);

private slots:
    void on_pushButton_clicked();
    void dataReadyRead();
    void dataReadFinished();

private:
    Ui::Visualizza *ui;
    QNetworkAccessManager * mNetManager;
    QNetworkReply * mNetReply;
    QByteArray * mDataBuffer;

    enum Columns{
        ID,
        Nome,
        Cognome,
        Eta,
        ChatID,
        Covid,
        Anno,
        Mese,
        Giorno,
        Giorno_della_settimana,
        Paese
    };

};

#endif // VISUALIZZA_H
