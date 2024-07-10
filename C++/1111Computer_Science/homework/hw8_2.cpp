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
	int minimum = 1, maximum = 100;
	while (1) {
		cout << "Input " << minimum << " to " << maximum
		     << "(inclusive) (Or input -1 to leave):";
		cin >> userInputNumber;
		if (userInputNumber == -1) {
			cout << "Bye!";
			break;
		} else if (userInputNumber < minimum or
			   userInputNumber > maximum) {
			cout << "please input a number in range" << endl;
			continue;
		}
		if (userInputNumber == correctNumber) {
			cout << "You got it, the answer is " << correctNumber;
			break;
		} else if (userInputNumber > correctNumber) {
			maximum = userInputNumber - 1;
		} else if (userInputNumber < correctNumber) {
			minimum = userInputNumber + 1;
		}
	}
}
