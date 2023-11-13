#include <stdio.h>

int main() {
	int a, b, c;
	scanf("%d-%d-%d", &a, &b, &c);
	if (a == b && b == c)
		printf("300");
	else if (a + b < c)
		printf("150");
	else if (a == c)
		printf("100");
	else if (a < b)
		printf("50");
	else
		printf("0");
	return 0;
}
