#ifndef CLASSES_HH
#define CLASSES_HH

#include <iostream>
#include <string>

using namespace std;

class Date{
	private:
		string day, month, year, dayOfWeek;
	public:
		Date(string d, string m, string y, string dow);
		void toString();
		string getDay(){ return day;}
		string getMonth(){ return month;}
		string getYear(){ return year;}
		string getDayOfWeek(){ return dayOfWeek; }
		
};

class Person{
	protected:
		string name, surname;
	public:
		Person(string n, string s);
		~Person();
		void printName();
		void printSurname();
};

class CPerson: public Person {
	private:
		string covid;
		string chatId;
		Date date;
	public:
//		CPerson(string n, string s, string cvd, string chId): Person(n,s), covid(cvd), chatId(chId){};
		CPerson(string n, string s, string cvd, string chId, string d, string m, string y, string dow);
		void toString();
};

#endif
