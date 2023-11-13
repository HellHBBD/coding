#include <stdio.h>

int main() {
	int a, b, c, d;
	scanf("%d %d", &a, &b);
	scanf("%d %d", &c, &d);
	int m = a * d + b * c;
	int n = b * d;
	if (m < n)
		printf("%d", 1);
	else
		printf("%d", 0);
	return 0;
}
