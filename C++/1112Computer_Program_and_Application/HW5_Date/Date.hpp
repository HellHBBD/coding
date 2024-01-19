#ifndef DATE_H
#define DATE_H

class Date
{
		public:
		Date(int = 1, int = 1, int = 2000);
		void print(char = '\0');
		void nextDay();

		private:
		void setYear(int = 2000);
		void setMonth(int = 1);
		void setDay(int = 1);
		void setDayMax();
		int Year, Month, Day, DayMax;
};
#endif
