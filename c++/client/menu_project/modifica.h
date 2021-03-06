#ifndef MODIFICA_H
#define MODIFICA_H

#include <QDialog>
#include <QWidget>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>


#include "classes.h"

namespace Ui
{
class Modifica;
}

class Modifica : public QDialog, private GuiUtility
{
    Q_OBJECT

public:
    explicit Modifica(QWidget *parent = nullptr);
    ~Modifica();
    void cleanUp() override;
    void setUiFieldsFromPatient(Patient *patient);
    void setPatientFromUiFields( Patient & patient);

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
    Patient *patient;
};

#endif // MODIFICA_H
