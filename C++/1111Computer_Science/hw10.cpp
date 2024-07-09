#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

int main()
{
	srand(time(0));
	int carDoor, selectDoor, openDoor, switchDoor;
	int strategyA = 0;
	int strategyB = 0;
	for (int i = 0; i < 5000; i++) {
		carDoor = 1 + rand() % 3;
		selectDoor = 1 + rand() % 3;
		while (true) {
			openDoor = 1 + rand() % 3;
			if (openDoor != carDoor and openDoor != selectDoor)
				break;
		}
		while (true) {
			switchDoor = 1 + rand() % 3;
			if (switchDoor != openDoor and switchDoor != selectDoor)
				break;
		}
		if (switchDoor == carDoor)
			strategyA += 1;
		if (selectDoor == carDoor)
			strategyB += 1;
	}
	cout << "If you do not switch, the prob. of winning is: "
	     << strategyB / 5000.0 << endl;
	cout << "If you switch, the prob. of winning is: " << strategyA / 5000.0
	     << endl;

	return 0;
}
