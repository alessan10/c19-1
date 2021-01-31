#include "mainwindow.h"
#include "worker.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Worker worker;
    Worker & ref = worker;
    MainWindow w(ref);
    w.show();
    return a.exec();
}
