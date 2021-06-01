#ifndef CLASSES_H
#define CLASSES_H

#include <QString>
#include <QDate>
#include <QJsonObject>

class Date{
    private:
        QString day, month, year, dayOfWeek;
    public:
        Date(QString d, QString m, QString y, QString dow): day(d),month(m), year(y), dayOfWeek(dow){}
        Date():day(""), month(""), year(""), dayOfWeek(""){}
        ~Date(){}
        void setDay(QString d){ day = d; }
        void setMonth(QString m){ month = m; }
        void setYear(QString y){ year = y; }
        void setDayOfWeek(QString dow){ dayOfWeek = dow; }
        QString getDay(){ return day; }
        QString getMonth(){ return month; }
        QString getYear(){ return year; }
        QString getDayOfWeek(){ return dayOfWeek; }
        void toString();        
        void conversion(QDate &q);//per cambiare il formato dei mesi dal numero alla parola (8->August) (1->Lunedì)
};

class Person{
    protected:
        QString id, name, surname, age, country ;
    public:
        Person(QString i, QString n, QString s, QString a, QString c): id(i), name(n), surname(s), age(a), country(c){};
        Person ():id(""), name(""), surname(""), age(""), country(""){};
        ~Person();

        void setId (QString i){ id = i; }
        void setName(QString n){ name = n; }
        void setSurname(QString s){ surname = s; }
        void setAge(QString a){ age = a; }
        void setCountry (QString c){ country = c; }

        QString getId(){ return id; }
        QString getName(){ return name; }
        QString getSurname(){ return surname; }
        QString getAge(){ return age; }
        QString getCountry(){ return country; }
};

class Patient: public Person {
    private:
        QString chatId;
        QString covid;
    public:
        Date date;
        Patient(QString i, QString n, QString s, QString a, QString chId, QString cvd, QString y, QString m, QString d, QString dow,  QString c):
            Person(i,n,s,a,c), chatId(chId), covid(cvd), date(y,m,d,dow){};
        Patient ():Person(),chatId(""),covid(""), date(){};
        Patient(QJsonObject json);

        ~Patient(){}

        void setChatId(QString chId){ chatId = chId; }
        void setCovid(QString cvd){ covid = cvd; }

        QString getChatId(){ return chatId; }
        QString getCovid(){ return covid; }

        void toString();
        QJsonObject toJson();
        QString toR();
};


#endif // CLASSES_H
