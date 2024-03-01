#include <stdio.h>

int main()
{
	double P = 1, p;
	for (int i = 0; i < 5; i++) {
		scanf("%lf", &p);
		P *= p;
	}
	printf("%.15lf", P);
	return 0;
}
