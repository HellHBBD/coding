#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cout << "Please input a positive integer:";
	cin >> n;
	cout << "Factors: ";
	for (int i = 2; i < n; i++) {
		if (n % i == 0)
			cout << i << " ";
	}
	return 0;
}
