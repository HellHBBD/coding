#include <stdio.h>
#define AMERICANO 110
#define LATTE 150
#define CAPPUCCINO 135
#define MOCHA 145

int main()
{
		int i, j;
		scanf("%d %d", &i, &j);
		if (i == 1)
				printf("The total price is %d dollars!", AMERICANO * j);
		else if (i == 2)
				printf("The total price is %d dollars!", LATTE * j);
		else if (i == 3)
				printf("The total price is %d dollars!", CAPPUCCINO * j);
		else if (i == 4)
				printf("The total price is %d dollars!", MOCHA * j);
		else
				printf("Wait, what?");
		return 0;
}
