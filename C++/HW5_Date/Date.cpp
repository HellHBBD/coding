#include <iostream>
#include "Date.hpp"
using namespace std;

//int main(){
//	return 0;
//}

//public
Date::Date(int month,int day,int year){
	Year = 2000;
	Month = 1;
	Day = 1;
	setYear(year);
	setMonth(month);
	setDay(day);
}

void Date::print(char display){
	cout << Month << "/" << Day << "/" << Year << display;
}

void Date::nextDay(){
	Day++;
	if (Day > DayMax){
		Day = 1;
		Month++;
	}
	if (Month > 12){
		Month = 1;
		Year++;
	}
}

//private
void Date::setYear(int year){
	if (year >= 0)
		Year = year;
	else
		cout << "error: Year < 0 !" << endl;
	setDayMax();
}

void Date::setMonth(int month){
	if (month < 1){
		Month = 1;
		cout << "error: Month < 1 !" << endl;
	}
	else if (month > 12){
		Month = 12;
		cout << "error: Month > 12 !" << endl;
	}
	else
		Month = month;
	setDayMax();
}

void Date::setDay(int day){
	if (day < 1){
		Day = 1;
		cout << "error: Day < 1 !" << endl;
	}
	else if (day > DayMax){
		Day = DayMax;
		cout << "error: Day > max Day !" << endl;
	}
	else
		Day = day;
}

void Date::setDayMax(){
	if (Month == 2){
		if ((Year%4 == 0 && Year%100 != 0) || Year%400 == 0)
			DayMax = 29;
		else
			DayMax = 28;
	}
	else if (Month == 4 || Month == 6 || Month == 9 || Month == 11){
		DayMax = 30;
	}
	else{
		DayMax = 31;
	}
	setDay(Day);
}
