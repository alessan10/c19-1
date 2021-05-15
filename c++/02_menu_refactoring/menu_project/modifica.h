#ifndef MODIFICA_H
#define MODIFICA_H

#include <QDialog>
#include <QWidget>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>

#include "worker.h"
#include "classes.h"

namespace Ui
{
class Modifica;
}

class Modifica : public QDialog
{
    Q_OBJECT

public:
    explicit Modifica(Worker & worker, QWidget *parent = nullptr);
    ~Modifica();
    void cleanUp();

private slots:
    void on_pushButton_clicked();
    void dataReadyRead();
    void dataReadFinished();

    void on_button_modifica_clicked();

private:
    Ui::Modifica *ui;
    QNetworkAccessManager * mNetManager;
    QNetworkReply * mNetReply;
    QByteArray * mDataBuffer;
    Worker *worker;
    Patient *patient;
};

#endif // MODIFICA_H
