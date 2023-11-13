#include <iostream>
#include <stdexcept>
using namespace std;

class DayError: public domain_error {
};

class MonthError: public domain_error {
};

string dateConvert(int month, int day) {
	const int days[] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	const string monthName[] = {"January", "February",
								"March", "April", "May", "June", "July", "August",
								"September", "October", "November", "December"};
	if (month < 1 || month > 12)
		throw MonthError;
	else if (day < 1 || day > days[month - 1])
		throw DayError;
}

int main() {
	return 0;
}
