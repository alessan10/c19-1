#ifndef TABLE_H
#define TABLE_H

#include <QDialog>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QStandardItemModel>


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
    void on_tableView_clicked(const QModelIndex &index);
    void dataReadyRead();
    void dataReadFinished();

    void on_pushButton_clicked();

private:
    Ui::Table *ui;
    QNetworkAccessManager * mNetManager;
    QNetworkReply * mNetReply;
    QByteArray * mDataBuffer;
    QStandardItemModel * tableModel;

};

#endif // TABLE_H
