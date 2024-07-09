#include <bits/stdc++.h>
using namespace std;

int main()
{
	char a;
	cout << "Please input an alphabet:";
	cin >> a;
	int ascii = static_cast<int>(a);
	cout << "After converting:";
	if (ascii >= 'A' and ascii <= 'Z')
		cout << static_cast<char>(ascii - 'A' + 'a');
	else if (ascii >= 'a' and ascii <= 'z')
		cout << static_cast<char>(ascii - 'a' + 'A');
	return 0;
}
