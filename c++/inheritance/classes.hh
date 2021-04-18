#ifndef CLASSES_HH
#define CLASSES_HH

#include <iostream>
#include <string>

using namespace std;

class Date{
	private:
		string day, month, year, dayOfWeek;
	public:
		Date(string d, string m, string y, string dow): day(d),month(m), year(y), dayOfWeek(dow){};
		void setDay(string d){ day = d; }
		void setMonth(string m){ month = m; }
		void setYear(string y){ year = y; }
		void setDayOfWeek(string dow){ dayOfWeek = dow; }
		string getDay(){ return day; }
		string getMonth(){ return month; }
		string getYear(){ return year; }
		string getDayOfWeek(){ return dayOfWeek; }
		void toString();
};

class Person{
	protected:
		string name, surname;
	public:
		Person(string n, string s): name(n), surname(s){};
		~Person();
		void printName();
		void printSurname();
};

class Patient: public Person {
	private:
		string covid;
		string chatId;
		Date date;
	public:
		Patient(string n, string s, string cvd, string chId, string d, string m, string y, string dow): Person(n,s),covid(cvd), chatId(chId), date(d,m,y,dow){};
		void toString();
};

#endif
