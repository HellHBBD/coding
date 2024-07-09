#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
	srand(time(0));
	int random, drawCount, count40, count30, count20, count11;
	const int maxRound = 10000000;
	count11 = 0;
	count20 = 0;
	count30 = 0;
	count40 = 0;
	for (int round = 0; round < maxRound; round++) {
		drawCount = 0;
		for (int draw = 0; draw < 471; draw++) {
			random = rand() % 10;
			if (random == 0)
				drawCount += 1;
		}
		if (drawCount <= 40)
			count40 += 1;
		if (drawCount <= 30)
			count30 += 1;
		if (drawCount <= 20)
			count20 += 1;
		if (drawCount <= 11)
			count11 += 1;
		cout << round * 100 / maxRound << "\% has completed!\r";
	}
	cout << 100 << "\% has completed!" << endl;
	cout << "The estimated prob. of winning <= 40 items: "
	     << (float)count40 / maxRound << endl;
	cout << "The estimated prob. of winning <= 30 items: "
	     << (float)count30 / maxRound << endl;
	cout << "The estimated prob. of winning <= 20 items: "
	     << (float)count20 / maxRound << endl;
	cout << "The estimated prob. of being unlucky as the streamer (<=11 items): "
	     << (float)count11 / maxRound << endl;
	return 0;
}
