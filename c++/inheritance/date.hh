#ifndef DATE_HH
#define DATE_HH

#include <iostream>
#include <string>

using namespace std;

class Date
{
	private:
		string day, month, year, dayOfWeek;
	public:
		Date(string d, string m, string y, string dow);
		void toString();
};
#endif
