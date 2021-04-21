#ifndef CLASSES_H
#define CLASSES_H

#include <QString>

class Date{
    private:
        QString day, month, year, dayOfWeek;
    public:
        Date(QString d, QString m, QString y, QString dow): day(d),month(m), year(y), dayOfWeek(dow){};
        void setDay(QString d){ day = d; }
        void setMonth(QString m){ month = m; }
        void setYear(QString y){ year = y; }
        void setDayOfWeek(QString dow){ dayOfWeek = dow; }
        QString getDay(){ return day; }
        QString getMonth(){ return month; }
        QString getYear(){ return year; }
        QString getDayOfWeek(){ return dayOfWeek; }
        void toString();
};

class Person{
    protected:
        QString name, surname, age, country;
    public:
        Person(QString n, QString s, QString a, QString c): name(n), surname(s), age(a), country(c){};
        ~Person();
        void printName();
        void printSurname();
        void printAge();
        void printCountry();
};

class Patient: public Person {
    private:
        QString covid;
        QString chatId;
        Date date;
    public:
        Patient(QString n, QString s, QString cvd, QString chId, QString d, QString m, QString y, QString dow, QString a, QString c):
            Person(n,s,a,c),covid(cvd), chatId(chId), date(d,m,y,dow){};
        void toString();
};



#endif // CLASSES_H
