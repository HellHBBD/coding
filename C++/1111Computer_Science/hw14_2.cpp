#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	int n;
	cout << "Please enter a number n to build a matrix A: ";
	cin >> n;
	int matrixA[n][n];

	for (int i = 0; i < n; i++) { //print original matrix
		for (int j = 0; j < n; j++) {
			matrixA[i][j] = n * i + j + 1;
			cout << setw(4) << matrixA[i][j] << " ";
		}
		cout << endl;
	}

	cout << "Matrix A multiplied by itself:" << endl;
	int matrixSquare[n][n], unitSum; //multiply operation
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			unitSum = 0;
			for (int k = 0; k < n; k++) {
				unitSum += (matrixA[i][k] * matrixA[k][j]);
			}
			matrixSquare[i][j] = unitSum;
		}
	}

	for (int i = 0; i < n; i++) { //print multiplied matrix
		for (int j = 0; j < n; j++) {
			cout << setw(4) << matrixSquare[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}
