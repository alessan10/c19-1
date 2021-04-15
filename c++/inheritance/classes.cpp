#include "classes.hh"

Date::Date(string d, string m, string y, string dow){
	this->day = d;
	this->month = m;
	this-> year = y;
	this->dayOfWeek = dow;
}

void Date::toString(){
	cout << dayOfWeek << " " day << " "<< month << " "<< year << endl;
}
