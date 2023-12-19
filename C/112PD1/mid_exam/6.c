#include <stdio.h>

int A(int);
int B(int);

int main() {
	printf("%d\n", B(20));
	return 0;
}

int A(int n) {
	return (n == 0) ? 0 : n + B(n - 1);
}

int B(int n) {
	return (n == 0) ? 0 : n + A(n / 2);
}
