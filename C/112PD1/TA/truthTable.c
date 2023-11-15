#include <stdio.h>
#define N 3

int record[N];

void truthTableGen(int n) {
	if (n == 0) {
		for (int i = 0; i < N; i++)
			printf("%d ", record[i]);
		puts("");
	} else {
		for (int i = 0; i < 2; i++) {
			record[N - n] = i;
			truthTableGen(n - 1);
		}
	}
}

int main() {
	truthTableGen(N);
	return 0;
}
