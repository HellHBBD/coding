#include <iostream>
#include <iomanip>
using namespace std;

#include "Time.hpp"

Time::Time(int hour, int minute, int second)
{
	setTime(hour, minute, second);
}

void Time::setTime(int h, int m, int s)
{
	Hour = (h >= 0 && h < 24) ? h : 0;
	Minute = (m >= 0 && m < 60) ? m : 0;
	Second = (s >= 0 && s < 60) ? s : 0;
}

void Time::printStandard(char display)
{
	cout << ((Hour == 0 || Hour == 12) ? 12 : Hour % 12) << ":"
	     << setfill('0') << setw(2) << Minute << ":" << setw(2) << Second
	     << (Hour < 12 ? " AM" : " PM") << display;
}

void Time::tick()
{
	Second++;
	if (Second == 60) {
		Second = 0;
		Minute++;
	}
	if (Minute == 60) {
		Minute = 0;
		Hour++;
	}
	if (Hour == 24)
		Hour = 0;
}
