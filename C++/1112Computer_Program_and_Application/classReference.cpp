#include <iostream>
using namespace std;

class Time
{
		public:
		Time(int = 0);
		int &badSetHour(int);

		private:
		int hour;
};

Time::Time(int hh)
{
		hour = hh;
}

int &Time::badSetHour(int hh)
{
		hour = hh;
		return hour; //return reference and pointer are dangerous
}

int main()
{
		Time T;
		int &hourRef = T.badSetHour(20);
		cout << "set hour:" << hourRef << endl;
		hourRef = 30;
		cout << "modify hour:" << hourRef << endl; //user can modify directly
		return 0;
}
