#include "classes.h"
#include <QDebug>


void Date::toString(){
    qDebug() <<  dayOfWeek << " " << day << " "<< month << " "<< year;
}

Person::~Person(){
    qDebug() << "Person destructor called";
}

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

Patient::Patient(QJsonObject object)
{
    setId( object["id"].toString());
    setName( object["name"].toString());
    setSurname ( object["surname"].toString());
    setAge( object["age"].toString());
    setChatId( object["chatid"].toString());
    setCovid( object["covid"].toString());
    date.setYear(object["year"].toString());
    date.setMonth( object["month"].toString());
    date.setDay( object["day"].toString());
    date.setDayOfWeek( object["weekday"].toString());
    setCountry( object["country"].toString());
}

QJsonObject  Patient::toJson()
{
    QJsonObject json;
    json["id"] = QString(id);
    json["name"] = QString(name);
    json["surname"] = QString(surname);
    json["age"] =QString(age);
    json["chatid"] = QString(chatId);
    json["covid"] =QString(covid);
    json["year"] =QString(date.getYear());
    json["month"] = QString(date.getMonth());
    json["day"] = QString(date.getDay());
    json["weekday"] =QString(date.getDayOfWeek());
    json["country"] =QString(country);

    return json;
}
void Patient::toString()
{
    qDebug() << "Id: " << id;
    qDebug() << "Name: " << name;
    qDebug() << "Surname: " << surname;
    qDebug() << "Age: " << age;
    qDebug() << "ChatId: " << chatId;
    qDebug() << "Covid: " << covid;
    qDebug() << "Date: " << date.getYear() << " " << date.getMonth() << " " << date.getDay() << " " << date.getDayOfWeek();
    qDebug() << "Country: " << country;

}

QString Patient::toR()
{
    QString str =
            "\"" + id + "\"," +
            "\"" + name + "\"," +
            "\"" + surname + "\"," +
            "\"" + age + "\"," +
            "\"" + chatId + "\"," +
            "\"" + covid + "\"," +
            "\"" + date.getYear() + "\"," +
            "\"" + date.getMonth() + "\"," +
            "\"" + date.getDay() + "\"," +
            "\"" + date.getDayOfWeek() + "\"," +
            "\"" + country + "\"";
    return str;
}

