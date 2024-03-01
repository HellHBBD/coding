#include <stdio.h>
#define n 4

void range(int I[n][2], int v, int *R[n])
{
	for (int i = 0; i < n; i++)
		if (v >= I[i][0] && v <= I[i][1])
			R[i] = I[i];
}

int main()
{
	int I[n][2] = { { 3, 19 }, { 11, 33 }, { 18, 80 }, { 80, 100 } }, *R[n] = { 0 };
	range(I, 18, R);
	for (int i = 0; i < n; i++) {
		if (R[i] == 0)
			continue;
		printf("%2d %2d\n", R[i][0], R[i][1]);
	}
	return 0;
}
