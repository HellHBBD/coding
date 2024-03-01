#include <iostream>
using namespace std;

int main()
{
	string cmd;
	int n = 3;
	int s[n], top, i;

	top = 0;

	while (true) {
		cout << "cmd:";
		cin >> cmd;
		if (cmd == "push") {
			if (top >= n) { //full?
				cout << "isfull" << endl;
			} else {
				cout << "push:";
				cin >> i;
				s[top] = i;
				top++;
			}
		} else if (cmd == "pop") {
			if (top == 0) //empty?
				cout << " pop: nothing in stack" << endl;
			else {
				cout << " pop: " << s[top - 1] << endl;
				top--;
			}
		} else { //enter other command and break
			break;
		}
	}
	for (int j = 0; j < top; j++) //output all data in stack
		cout << s[j] << ",";
	return 0;
}
