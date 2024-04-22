#include <iomanip>
#include <iostream>
using namespace std;

class Time {
    public:
	Time(int = 0, int = 0, int = 0);
	Time &setTime(int, int, int);
	Time &setHour(int);
	Time &setMinute(int);
	Time &setSecond(int);
	int getHour() const;
	int getMinute() const;
	int getSecond() const;
	void printUniversal(char = '\0') const;
	void printStandard(char = '\0') const;

    private:
	int Second;
};

int main()
{
	Time t;
	t.setHour(18).setMinute(30).setSecond(22);
	cout << "Universal time: ";
	t.printUniversal('\n');
	cout << "Standard time: ";
	t.printStandard('\n');
	cout << endl;
	cout << "New standard time: ";
	t.setTime(20, 20, 20).printStandard('\n');
	return 0;
}

Time::Time(int hour, int minute, int second)
{
	Second = 0;
	setTime(hour, minute, second);
}

Time &Time::setTime(int hour, int minute, int second)
{
	setHour(hour);
	setMinute(minute);
	setSecond(second);
	return *this;
}

Time &Time::setHour(int hour)
{
	hour = (hour > 0 && hour < 24) ? hour : 0;
	int Minute = Second % 3600 / 60;
	Second = Second % 60;
	Second = hour * 3600 + Minute * 60 + Second;
	return *this;
}

Time &Time::setMinute(int minute)
{
	minute = (minute > 0 && minute < 60) ? minute : 0;
	int Hour = Second / 3600;
	Second = Second % 60;
	Second = Hour * 3600 + minute * 60 + Second;
	return *this;
}

Time &Time::setSecond(int second)
{
	second = (second > 0 && second < 60) ? second : 0;
	int Hour = Second / 3600;
	int Minute = Second % 3600 / 60;
	Second = Hour * 3600 + Minute * 60 + second;
	return *this;
}

int Time::getHour() const
{
	return Second / 3600;
}

int Time::getMinute() const
{
	return Second % 3600 / 60;
}

int Time::getSecond() const
{
	return Second % 60;
}

void Time::printUniversal(char display) const
{
	int hour = Second / 3600;
	int minute = Second % 3600 / 60;
	int second = Second % 60;
	cout << setfill('0') << setw(2) << hour << ":" << setw(2) << minute
	     << ":" << setw(2) << second << display;
}

void Time::printStandard(char display) const
{
	int hour = Second / 3600;
	int minute = Second % 3600 / 60;
	int second = Second % 60;
	cout << ((hour == 0 || hour == 12) ? 12 : hour % 12) << ":"
	     << setfill('0') << setw(2) << minute << ":" << setw(2) << second
	     << (hour < 12 ? " AM" : " PM") << display;
}
