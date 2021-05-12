#ifndef PROVA_H
#define PROVA_H

#include <QDialog>
#include <QWidget>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>

namespace Ui {
class Prova;
}

class Prova : public QDialog
{
    Q_OBJECT

public:
    explicit Prova(QWidget *parent = nullptr);
    ~Prova();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Prova *ui;
};

#endif // PROVA_H
