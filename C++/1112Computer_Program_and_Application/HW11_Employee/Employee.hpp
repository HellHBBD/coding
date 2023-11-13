// Fig. 13.13: Employee.hpp
// Employee abstract base class.
#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include "Date.hpp"
#include <string> // C++ standard string class
using namespace std;

class Employee {
	public:
		Employee(const string &, const string &, const string &, int, int, int);
		virtual ~Employee(){};

		void setFirstName(const string &); // set first name
		string getFirstName() const;	   // return first name

		void setLastName(const string &); // set last name
		string getLastName() const;		  // return last name

		void setSocialSecurityNumber(const string &); // set SSN
		string getSocialSecurityNumber() const;		  // return SSN

		void setBirthDate(int month, int day, int year);
		Date getBirthDate() const;
		// pure virtual function makes Employee abstract base class
		virtual double earnings() const = 0; // pure virtual
		virtual void print() const;			 // virtual
		static void setCurrentDate(int, int, int);
		static Date getCurrentDate();

	private:
		string firstName;
		string lastName;
		string socialSecurityNumber;
		Date birthDate;
		static Date currentDate;
}; // end class Employee

#endif // EMPLOYEE_H

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
