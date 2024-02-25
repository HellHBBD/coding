#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Using rand() to generate a random number between 1 and 6.
double rollDice(int roll)
{
	int sum = 0;
	for (int i = 0; i < roll; i++)
		sum += rand() % 6 + 1;
	return (double)sum / roll;
}

int main()
{
	srand(time(0));

	printf("The Expected Value is %lf\n", rollDice(10000));

	return 0;
}
