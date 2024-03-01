#include <math.h>
#include <stdio.h>
#define r -b / (2 * a)

int main()
{
	int a, b, c;
	scanf("%d %d %d", &a, &b, &c);
	if (pow(b, 2) - 4 * a * c > 0) {
		int r1 = (-b + sqrt(pow(b, 2) - 4 * a * c)) / (2 * a);
		int r2 = (-b - sqrt(pow(b, 2) - 4 * a * c)) / (2 * a);
		printf("Two different roots x1=%d , x2=%d", r1, r2);
	} else if (pow(b, 2) - 4 * a * c == 0) {
		printf("Two same roots x=%d", r);
	} else {
		puts("No real root");
	}
	return 0;
}
