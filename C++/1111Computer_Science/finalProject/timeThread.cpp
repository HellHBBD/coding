#include <ctime>
#include <iomanip>
#include <iostream>
#include <queue>
#include <string>
#include <thread>
#include <unistd.h>

using namespace std;
queue<string> queueReturn;

void countDown(int time) {
	for (int i = 0; i < time; i++) {
		cout << "\r" << setw(2) << time - i;
		cout << "\033[18C";
		sleep(1);
	}
	cout << "\r"
		 << "\033[K"
		 << "time's up!" << endl;
	cout << "game over" << endl;
	queueReturn.push("time's up");
}

int main() {
	string userInput;
	thread time_thead(countDown, 5);
	string threadReturn;
	while (1) {
		cout << "   second(s) left:";
		threadReturn = queueReturn.front();
		if (threadReturn == "time's up")
			break;
		cin >> userInput;
		if (userInput == "quit") {
			time_thead.detach();
			break;
		}
		cout << "result report" << endl
			 << endl;
	}
	cout << "game over" << endl;
	// cout << endl;
	// system("pause");
	return 0;
}
