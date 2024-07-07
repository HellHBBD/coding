#include <iostream>
using namespace std;

#define abs(a, b) ((a) > (b) ? (a) - (b) : (b) - (a))

int main()
{
	int perfect, good, bad, miss, maxCombo, bigP, blackP;
	double tp, tpTest;
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
		if (abs(tp, tpTest * 100) <= 0.01)
			break;
	}
	cout << "Your black perfect is " << blackP << endl;
	return 0;
}
