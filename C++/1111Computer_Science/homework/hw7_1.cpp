#include <bits/stdc++.h>
using namespace std;

bool isPrime(int n)
{
	int count = 0;
	for (int i = 1; i < n + 1; i++) {
		if (n % i == 0)
			count++;
	}
	if (count == 2)
		return true;
	else
		return false;
}

int main()
{
	int n;
	cout << "Plesase input a positive integer:";
	cin >> n;
	cout << "Prime factors:";
	for (int i = 1; i < n + 1; i++) {
		if (n % i == 0 and isPrime(i))
			cout << " " << i;
	}
	return 0;
}
