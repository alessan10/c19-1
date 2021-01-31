#include "date.h"

Date::Date(){
  day=0;
  month ="";
  year = 0;
  dayOfWeek ="";

}

Date::~Date()
{

}

Date* Date::conversion(QDate & q){


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

    this->year = q.year();
    this->day = q.day();

    qDebug() << "ANNO: "<< this->year;
    qDebug() << "Mese: " << this->month;
    qDebug() << "Giorno: " << this->day;
    qDebug() << "Day of The week: " << this->dayOfWeek;

    return this;

}
