#include <iostream>
using namespace std;

void bubblesort(int array[][4], int n, int index)
{
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n - 1 - i; j++) {
			if (array[j][index] > array[j + 1][index]) {
				for (int k = 0; k < 4; k++) {
					array[j][k] = array[j][k] ^
						      array[j + 1][k];
					array[j + 1][k] = array[j][k] ^
							  array[j + 1][k];
					array[j][k] = array[j][k] ^
						      array[j + 1][k];
				}
			}
		}
	}
}

int main()
{
	int row[5][4] = { { 1, 44, 22, 33 },
			  { 2, 40, 60, 50 },
			  { 3, 50, 100, 75 },
			  { 4, 0, 80, 40 },
			  { 5, 24, 32, 28 } };
	bubblesort(row, 5, 3);

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 4; j++)
			cout << row[i][j] << "\t";
		cout << endl;
	}
	return 0;
}
