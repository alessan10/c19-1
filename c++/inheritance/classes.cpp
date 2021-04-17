#include "classes.hh"

Date::Date(string d, string m, string y, string dow){
	this->day = d;
	this->month = m;
	this->year = y;
	this->dayOfWeek = dow;
}

void Date::toString(){
	cout << dayOfWeek << " " << day << " "<< month << " "<< year << endl;
}

Person::Person(string n, string s):name(n),surname(s){}

Person::~Person(){
	cout << "Distruttore Person chiamato" << endl;
}
void Person::printName(){
	cout << "Name : " << name << endl;
}

void Person::printSurname(){
	cout << "Surname : " << surname << endl;
}


CPerson::CPerson(string n, string s, string cvd, string chId, string d, string m, string y, string dow ): Person(n,s), date(d,m,y,dow) {
	this->covid = cvd;
	this->chatId = chId;
}


void CPerson::toString(){
	cout << name <<" "<< surname <<" "<< covid <<" "<< chatId <<" "<< date.getDay() <<" "<< date.getMonth() <<" "<< date.getYear() <<" "<< date.getDayOfWeek() << endl;

//	cout << this->name <<" "<< surname <<" "<< covid <<" "<< chatId << endl;
}
int main(){
	Date d = Date("23", "April", "2021", "Wed");
	d.toString();
	
	Person *p = new Person("Andrea", "Calabretta");
	p->printName();
	delete p;

	CPerson *cp = new CPerson("Caio", "Mario","negativo", "-", "23", "Aprile", "2021", "Wed");
	cp->toString();
	delete cp;
}

