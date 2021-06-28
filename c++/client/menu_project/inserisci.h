#ifndef INSERISCI_H
#define INSERISCI_H

#include <QDialog>
#include <QAbstractButton>

#include "worker.h"
#include "classes.h"

namespace Ui
{
class Inserisci;
}

class Inserisci : public QDialog, private GuiUtility
{
    Q_OBJECT

public:
    explicit Inserisci(Worker &worker, QWidget *parent = nullptr);
    ~Inserisci();
    void cleanUp() override;

private slots:
    void on_save_button_clicked(QAbstractButton *button);

private:
    Ui::Inserisci *ui;
    QNetworkAccessManager * mNetManager;
    QNetworkReply * mNetReply;
    QByteArray * mDataBuffer;
    Worker *worker;
};

#endif // INSERISCI_H
