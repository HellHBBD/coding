#ifndef DATE_H
#define DATE_H

#include <stdio.h>
#include <time.h>

struct Date {
	unsigned long long year : 35;
	unsigned long long month : 4;
	unsigned long long weekday : 3;
	unsigned long long day : 5;
	unsigned long long hour : 5;
	unsigned long long minute : 6;
	unsigned long long second : 6;
};

void getDate(struct Date *date)
{
	time_t rawtime;
	time(&rawtime);
	struct tm timer = *localtime(&rawtime);
	date->year = timer.tm_year + 1900;
	date->month = timer.tm_mon + 1;
	date->weekday = 7 - (7 - timer.tm_wday) % 7;
	date->day = timer.tm_mday;
	date->hour = timer.tm_hour;
	date->minute = timer.tm_min;
	date->second = timer.tm_sec;
}

void printDate(struct Date date)
{
	const char *wday[] = { "Mon", "Tue", "Wed", "Thr", "Fri", "Sat", "Sun" };
	const char *month[] = { "Jan", "Feb", "Mar", "Apr", "May", "Jun",
				"Jul", "Aug", "Sep", "Oct", "Nov", "Dec" };
	printf("%s %s %d %02d:%02d:%02d %llu\n", wday[date.weekday - 1],
	       month[date.month - 1], date.day, date.hour, date.minute,
	       date.second, (unsigned long long)date.year);
}

#endif
