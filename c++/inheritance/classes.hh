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
};

class Person{
	private:
		string name, surname;
	public:
		Person(string n, string s);
		void printName();
		void printSurname();
};

class CPerson: public Person {
	private:
		string covid;
		string chatId;
		Date date;
	public:
//  costruttore
}
#endif
