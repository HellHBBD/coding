#include <stdio.h>
#define N 3

int innerProduct(int rowA[N], int (*p)[N]) {
	int result = 0;
	for (int i = 0; i < N; i++)
		result += (rowA[i] * **(p + i));
	return result;
}

void matrixProduct(int A[N][N], int b[N][N], int result[N][N]) {
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			result[i][j] = innerProduct(A[i], (int(*)[N]) & b[0][j]);
}

int main() {
	int a[N][N] = {{1, 2, 3},
				   {4, 5, 6},
				   {7, 8, 9}};
	int b[N][N] = {{2, 3, 5},
				   {7, 1, 3},
				   {7, 1, 3}};
	int c[N][N];
	matrixProduct(a, b, c);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)
			printf("%3d ", c[i][j]);
		puts("");
	}
	return 0;
}
