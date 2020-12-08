#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

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
