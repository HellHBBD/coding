#include <iomanip>
#include <iostream>
using namespace std;

class Time { //Time type occupied (4*3) bytes
	private:
		int hour;	//0 ~ 23
		int minute; //0 ~ 59
		int second; //0 ~ 59
	public:
		Time(); //constructor has no return type
		void setTime(int, int, int);
		void printUniversal();
		void printStandard();
}; //must end the class definition

int main() {
	Time t;
	Time();
	t.printUniversal();
	cout << endl;
	t.printStandard();
	return 0;
}

Time::Time() { //call automatically when construct an object
	hour = minute = second = 0;
}

void Time::setTime(int h, int m, int s) {
	hour = (h >= 0 && h < 24) ? h : 0;
	minute = (m >= 0 && m < 60) ? m : 0;
	second = (s >= 0 && s < 60) ? s : 0;
}

void Time::printUniversal() {
	cout << setfill('0') << setw(2) << hour << ":" << setw(2) << minute << ":" << setw(2) << second;
}

void Time::printStandard() {
	cout << setfill('0') << setw(2) << (hour > 12 ? hour : hour % 12) << ":" << setw(2) << minute << ":" << setw(2) << second << " " << (hour > 12 ? "P.M." : "A.M.");
}
