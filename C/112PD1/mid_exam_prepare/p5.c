#include <limits.h>
#include <stdio.h>

void check(int a, int b)
{
	if (b > 0 && a > INT_MAX - b)
		puts("overflow");
	else if (b < 0 && a < INT_MIN - b)
		puts("overflow");
	else
		puts("no overflow");
}

int main()
{
	int a, b;
	scanf("%d%d", &a, &b);
	check(a, b);
	return 0;
}
