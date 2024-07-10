#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

void printMatrix(int matrix[], int length)
{
	for (int i = 0; i < pow(length, 2); i++) {
		cout << setw(4) << matrix[i] << " ";
		if ((i + 1) % length == 0)
			cout << endl;
	}
}

void matrixMutiply(int matrix[], int length)
{
	int matrixA[length][length];
	for (int i = 0; i < pow(length, 2); i++) {
		matrixA[i / length][i % length] = matrix[i];
	}
	int unitSum;
	for (int i = 0; i < length; i++) {
		for (int j = 0; j < length; j++) {
			unitSum = 0;
			for (int k = 0; k < length; k++) {
				unitSum += (matrixA[i][k] * matrixA[k][j]);
			}
			cout << setw(4) << unitSum << " ";
		}
		cout << endl;
	}
}

int main()
{
	int n;
	cout << "Please enter a number n to build a matrix A: ";
	cin >> n;
	int nSquare = pow(n, 2);
	int matrixA[nSquare];

	for (int i = 0; i < pow(n, 2); i++) { //generate original matrix
		matrixA[i] = i + 1;
	}
	printMatrix(matrixA, n); //print original matrix

	cout << "Matrix A multiplied by itself:" << endl;
	matrixMutiply(matrixA, n); //multiply and print matrix
	return 0;
}
