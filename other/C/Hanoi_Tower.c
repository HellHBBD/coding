#include <stdio.h>

unsigned long long int hanoi(unsigned long long int n)
{
	return n == 1 ? 1 : 1 + 2 * hanoi(n - 1);
}

int main()
{
	for (int i = 1; i < 64; i++)
		printf("%lld\n", hanoi(i));
	return 0;
}
