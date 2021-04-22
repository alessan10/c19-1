#include "mainwindow.h"
#include "worker.h"
#include "classes.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Worker worker;
    Patient patient;

    Worker & ref = worker;
    Patient & p = patient;

    MainWindow w(ref,p);

    w.show();
    return a.exec();
}
