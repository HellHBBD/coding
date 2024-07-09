#include <bits/stdc++.h>
using namespace std;

int main()
{
	int f0 = 0;
	int f1 = 1;
	int f = 0;
	int count = 1;
	//cout << "F0=" << f0 << endl << "F1=" << f1 << endl;
	while (true) {
		f = f0 + f1;
		f0 = f1;
		f1 = f;
		count += 1;
		cout << "F" << count << "=" << f << endl;
		if (count == 20)
			break;
	}
	return 0;
}
