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
        QString name, surname;
    public:
        Person(QString n, QString s): name(n), surname(s){};
        ~Person();
        void printName();
        void printSurname();
};

class Patient: public Person {
    private:
        QString covid;
        QString chatId;
        Date date;
    public:
        Patient(QString n, QString s, QString cvd, QString chId, QString d, QString m, QString y, QString dow): Person(n,s),covid(cvd), chatId(chId), date(d,m,y,dow){};
        void toString();
};



#endif // CLASSES_H