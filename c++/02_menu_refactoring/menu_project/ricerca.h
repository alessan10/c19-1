#ifndef RICERCA_H
#define RICERCA_H

#include <QDialog>
#include <QWidget>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>

#include "worker.h"
#include "classes.h"

namespace Ui
{
class Ricerca;
}

class Ricerca : public QDialog, private GuiUtility
{
    Q_OBJECT
public:
    explicit Ricerca(Worker & worker, QWidget *parent = nullptr);
    ~Ricerca();
    void cleanUp() override;
    void patientToTable(Patient *p, int row);


private slots:
    void on_searchButton_clicked();
    void dataReadyRead();
    void dataReadFinished();   
    void on_deleteButton_clicked();

private:
    Ui::Ricerca *ui;
    QNetworkAccessManager * mNetManager;
    QNetworkReply * mNetReply;
    QByteArray * mDataBuffer;
    Worker *worker;
    Patient *patient;
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

#endif // RICERCA_H
