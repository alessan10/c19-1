#include "stats.h"
#include "ui_stats.h"

#include <QNetworkRequest>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>
#include <QVariantMap>
#include <QDebug>
#include <QList>
#include <iostream>
#include <QFile>
#include <QMessageBox>
#include <QPixmap>
#include <QFileDialog>
using namespace std;

Stats::Stats(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Stats),
    mNetManager(new QNetworkAccessManager(this)),
    mNetReply(nullptr),
    mDataBuffer(new QByteArray)
{
    ui->setupUi(this);
    ui->positive_country->setEnabled(false);
    ui->positive_year->setEnabled(false);
    ui->positive_age->setEnabled(false);
}

Stats::~Stats()
{
    delete ui;
}

void Stats::on_generateButton_clicked()
{

    const QUrl API_ENDPOINT("http://localhost:8081/graph");
    QNetworkRequest request;
    request.setUrl(API_ENDPOINT);

    mNetReply = mNetManager->get(request);
    connect(mNetReply,&QIODevice::readyRead,this,&Stats::dataReadyRead);
    connect(mNetReply,&QNetworkReply::finished,this,&Stats::dataReadFinished);

}

void Stats::dataReadyRead()
{
    mDataBuffer->append(mNetReply->readAll());
}

void Stats::dataReadFinished()
{
    if( mNetReply->error())
    {
        qDebug() << "Error : " << mNetReply->errorString();
    }
    else
    {
       qDebug() << "Data fetch finished : " << QString(*mDataBuffer);

       QJsonDocument mDoc;
       mDoc = QJsonDocument::fromJson(*mDataBuffer);

       qDebug() << mDoc.object().value("patient").toArray().size();

       QJsonArray array = mDoc.array();
       QList<Patient *> patients_list;
       Patient *p = new Patient();

       for ( int i = 0; i < array.size(); i++)
       {
           QJsonObject object = array.at(i).toObject().value("patient").toObject();

           Patient *p = new Patient(
               object["id"].toString(),
               object["name"].toString(),
               object["surname"].toString(),
               object["age"].toString(),
               object["chatId"].toString(),
               object["covid"].toString(),
               object["year"].toString(),
               object["month"].toString(),
               object["day"].toString(),
               object["weekday"].toString(),
               object["country"].toString()
           );

           patients_list.push_back(p);

           QString tmpPatient =
                   "Id: " + p->getId() +
                   " - Nome: " + p->getName() +
                   " - Cognome: " + p->getSurname() +
                   " - Age: " + p->getAge() +
                   " - ChatID: "  + p->getChatId() +
                   " - Covid: " + p->getCovid() +
                   " - Data: " + p->date.getYear() + " " + p->date.getMonth() + " " + p->date.getDay() + " " + p->date.getDayOfWeek() +
                   " - Country: " + p->getCountry();

           qDebug() << "My Current Patient is: \n" << tmpPatient << "\n End current Patient \n";

           QString c0 = mDoc.object().value("patient").toArray().at(i).toObject().value("name").toString();
           qDebug() << c0;

       }
       delete p;

       QList<Patient*>::iterator i;
       for (i = patients_list.begin(); i != patients_list.end(); ++i){
            (*i)->toString();
       }

       QFile file("C:/Users/alexm/Downloads/out.csv");
       if (!file.open(QIODevice::WriteOnly | QIODevice::Text)){
           QMessageBox::warning(this, "Attenzione", "Non è stato possibile generare il file!",
                                QMessageBox::Close);
           return;
       } else {
           QMessageBox::information(this, "Attenzione", "Il file è stato creato correttamente!",
                                    QMessageBox::Ok);
           QTextStream out(&file);
           QString stringa = "\"Id\",\"Nome\",\"Cognome\",\"Age\",\"ChatId\",\"Covid\",\"Anno\",\"Mese\",\"Giorno\",\"Weekday\",\"Country\"";
           out << stringa <<"\n";

           for (i = patients_list.begin(); i != patients_list.end(); ++i){
               qDebug() << "toR: " << (*i)->toR() << " toR end";
               out << (*i)->toR() << "\n";
           }
           file.close();

           ui->positive_country->setEnabled(true);
           ui->positive_year->setEnabled(true);
           ui->positive_age->setEnabled(true);
       }
    }
}

void Stats::on_positive_country_clicked()
{
    system("C:\\\"Program Files\"\\R\\R-4.0.5\\bin\\Rscript D:\\Alessandro\\uniCT\\Magistrale\\Secondo_Anno\\1_Advanced_Programming_Languages\\Progetto_Esame\\git_c19\\c19\\r\\geo_script.r");

    QPixmap pix("D:/Alessandro/uniCT/Magistrale/Secondo_Anno/1_Advanced_Programming_Languages/Progetto_Esame/git_c19/c19/r/geo_plot.jpg");
    ui->imageLabel->setPixmap(pix);
}

void Stats::on_positive_year_clicked()
{
    if (ui->year_comboBox->currentIndex() == 0){
        qDebug() << "Selected: " << ui->year_comboBox->currentIndex();
        system("C:\\\"Program Files\"\\R\\R-4.0.5\\bin\\Rscript D:\\Alessandro\\uniCT\\Magistrale\\Secondo_Anno\\1_Advanced_Programming_Languages\\Progetto_Esame\\git_c19\\c19\\r\\covid+_2020_script.r");

        QPixmap pix("D:/Alessandro/uniCT/Magistrale/Secondo_Anno/1_Advanced_Programming_Languages/Progetto_Esame/git_c19/c19/r/covid+_2020_plot.jpg");
        ui->imageLabel->setPixmap(pix);
    } else {
        qDebug() << "Selected: " << ui->year_comboBox->currentIndex();
        system("C:\\\"Program Files\"\\R\\R-4.0.5\\bin\\Rscript D:\\Alessandro\\uniCT\\Magistrale\\Secondo_Anno\\1_Advanced_Programming_Languages\\Progetto_Esame\\git_c19\\c19\\r\\covid+_2021_script.r");

        QPixmap pix("D:/Alessandro/uniCT/Magistrale/Secondo_Anno/1_Advanced_Programming_Languages/Progetto_Esame/git_c19/c19/r/covid+_2021_plot.jpg");
            ui->imageLabel->setPixmap(pix);
    }


}

void Stats::on_positive_age_clicked()
{
    system("C:\\\"Program Files\"\\R\\R-4.0.5\\bin\\Rscript D:\\Alessandro\\uniCT\\Magistrale\\Secondo_Anno\\1_Advanced_Programming_Languages\\Progetto_Esame\\git_c19\\c19\\r\\covid+_eta.r");

    QPixmap pix("D:/Alessandro/uniCT/Magistrale/Secondo_Anno/1_Advanced_Programming_Languages/Progetto_Esame/git_c19/c19/r/covid+_eta_plot.jpg");
    ui->imageLabel->setPixmap(pix);
}
