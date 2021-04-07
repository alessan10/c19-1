#include <iostream>

using namespace std;
class Date
{
	private:
		string day, month, year, dayOfWeek;
	public:
		Date(string d, string m, string y, string dow): day(d), month(m), year(y), dayOfWeek(dow){};
		void toString();
};

void Date::toString(){
	cout << "Data: " << day <<" "<< month <<" "<< year << " - " << dayOfWeek << endl;
}


int main()
{
	Date d = Date("12", "Jen", "2021", "Wednesday");
	d.toString();
}
