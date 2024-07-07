#include <time.h>
#include <stdio.h>

#include <timer.h>

void timer_start()
{
	start = time(NULL) - start;
}

void timer_end()
{
	start = time(NULL) - start;
	printf("total time: %ld\n", start);
}
