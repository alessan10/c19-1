#ifndef INSERISCI_H
#define INSERISCI_H

#include <QDialog>
#include <QAbstractButton>
#include <QNetworkRequest>
#include <QNetworkReply>

#include "classes.h"

namespace Ui
{
    class Inserisci;
}

class Inserisci : public QDialog, private GuiUtility
{
    Q_OBJECT

public:
    explicit Inserisci(QWidget *parent = nullptr);
    ~Inserisci();
    void cleanUp() override;

private slots:
    void on_save_button_clicked();

private:
    Ui::Inserisci *ui;
    QNetworkAccessManager * mNetManager;
    QNetworkReply * mNetReply;
    QByteArray * mDataBuffer;
};

#endif // INSERISCI_H
