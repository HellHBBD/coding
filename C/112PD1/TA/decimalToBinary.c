#include <math.h>
#include <stdio.h>

void decimalToBinary(int num)
{
	int maxBit = log2(num);
	/* for (int i = 31; i >= 0; i--) */
	for (int i = maxBit; i >= 0; i--)
		if (num & (1 << i))
			putchar('1');
		else
			putchar('0');
	puts("");
}

int main()
{
	int num;

	printf("Enter a decimal number: ");
	scanf("%d", &num);

	decimalToBinary(num);

	return 0;
}
