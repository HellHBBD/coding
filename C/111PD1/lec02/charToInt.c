#include <stdio.h>

int main()
{
	char a[5] = "12345";
	int total, digit;
	printf("%d\n", total);
	scanf("%d", &digit);
	total = total + (a[digit] - '0');
	printf("%d", total);
	return 0;
}
