#include <iostream>
using namespace std;

class Date {
	public:
		Date(int = 1, int = 1, int = 2000);
		void print();

	private:
		int month, day, year;
};

int main() {
	Date date1, date2(3, 29, 2023);
	cout << "date1:";
	date1.print();
	cout << "date2:";
	date2.print();
	date1 = date2; //memberwise assignment
	cout << "\nafter assign!\n"
		 << endl;
	cout << "date1:";
	date1.print();
	cout << "date2:";
	date2.print();
	return 0;
}

Date::Date(int m, int d, int y) {
	month = m;
	day = d;
	year = y;
}

void Date::print() {
	cout << month << "/" << day << "/" << year << endl;
}
