#include "modifica.h"
#include "ui_modifica.h"

Modifica::Modifica(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Modifica)
{
    ui->setupUi(this);
}

Modifica::~Modifica()
{
    delete ui;
}
