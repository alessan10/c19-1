#include <QCoreApplication>
#include "worker.h"

//QNetworkAccessManager really encasulates the HTTP protocol, incudes SSL

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Worker worker;
    QString name = "Alec";
    QString surname = "Hahn";
    //worker.get("http://localhost:8081/search?name=Rosemary%20Stiedemann");
    worker.get("http://localhost:8081/search?name="+name+"%20"+surname);

    /*
    worker.get("https://postman-echo.com/get?foo1=bar1&foo2=bar2");


    QByteArray data;
    data.append("name=Rosemary%20Stiedemann");
    data.append("&");
    data.append("param2=foo");

    worker.post("http://localhost:8081/search",data);

    */


    return a.exec();
}
