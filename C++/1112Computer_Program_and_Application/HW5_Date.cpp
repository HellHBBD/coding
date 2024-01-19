#include <iostream>
using namespace std;

class Date
{
		public:
		Date(int = 0, int = 1, int = 1);
		void setYear(int = 0);
		void setMonth(int = 1);
		void setDay(int = 1);
		int getYear();
		int getMonth();
		int getDay();
		void displayDate(char = '\0');

		private:
		void setDayMax();
		int Year, Month, Day, DayMax;
};

int main()
{
		Date date1, date2(-1, -1, -1), date3(2020, 100, 100), date4(2023, 4);
		cout << "initial: ";
		date1.displayDate('\n');
		cout << "argument error: ";
		date2.displayDate(' ');
		date3.displayDate('\n');
		cout << "few argument: ";
		date4.displayDate('\n');

		date1.setYear(2004);
		date1.setMonth(1);
		date1.setDay(31);
		cout << "not Feb. ";
		date1.displayDate('\n');

		date1.setMonth(2);
		cout << "leap year: ";
		date1.displayDate('\n');

		date1.setYear(2003);
		cout << "common year: ";
		date1.displayDate('\n');

		cout << "the year of date1: " << date1.getYear() << endl;
		cout << "the month of date2: " << date2.getMonth() << endl;
		cout << "the day of date3: " << date3.getDay() << endl;
		return 0;
}

Date::Date(int year, int month, int day)
{
		Year = 0;
		Month = 1;
		Day = 1;
		setYear(year);
		setMonth(month);
		setDay(day);
}

void Date::setYear(int year)
{
		if (year >= 0)
				Year = year;
		setDayMax();
}

void Date::setMonth(int month)
{
		if (month < 1)
				Month = 1;
		else if (month > 12)
				Month = 12;
		else
				Month = month;
		setDayMax();
}

void Date::setDay(int day)
{
		if (day < 1)
				Day = 1;
		else if (day > DayMax)
				Day = DayMax;
		else
				Day = day;
}

int Date::getYear()
{
		return Year;
}

int Date::getMonth()
{
		return Month;
}

int Date::getDay()
{
		return Day;
}

void Date::displayDate(char display)
{
		cout << Month << "/" << Day << "/" << Year << display;
}

void Date::setDayMax()
{
		if (Month == 2)
				if ((Year % 4 == 0 && Year % 100 != 0) || Year % 400 == 0)
						DayMax = 29;
				else
						DayMax = 28;

		else if (Month == 4 || Month == 6 || Month == 9 || Month == 11)
				DayMax = 30;

		else
				DayMax = 31;
		setDay(Day);
}
