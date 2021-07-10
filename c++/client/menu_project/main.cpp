#include "mainwindow.h"
#include "worker.h"
#include "classes.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

//    Worker worker;
//    Worker & ref = worker;
//    MainWindow w(ref);

    MainWindow w;

    w.show();
    return a.exec();
}
