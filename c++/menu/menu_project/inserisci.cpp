#include "inserisci.h"
#include "ui_inserisci.h"

Inserisci::Inserisci(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Inserisci)
{
    ui->setupUi(this);
}

Inserisci::~Inserisci()
{
    delete ui;
}
