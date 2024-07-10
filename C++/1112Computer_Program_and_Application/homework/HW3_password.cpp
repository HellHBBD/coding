#include <iostream>
using namespace std;

void printx(int n)
{
	for (int i = 0; i < n; i++)
		cout << "x";
}

int main()
{
	char c;
	bool isNumber;
	int digit;
	string line, numberBuffer;
	while (1) { //user input loop
		cout << "(type \"quit\" to escape)" << endl;
		digit = 0;
		isNumber = true;
		line.clear();
		numberBuffer.clear();
		getline(cin, line);
		const int len = line.length();
		if (line == "quit")
			break;
		for (char *c = &line[0]; c - &line[0] < len; c++) {
			if (isalpha(*c)) { //character
				if (digit != 0) {
					cout << numberBuffer;
					numberBuffer.clear();
					digit = 0;
				}
				cout << *c;
				isNumber = false;
			} else if (isdigit(*c)) { //number
				if (isNumber) {
					numberBuffer += *c;
					digit++;
				} else
					cout << *c;
			} else { //else
				if (digit == 0) {
					cout << *c;
					isNumber = true;
				} else {
					printx(digit);
					cout << *c;
					isNumber = true;
					numberBuffer.clear();
					digit = 0;
				}
			}
		}
		if (digit != 0)
			printx(digit);
		cout << endl;
	}
	return 0;
}
