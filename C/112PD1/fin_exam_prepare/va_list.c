#include <math.h>
#include <stdarg.h>
#include <stdio.h>

/* double poly(int num, ...) { */
/* 	va_list args; */
/* 	double sum = 0; */
/* 	int t = num; */
/* 	num++; */
/* 	va_start(args, num + 1); */
/* 	double X = va_arg(args, double); */
/* 	for (int i = 0; i < num; i++) */
/* 		sum += va_arg(args, double) * pow(X, t--); */
/* 	return sum; */
/* } */

double poly(int num, ...) {
	va_list args;
	double total = 0;
	va_start(args, num);
	double X = va_arg(args, double);
	for (int degree = num - 2; degree >= 0; degree--) {
		double co = va_arg(args, double);
		double a = co * pow(X, degree);
		total += a;
	}
	return total;
}

int main() {
	/* printf("%lf\n", poly(5, 3.2, 3.0, 2.0, -5.0, 0.0, 7.0, -6.0)); */
	printf("%lf\n", poly(7, 3.2, 3.0, 2.0, -5.0, 0.0, 7.0, -6.0));
	return 0;
}
