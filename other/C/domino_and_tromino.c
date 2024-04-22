#include <stdio.h>

int numTilings(int n)
{
	if (n == 1)
		return 1;
	else if (n == 2)
		return 2;
	else if (n == 3)
		return 5;
	else
		return numTilings(n - 1) + 2 * numTilings(n - 2) +
		       5 * numTilings(n - 3);
}

int main()
{
	for (int i = 1; i < 10; i++)
		printf("%d ", numTilings(i));
	puts("");
	return 0;
}
