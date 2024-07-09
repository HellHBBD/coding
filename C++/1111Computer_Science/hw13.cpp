#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <iomanip>
using namespace std;

int main()
{
	srand(time(0));
	int inSquareCount = 5000000;
	int inCircleCount = 0;
	float Pi;
	float randomX;
	float randomY;
	for (int i = 0; i < 5000000; i++) {
		randomX = (float)rand() / RAND_MAX * 4 - 2;
		randomY = (float)rand() / RAND_MAX * 4 - 2;
		if (pow(randomX, 2) + pow(randomY, 2) <= 4)
			inCircleCount += 1;
	}
	Pi = (float)inCircleCount * 4 / inSquareCount;
	cout << "The Pi is: " << setprecision(6) << Pi;
	return 0;
}
