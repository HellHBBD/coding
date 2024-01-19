#include "clock.h"
#include <stdio.h>
#include <stdlib.h>

unsigned long long int begin, end;

int main()
{

		begin = rdtsc();
		/*---------------------------
	your function
	---------------------------*/
		end = rdtsc();

		printf("Execute cycles %llu \n", (end - begin));
}
