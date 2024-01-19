#include <stdio.h>

int main()
{
		long a, b, c, d;
		scanf("%ld/%ld+%ld/%ld", &a, &b, &c, &d);
		printf("%ld/%ld", a * d + b * c, b * d);
		return 0;
}
