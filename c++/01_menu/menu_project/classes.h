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
        QString fullname, country, age ;
    public:
        Person(QString f, QString c, QString a ): fullname(f), country(c), age(a) {};
        Person ():fullname(""), country(""), age(""){};
        ~Person();

        void setFullName(QString f){ fullname = f; }        
        void setCountry (QString c){ country = c; }
        void setAge(QString a){ age = a; }

        QString getFullName(){ return fullname; }        
        QString getCountry(){ return country; }
        QString getAge(){ return age; }
};

class Patient: public Person {
    private:
        QString chatId;
        QString covid;
    public:
        Date date;
        Patient(QString f, QString chId, QString cvd,QString d, QString m, QString y, QString dow, QString a, QString c):
            Person(f,a,c), chatId(chId), covid(cvd), date(d,m,y,dow){};
        Patient ():Person(),chatId(""),covid(""), date(){};
        ~Patient(){}

        void setChatId(QString chId){ chatId = chId; }
        void setCovid(QString cvd){ covid = cvd; }

        QString getChatId(){ return chatId; }
        QString getCovid(){ return covid; }

        void toString();
        QString toR();
};


#endif // CLASSES_H
