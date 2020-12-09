#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include "inserisci.h"
#include "ricerca.h"
#include "elimina.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_actionAbout_Our_Project_triggered()
{
    QMessageBox::about(this, "Message", "This is ...");
}

void MainWindow::on_actionExit_triggered()
{
    QApplication::quit();
}

void MainWindow::on_actioninserisci_triggered()
{
    Inserisci inseriscidialog;
    inseriscidialog.setWindowTitle("Inserisci");
    inseriscidialog.setModal(true);
    inseriscidialog.exec();

}

void MainWindow::on_actionRicerca_triggered()
{
    Ricerca ricercadialog;
    ricercadialog.setWindowTitle("Ricerca");
    ricercadialog.setModal(true);
    ricercadialog.exec();
}

void MainWindow::on_actionElimina_triggered()
{
    Elimina eliminadialog;
    eliminadialog.setWindowTitle("Elimina");
    eliminadialog.setModal(true);
    eliminadialog.exec();
}
