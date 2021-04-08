#include "date.hh"

Date::Date(string d, string m, string y, string dow){
	this->day = d;
	this->month = m;
	this->year = y;
	this->dayOfWeek = dow;
}

void Date::toString(){
	cout << "Data: " << day <<" "<< month <<" "<< year << " - " << dayOfWeek << endl;
}


int main()
{
	Date d = Date("12", "Jen", "2021", "Wednesday");
	d.toString();
}
