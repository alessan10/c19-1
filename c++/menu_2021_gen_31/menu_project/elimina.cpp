#include "elimina.h"
#include "ui_elimina.h"

Elimina::Elimina(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Elimina)
{
    ui->setupUi(this);
}

Elimina::~Elimina()
{
    delete ui;
}
