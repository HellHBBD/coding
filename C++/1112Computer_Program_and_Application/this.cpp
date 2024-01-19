#include <iomanip>
#include <iostream>
using namespace std;

class Time
{
		public:
		Time(int = 0, int = 0, int = 0);
		Time &setHour(int);
		Time &setMinute(int);
		Time &setSecond(int);
		Time &printStandard(char = '\0');
		void printThis();

		private:
		int Hour, Minute, Second;
};

int main()
{
		Time t;
		t.printStandard('\n').setHour(18).setMinute(30).setSecond(22).printStandard('\n');
		cout << endl;
		t.printThis();
		return 0;
}

Time::Time(int hour, int minute, int second)
{
		setHour(hour);
		setMinute(minute);
		setSecond(second);
}

Time &Time::setHour(int hour)
{
		Hour = (hour >= 0 && hour < 24) ? hour : 0;
		return *this;
}

Time &Time::setMinute(int minute)
{
		Minute = (minute >= 0 && minute < 60) ? minute : 0;
		return *this;
}

Time &Time::setSecond(int second)
{
		Second = (second >= 0 && second < 60) ? second : 0;
		return *this;
}

Time &Time::printStandard(char display)
{
		cout << ((Hour == 0 || Hour == 12) ? 12 : Hour % 12) << ":" << setfill('0') << setw(2) << Minute << ":" << setw(2) << Second << (Hour < 12 ? " AM" : " PM") << display;
		return *this;
}

void Time::printThis()
{
		cout << "this:" << this << endl;
		//cout << "*this:" << *this << endl; error
		cout << "this->Hour:" << this->Hour << endl;
		cout << "(*this).Hour:" << (*this).Hour << endl;
}
