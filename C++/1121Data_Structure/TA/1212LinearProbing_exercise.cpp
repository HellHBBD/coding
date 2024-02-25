#include <cstdlib>
#include <iostream>
using namespace std;

void HashFunction(int *data, int *key)
{
	for (int i = 0; i < 9; i++) {
		//???   // H(x) = x mod 9
		key[i] = data[i] % 9;
	}
}

void LinearProbing(int *data, int *key, int *table)
{
	int index = -1;
	for (int i = 0; i < 9; i++) {
		index = key[i];
		while (true) {
			if (table[index] == -1) { //if table[index] is empty
				table[index] = data[i];
				break;
			} else { //if table[index] is full
				//???   //find next one bucket
				//???   //if index >9, then back to index 0
				index = (index + 1) % 9;
			}
		}
	}
}

int main()
{
	int data[9] = { 16, 4, 1, 10, 9, 8, 11, 25, 33 };
	int key[9] = { -1, -1, -1, -1, -1, -1, -1, -1, -1 }; //-1 means empty
	int table[9] = { -1, -1, -1, -1, -1, -1, -1, -1, -1 }; //-1 means empty

	cout << "\n\noriginal data:\n";
	for (int i = 0; i < 9; i++)
		cout << data[i] << ' ';
	cout << "\n\n";

	HashFunction(data, key);
	cout << "\n\nkey set:\n";
	for (int i = 0; i < 9; i++)
		cout << key[i] << ' ';
	cout << "\n\n";

	LinearProbing(data, key, table);
	cout << "\n\nHash table:\n";
	for (int i = 0; i < 9; ++i)
		cout << table[i] << ' ';
	cout << "\n\n";

	return 0;
}
