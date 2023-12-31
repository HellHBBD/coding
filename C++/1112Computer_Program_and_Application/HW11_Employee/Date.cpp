// Fig. 11.10: Date.cpp
// Date class member- and friend-function definitions.
#include "Date.hpp"
#include <iostream>
#include <string>
using namespace std;

// initialize static member; one classwide copy
const int Date::days[] =
  {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

// Date constructor
Date::Date(int m, int d, int y) {
	setDate(m, d, y);
} // end Date constructor

// set month, day and year
void Date::setDate(int mm, int dd, int yy) {
	month = (mm >= 1 && mm <= 12) ? mm : 1;
	year = (yy >= 1900 && yy <= 2100) ? yy : 1900;

	// test for a leap year
	if (month == 2 && leapYear(year))
		day = (dd >= 1 && dd <= 29) ? dd : 1;
	else
		day = (dd >= 1 && dd <= days[month]) ? dd : 1;
} // end function setDate

// overloaded prefix increment operator
Date &Date::operator++() {
	helpIncrement(); // increment date
	return *this;	 // reference return to create an lvalue
} // end function operator++

// overloaded postfix increment operator; note that the
// dummy integer parameter does not have a parameter name
Date Date::operator++(int) {
	Date temp = *this; // hold current state of object
	helpIncrement();

	// return unincremented, saved, temporary object
	return temp; // value return; not a reference return
} // end function operator++

// add specified number of days to date
const Date &Date::operator+=(int additionalDays) {
	for (int i = 0; i < additionalDays; i++)
		helpIncrement();

	return *this; // enables cascading
} // end function operator+=

// if the year is a leap year, return true; otherwise, return false
bool Date::leapYear(int testYear) {
	if (testYear % 400 == 0 ||
		(testYear % 100 != 0 && testYear % 4 == 0))
		return true; // a leap year
	else
		return false; // not a leap year
} // end function leapYear

// determine whether the day is the last day of the month
bool Date::endOfMonth(int testDay) const {
	if (month == 2 && leapYear(year))
		return testDay == 29; // last day of Feb. in leap year
	else
		return testDay == days[month];
} // end function endOfMonth

int Date::getMonth() const {
	return month;
}

int Date::getDay() const {
	return day;
}

int Date::getYear() const {
	return year;
}

// function to help increment the date
void Date::helpIncrement() {
	// day is not end of month
	if (!endOfMonth(day))
		day++;			 // increment day
	else if (month < 12) // day is end of month and month < 12
	{
		month++; // increment month
		day = 1; // first day of new month
	}			 // end if
	else		 // last day of year
	{
		year++;	   // increment year
		month = 1; // first month of new year
		day = 1;   // first day of new month
	}			   // end else
} // end function helpIncrement

// overloaded output operator
ostream &operator<<(ostream &output, const Date &d) {
	static string monthName[13] = {"", "January", "February",
								   "March", "April", "May", "June", "July", "August",
								   "September", "October", "November", "December"};
	output << monthName[d.getMonth()] << ' ' << d.getDay() << ", " << d.getYear();
	return output; // enables cascading
} // end function operator<<

bool operator==(const Date &date1, const Date &date2) {
	if (date1.getMonth() == date2.getMonth() && date1.getYear() == date2.getYear())
		return true;
	else
		return false;
}

/**************************************************************************
 * (C) Copyright 1992-2011 by Deitel & Associates, Inc. and               *
 * Pearson Education, Inc. All Rights Reserved.                           *
 *                                                                        *
 * DISCLAIMER: The authors and publisher of this book have used their     *
 * best efforts in preparing the book. These efforts include the          *
 * development, research, and testing of the theories and programs        *
 * to determine their effectiveness. The authors and publisher make       *
 * no warranty of any kind, expressed or implied, with regard to these    *
 * programs or to the documentation contained in these books. The authors *
 * and publisher shall not be liable in any event for incidental or       *
 * consequential damages in connection with, or arising out of, the       *
 * furnishing, performance, or use of these programs.                     *
 **************************************************************************/
