#include <iostream>

using namespace std;

int main()
{
	int A[] = { 80, 2, 22, 4, 0, 8, 100, 20, 1, 50 };

	for (int i = 1; i < 10; i++) {
		int j = i - 1;
		while (j >= 0) {
			if (A[j + 1] < A[j]) {
				A[j + 1] = A[j + 1] ^ A[j];
				A[j] = A[j + 1] ^ A[j];
				A[j + 1] = A[j + 1] ^ A[j];
				j--;
			} else {
				break;
			}
		}
	}
	for (int i = 0; i < 10; i++)
		cout << A[i] << ",";
	cout << "end";
	return 0;
}
