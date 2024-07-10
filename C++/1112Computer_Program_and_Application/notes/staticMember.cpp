#include <iostream>
#include <string>
using namespace std;

class Employee {
    public:
	Employee(const string &, const string &);
	~Employee();
	string getFirstName() const;
	string getLastName() const;
	static int getCount();

    private:
	string firstName, lastName;
	static int count; //all object share one variable
};

int main()
{
	cout << "object count:" << Employee::getCount() << endl;
	{
		Employee e1("Paul", "Yu");
		cout << "object count:" << Employee::getCount() << endl;
		Employee e2("Jim", "Yu");
		cout << "object count:" << Employee::getCount() << endl;
	}
	cout << "object count:" << Employee::getCount() << endl;
	return 0;
}

int Employee::count = 0;

Employee::Employee(const string &first, const string &last)
{
	firstName = first;
	lastName = last;
	++count;
	cout << firstName << " " << lastName << " constructed." << endl;
}

Employee::~Employee()
{
	--count;
	cout << firstName << " " << lastName << " destructed." << endl;
}

string Employee::getFirstName() const
{
	return firstName;
}

string Employee::getLastName() const
{
	return lastName;
}

int Employee::getCount()
{
	return count;
}
