#include "ricerca.h"
#include "ui_ricerca.h"

Ricerca::Ricerca(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Ricerca)
{
    ui->setupUi(this);
}

Ricerca::~Ricerca()
{
    delete ui;
}
