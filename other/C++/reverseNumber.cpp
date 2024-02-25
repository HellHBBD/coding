#include <iostream>
using namespace std;

long reverseInt(long x)
{
	int digit;
	long reverse = 0;
	while (x != 0) {
		digit = x % 10;
		reverse = reverse * 10 + digit;
		x = x / 10;
	}
	return reverse;
}

int main()
{
	long num;
	cin >> num;
	cout << reverseInt(num);
	return 0;
}
