#ifndef STATS_H
#define STATS_H

#include <QDialog>
#include <QWidget>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>

#include "classes.h"

namespace Ui
{
    class Stats;
}

class Stats : public QDialog
{
    Q_OBJECT

public:
    explicit Stats(QWidget *parent = nullptr);
    ~Stats();

private slots:
    void dataReadyRead();
    void dataReadFinished();

    void on_generateButton_clicked();


    void on_positive_country_clicked();

private:
    Ui::Stats *ui;
    QNetworkAccessManager * mNetManager;
    QNetworkReply * mNetReply;
    QByteArray * mDataBuffer;
};

#endif // STATS_H
