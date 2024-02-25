#ifndef PROGRESS_BAR_H
#define PROGRESS_BAR_H

#include <stdio.h>

void progress_bar(unsigned long long i, unsigned long long max)
{
	if (i == max) {
		puts("[====================]100%");
		return;
	}
	int percent = i * 100 / max;
	printf("\e[?25l[");
	for (int j = 0; j < 20; j++)
		if (j < percent / 5)
			printf("=");
		else
			printf(" ");
	printf("]");
	printf("%3d\%\r\e[?25h", percent);
}

#endif
