#ifndef TIME_H
#define TIME_H

class Time {
	public:
		Time(int = 0, int = 0, int = 0);
		void setTime(int, int, int);
		void printStandard(char = '\0');
		void tick();

	private:
		int Hour, Minute, Second;
};
#endif
