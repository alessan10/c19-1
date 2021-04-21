#include "classes.h"
#include <QDebug>



void Date::toString(){
    qDebug() <<  dayOfWeek << " " << day << " "<< month << " "<< year;
}

Person::~Person(){
    qDebug() << "Distruttore Person chiamato";
}
void Person::printName(){
    qDebug() << "Name : " << name ;
}

void Person::printSurname(){
    qDebug() << "Surname : " << surname ;
}

void Person::printAge(){
    qDebug() << "Age : " << age ;
}

void Person::printCountry(){
    qDebug() << "Country : " << country ;
}

void Patient::toString(){
    qDebug() << name <<" "<< surname <<" "<< covid <<" "<< chatId <<" "<< date.getDay() <<" "<< date.getMonth() <<" "<< date.getYear() <<" "<< date.getDayOfWeek() <<" "<< age <<" "<< country ;

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

