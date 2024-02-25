#include <stdio.h>

int main()
{
	int a, b, x, y, z, checknumber, digit;
	a = 0;
	b = 0;
	for (int i = 0; i < 12; ++i) {
		scanf("%1d", &digit);
		if (i % 2 != 0)
			a += digit;
		if (i % 2 == 0)
			b += digit;
	}
	x = 3 * a + b;
	y = x - 1;
	z = y % 10;
	checknumber = 9 - z;
	printf("%d", checknumber);
	return 0;
}
