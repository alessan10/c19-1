#ifndef INSERISCI_H
#define INSERISCI_H

#include <QDialog>
#include <QAbstractButton>

#include "worker.h"

namespace Ui {
class Inserisci;
}

class Inserisci : public QDialog
{
    Q_OBJECT

public:
    explicit Inserisci(Worker &worker ,QWidget *parent = nullptr);
    ~Inserisci();

private slots:
    void on_buttonBox_clicked(QAbstractButton *button);

private:
    Ui::Inserisci *ui;
    QNetworkAccessManager * mNetManager;
    QNetworkReply * mNetReply;
    QByteArray * mDataBuffer;
    Worker *worker;
};

#endif // INSERISCI_H
