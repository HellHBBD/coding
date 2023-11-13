#include <stdio.h>

int main() {
	int days, starting_day;
	puts("Enter number of days in month: ");
	scanf("%d", &days);
	puts("Enter starting day of the week (1=Sun, 7=Sat): ");
	scanf("%d", &starting_day);
	int count = 0;
	for (int i = 0; i < days;) {
		if (starting_day - 1) {
			printf("   ");
			starting_day--;
			count++;
			continue;
		}
		printf("%2d", i + 1);
		i++;
		count++;
		if (count % 7 == 0)
			puts("");
		else if (i < days)
			printf(" ");
	}
	return 0;
}
