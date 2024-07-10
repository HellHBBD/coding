#include <iostream>
#include <stdexcept>
using namespace std;

class DayError : public domain_error {
    public:
	DayError()
		: domain_error("Invalid day")
	{
	}
};

class MonthError : public domain_error {
    public:
	MonthError()
		: domain_error("Invalid month")
	{
	}
};

string dateConvert(int month, int day)
{
	const int days[] = { 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	const string monthName[] = { "January", "February", "March",
				     "April",	"May",	    "June",
				     "July",	"August",   "September",
				     "October", "November", "December" };
	if (month < 1 || month > 12)
		throw MonthError();
	else if (day < 1 || day > days[month - 1])
		throw DayError();
	else
		return monthName[month - 1] + " " + to_string(day);
}

int main()
{
	try {
		cout << dateConvert(2, 29) << endl;
		cout << dateConvert(2, 30) << endl;
	} catch (const exception &e) {
		cerr << e.what() << endl;
	}
	return 0;
}
