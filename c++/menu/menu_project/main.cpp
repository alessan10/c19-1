#include "mainwindow.h"
#include "worker.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    Worker worker;
    QString name = "Odie";
    QString surname = "Von";
  //worker.get("http://localhost:8081/search?name=Rosemary%20Stiedemann");
    worker.get("http://localhost:8081/search?name="+name+"%20"+surname);

    return a.exec();


}
