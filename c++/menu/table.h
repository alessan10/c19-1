#ifndef TABLE_H
#define TABLE_H

#include <QDialog>
#include <QWidget>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>

namespace Ui {
class Table;
}

class Table : public QDialog
{
    Q_OBJECT

public:
    explicit Table(QWidget *parent = nullptr);
    ~Table();

private slots:
    void on_tableWidget_clicked(const QModelIndex &index);

    void on_pushButton_clicked();
    void dataReadyRead();
    void dataReadFinished();

private:
    Ui::Table *ui;

    QNetworkAccessManager * mNetManager;
    QNetworkReply * mNetReply;
    QByteArray * mDataBuffer;
};

#endif // TABLE_H

