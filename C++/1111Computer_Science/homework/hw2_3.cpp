#include <bits/stdc++.h>
using namespace std;

int main()
{
	int num1, num2;
	cin >> num1;
	cin >> num2;
	cout << "Input the first interger:" << num1 << endl;
	cout << "Input the second interger:" << num2 << endl;
	if (num1 > num2) {
		cout << "After " << num1 << " is devided by " << num2
		     << ", the remainder is: " << num1 % num2;
	} else {
		cout << "After " << num2 << " is devided by " << num1
		     << ", the remainder is: " << num2 % num1;
	}
	return 0;
}
