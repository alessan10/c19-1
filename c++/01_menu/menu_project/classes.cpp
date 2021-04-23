#include "classes.h"
#include <QDebug>



void Date::toString(){
    qDebug() <<  dayOfWeek << " " << day << " "<< month << " "<< year;
}

Person::~Person(){
    qDebug() << "Distruttore Person chiamato";
}

//Date::~Date(){}

void Date::conversion(QDate & q){


    switch (q.dayOfWeek()) {
    case 1:
        this->dayOfWeek = "Mon";
        break;
    case 2:
        this->dayOfWeek = "Tue";
        break;
    case 3:
        this->dayOfWeek = "Wed";
        break;
    case 4:
        this->dayOfWeek = "Thu";
        break;
    case 5:
        this->dayOfWeek = "Fri";
        break;
    case 6:
        this->dayOfWeek = "Sat";
        break;
    case 7:
        this->dayOfWeek = "Sun";
        break;
    }

    switch (q.month()) {
    case 1:
        this->month = "Jen";
    break;
    case 2:
        this->month = "Feb";
    break;
    case 3:
        this->month = "Mar";
    break;
    case 4:
        this->month = "Apr";
    break;
    case 5:
        this->month = "May";
    break;
    case 6:
        this->month = "Jun";
    break;
    case 7:
        this->month = "Jul";
    break;
    case 8:
        this->month = "Aug";
    break;
    case 9:
        this->month = "Sep";
    break;
    case 10:
        this->month = "Oct";
    break;
    case 11:
        this->month = "Nov";
    break;
    case 12:
        this->month = "Dec";
    break;
    }

    this->year = QString::number(q.year());
    this->day = QString::number(q.day());

    qDebug() << "Date::conversion --> ANNO: "<< this->year;
    qDebug() << "Date::conversion --> Mese: " << this->month;
    qDebug() << "Date::conversion --> Giorno: " << this->day;
    qDebug() << "Date::conversion --> Day of The week: " << this->dayOfWeek;


}

void Patient::toString()
{
    qDebug() << "Fullname: " << this->fullname;
    qDebug() << "ChatId: " << this->chatId;
    qDebug() << "Covid: " << this->covid;
    qDebug() << "Date: " << this->date.getDayOfWeek() << " " << this->date.getDay() << " " << this->date.getMonth() << " " << this->date.getYear();
    qDebug() << "Country: " << this->country;
    qDebug() << "Age: " << this->age;
}
/*int main(){
    Date d = Date("23", "April", "2021", "Wed");

  d.setDay("45");
    d.toString();
    Person *p = new Person("Andrea", "Calabretta");
    p->printName();
    delete p;

    Patient *cp = new Patient("Caio", "Mario","negativo", "-", "23", "Aprile", "2021", "Wed");
    cp->toString();
    delete cp;
}*/

