#include <stdio.h>
#include <stdlib.h>

typedef double (*F)(double, int);

double power(double x, int n) {
	if (n > 0)
		return x * power(x, n - 1);
	else if (n < 0)
		return (1 / x) * power(x, n + 1);
	else
		return 1;
}

double multiply(double x, int n) {
	return x * n;
}

double divide(double x, int n) {
	return x / n;
}

double powerpower(F function, double x, int n, int m) {
	return power(function(x, n), m);
}

int main(int argc, char **argv) {
	double x = atof(argv[1]);
	int n = atoi(argv[2]);
	int m = atoi(argv[3]);
	printf("call powerpower() with power(): %lf\n", powerpower(power, x, n, m));
	printf("call powerpower() with multiply(): %lf\n", powerpower(multiply, x, n, m));
	printf("call powerpower() with divide(): %lf\n", powerpower(divide, x, n, m));
	return 0;
}
