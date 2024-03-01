#include <iostream>
using namespace std;

int main()
{
	int perfect, good, bad, miss, maxCombo, bigP, blackP;
	float tp, tpTest;
	cout << "How many perfect?" << endl;
	cin >> perfect;
	cout << "How many good?" << endl;
	cin >> good;
	cout << "How many bad?" << endl;
	cin >> bad;
	cout << "How many miss?" << endl;
	cin >> miss;
	cout << "What\'s your tp?" << endl;
	cin >> tp;
	maxCombo = perfect + good + bad + miss;
	for (int i = 0; i < perfect + 1; i++) {
		bigP = i;
		blackP = perfect - i;
		tpTest = (bigP + blackP * 0.7 + good * 0.3) / maxCombo;
		if (tp == tpTest)
			break;
	}
	cout << "Your black perfect is " << blackP;
	return 0;
}
