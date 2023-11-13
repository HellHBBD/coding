#include <stdio.h>

int main() {
	int year;
	while (scanf("%d", &year) != EOF)
		if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0))
			puts("閏年");
		else
			puts("平年");
	return 0;
}
