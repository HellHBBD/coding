#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void mySwap(int s[], int i, int j)
{
	int temp = s[i];
	if (s[i] > s[j]) {
		s[i] = s[j];
		s[j] = temp;
	}
}

void printArray(int s[], int length)
{
	for (int i = 0; i < length; i++) {
		cout << s[i] << " ";
	}
	cout << endl;
}

int main()
{
	srand(time(0));
	int num[10] = {};

	for (int i = 0; i < 10; i++) {
		num[i] = 1 + rand() % 1000;
	}

	cout << "Ten random numbers: ";
	printArray(num, 10);

	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 9 - i; j++) {
			mySwap(num, j, j + 1);
		}
	}

	cout << "Sorted by bubble sorting: ";
	printArray(num, 10);

	return 0;
}
