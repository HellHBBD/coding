#include <iostream>
using namespace std;

int reverseInt(int x) {
	int digit;
	int reverse = 0;
	while (x != 0) {
		digit = x % 10;
		reverse = reverse * 10 + digit;
		x = x / 10;
	}
	return reverse;
}

int main() {
	int num;
	cin >> num;
	cout << reverseInt(num);
	return 0;
}
