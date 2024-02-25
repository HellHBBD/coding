#include <stdio.h>

int a_1 = 1, a_n = 5, d = 1;

int sum(int a_1)
{
	if (a_1 == a_n)
		return a_n;
	return a_1 + sum(a_1 + d);
}

int main()
{
	printf("%d", sum(a_1));
	return 0;
}
