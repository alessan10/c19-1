#include "table.h"
#include "ui_table.h"
#include <QNetworkRequest>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>
#include <QVariantMap>
#include <QDebug>

Table::Table(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Table),
    mNetManager(new QNetworkAccessManager(this)),
    mNetReply(nullptr),
    mDataBuffer(new QByteArray)
{
    ui->setupUi(this);
    tableModel = new QStandardItemModel(this);
    tableModel->setRowCount(3);
    tableModel->setColumnCount(5);

    for ( int i = 0; i < 3 ; i++)
    {
        for ( int j =0; j < 5 ; j++)
        {
            QString data = QString ("row %0 , column %1").arg(i).arg(j);

            QModelIndex index = tableModel->index(i,j,QModelIndex());

            tableModel->setData(index,QVariant::fromValue(data));
        }
    }

    ui->tableView->setModel(tableModel);

}

Table::~Table()
{
    delete ui;
}

void Table::on_tableView_clicked(const QModelIndex &index)
{
    QString data = tableModel->data(index,Qt::DisplayRole).toString();
    qDebug() << "The data is :" << data;
}
