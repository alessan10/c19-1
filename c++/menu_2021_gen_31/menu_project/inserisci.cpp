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
    Date date;




    //connect(ui->string_name, SIGNAL(textEdited(const QString&)), SLOT(on_save_button_clicked()));


}

Inserisci::~Inserisci()
{
    delete ui;
}
/*
void Inserisci::on_buttonBox_clicked()
{

    QString esito;
    QString name = ui->string_name->text();

    //controllo che string name sia pieno
    connect(ui->string_name, SIGNAL(textEdited(const QString&)), SLOT(on_text_changed()));

    if (ui->radio_positivo->isChecked() == true && ui->radio_negativo->isChecked() == false){
        esito = "positivo";
    }else esito = "negativo";
    //controllo che positivo o negativo siano selezionati - da sistemare
    //connect(ui->radio_negativo, SIGNAL(()), SLOT(check_button()));
    //connect(ui->radio_positivo, SIGNAL(()), SLOT(check_button()));

    QString calendar = ui->calendar->selectedDate().toString();

    //controllo che la data sia stata selezionata - da sistemare
    //connect(ui->calendar, SIGNAL());
    qDebug() << "calendar: " << calendar;



}*/

/*
void Inserisci::on_pushButton_toggled(bool checked)
{
    //ui->string_name->text();

    //controllo che string name sia pieno
    connect(ui->string_name, SIGNAL(textEdited(const QString&)), SLOT(on_text_changed()));
}
*/

/*
void Inserisci::check_button(){

    ui->save_button->setEnabled(!ui->string_name->text().isEmpty()); //&& !ui->calendar->selectedDate().isNull()

}
void Inserisci::onTextChanged(const QString &arg1){
    if (ui->string_name->text().isEmpty()){
        ui->pushButton->setEnabled(false);
    }else{
        ui->pushButton->setEnabled(true);
    }
}*/


//void Inserisci::on_save_button_clicked(QAbstractButton *button)
//{
//    if (!ui->string_name->text().isEmpty()){
//        int ret = QMessageBox::warning(this, "Message Title", "Ciao",
//                                       QMessageBox::Ok);
//    }
//}

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

        qDebug() << "NOME = " <<  name;
        qDebug() << "COVID = " << covid;
        qDebug() << "Giorno = " << date.day;
        qDebug() << "Mese = " << date.month;
        qDebug() << "Anno = " << date.year;


    }

}
