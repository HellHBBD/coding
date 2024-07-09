#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cout << "Please input the height of your pyramid:";
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < (n - i - 1); j++) {
			cout << " ";
		}
		for (int j = 0; j < (2 * i + 1); j++) {
			cout << "x";
		}
		cout << endl;
	}
	return 0;
}
