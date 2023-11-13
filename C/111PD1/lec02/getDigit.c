#include <math.h>
#include <stdio.h>

int getDigit(int num, int position) {
	int digit = 0;
	digit = (num / pow(10, position - 1));
	digit %= 10;
	return digit;
}

int main() {
	int num, digit;
	scanf("%d %d", &num, &digit);
	for (int i = 0; i < digit; i++)
		if (i % 2 == 0)
			printf("%d", getDigit(num, i + 1));
	printf("\n");
	for (int i = 0; i < digit; i++)
		if (i % 2 != 0)
			printf("%d", getDigit(num, i + 1));
	return 0;
}
