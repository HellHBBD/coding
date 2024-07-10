#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
	int userInputNumber;
	srand(time(0));
	int correctNumber = 1 + rand() % 100;
	cout << "correct answer:" << correctNumber << endl;
	while (1) {
		cout << "Input a number between 1 and 100 (inclusive) (Or input -1 to leave):";
		cin >> userInputNumber;
		if (userInputNumber == -1) {
			cout << "Bye!";
			break;
		}
		if (userInputNumber == correctNumber) {
			cout << "You got it, the answer is " << correctNumber;
			break;
		} else if (userInputNumber > correctNumber) {
			cout << "Lower" << endl;
		} else if (userInputNumber < correctNumber) {
			cout << "Higher" << endl;
		}
	}
}
