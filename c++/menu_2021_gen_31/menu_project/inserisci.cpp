#include "inserisci.h"
#include "ui_inserisci.h"
#include "worker.h"
#include "date.h"

#include <QNetworkRequest>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>
#include <QVariantMap>
#include <QDebug>
#include <QUrlQuery>
#include <QMessageBox>
#include <QPushButton>
#include <QDate>

Inserisci::Inserisci(Worker &worker ,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Inserisci),
    mNetManager(new QNetworkAccessManager(this)),
    mNetReply(nullptr),
    mDataBuffer(new QByteArray),
    worker(nullptr)


{
    this->worker = &worker;
    ui->setupUi(this);

}

Inserisci::~Inserisci()
{
    delete ui;
}

void Inserisci::on_save_button_clicked(QAbstractButton *button)
{

    if (ui->nome_e_cognome->text().isEmpty() ||
            (!ui->radio_positivo->isChecked()) && (!ui->radio_negativo->isChecked()) ||
            ui->calendar->selectedDate().isNull() ){

        int ret = QMessageBox::warning(this,"Message Title","hai dimenticato di impostare uno dei campi. Controlla!",
                                        QMessageBox::Ok);

        if ( ret == QMessageBox::Ok)
        {
            qDebug() << "User clicked on OK";
        }


    }else {
        qDebug() << "OK";
        QString name = ui->nome_e_cognome->text();
        qDebug() << "string: " << name;

        QString covid;
        ui->radio_positivo->isChecked()? covid = "positivo" : covid = "negativo";

        QDate calend = ui->calendar->selectedDate() ;
        QDate &cld = calend;


        date.conversion(cld);

        qDebug() << "Inserisci::save -->  NOME = " <<  name;
        qDebug() << "Inserisci::save --> COVID = " << covid;
        qDebug() << "Inserisci::save --> Giorno = " << date.day;
        qDebug() << "Inserisci::save --> Mese = " << date.month;
        qDebug() << "Inserisci::save --> Anno = " << date.year;
        cleanUp();

    }

}

void Inserisci::cleanUp(){
    this->ui->nome_e_cognome->setText("");
}
