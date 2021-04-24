#ifndef CLASSES_H
#define CLASSES_H

#include <QString>
#include <QDate>

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
        QString fullname, age, country;
    public:
        Person(QString f, QString a, QString c): fullname(f), age(a), country(c){};
        Person ():fullname(""), age(""), country(""){};
        ~Person();

        void setFullName(QString f){ fullname = f; }
        void setAge(QString a){ age = a; }
        void setCountry (QString c){ country = c; }
        QString getFullName(){ return fullname; }
        QString getAge(){ return age; }
        QString getCountry(){ return country; }
};

class Patient: public Person {
    private:
        QString covid;
        QString chatId;
    public:
        Date date;
        Patient(QString f, QString cvd, QString chId, QString d, QString m, QString y, QString dow, QString a, QString c):
            Person(f,a,c),covid(cvd), chatId(chId), date(d,m,y,dow){};
        Patient ():Person(),covid(""), chatId(""), date(){};
        ~Patient(){}

        void setCovid(QString cvd){ covid = cvd; }
        void setChatId(QString chId){ chatId = chId; }
        QString getCovid(){ return covid; }
        QString getChatId(){ return chatId; }

        void toString();
        QString toR();
};


#endif // CLASSES_H
