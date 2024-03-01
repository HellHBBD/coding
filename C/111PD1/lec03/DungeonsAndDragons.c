#include <stdio.h>

int main()
{
	int d1, d2, d3, d4, d5, d6;
	scanf("%d %d %d %d %d %d", &d1, &d2, &d3, &d4, &d5, &d6);
	if ((d1 + d2 + d3) <= 10) {
		printf("Player attacks: ");
		if (d4 == d6 && d5 == d6)
			printf("Critical Hit");
		else if ((d4 + d5) >= d6)
			printf("Normal Hit");
		else
			printf("Miss");
	} else {
		printf("Dragon attacks: ");
		if (d4 == d6 || d5 == d6 || d4 == d5)
			printf("Miss");
		else if ((d4 + d5) != d6)
			printf("Normal Hit");
		else
			printf("Critical Hit");
	}
	return 0;
}
