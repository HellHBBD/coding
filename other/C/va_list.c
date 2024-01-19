#include <math.h>
#include <stdarg.h>
#include <stdio.h>

double average(int length, ...)
{
		int total = 0;
		va_list args;
		va_start(args, length);
		for (int i = 0; i < length; i++) {
				int arg = va_arg(args, int);
				total += arg;
		}
		va_end(args);
		return (double)total / length;
}

double poly(int degree, ...)
{
		double total = 0;
		va_list args;
		va_start(args, degree);
		double x = va_arg(args, double);
		for (int i = degree; i >= 0; i--) {
				double arg = va_arg(args, double);
				total += (arg * pow(x, degree));
		}
		va_end(args);
		return total;
}

int main()
{
		printf("%lf\n", poly(7, 0, 3, 2, -5, 0, 7, -6));
		return 0;
}
