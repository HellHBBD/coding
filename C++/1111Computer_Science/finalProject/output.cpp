#include <iostream>
#include <unistd.h>
using namespace std;

void cursorUp(int line) {
	for (int i = 0; i < line; i++) {
		cout << "\033[F";
		sleep(1);
	}
}

void cursorBack(int line) {
	for (int i = 0; i < line; i++) {
		cout << "\n";
		sleep(1);
	}
}

int main() {
	cout << "time" << endl;
	for (int i = 0; i < 2; i++)
		cout << "result" << endl;
	sleep(1);
	cursorUp(3);
	cout << "time change";
	sleep(1);
	cursorBack(3);
	cout << "back";
	return 0;
}