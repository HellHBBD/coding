#include <stdio.h>
#include "date.h"

int main()
{
	printf("struct Date is %ld bytes\n", sizeof(struct Date));
	struct Date date;
	getDate(&date);
	printDate(date);
	return 0;
}
