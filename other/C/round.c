#include <stdio.h>
#include <math.h>

double rou(double num, int degree)
{
	double t1 = num * pow(10, degree);
	double t2 = t1 + 0.5;
	return t2 / pow(10, degree);
}

int main()
{
	/* for (double a = 1.005; a < 2; a += 0.005) { */
	double a = 1.005;
	printf("%.3lf %.3lf\n", a, rou(a, 2));
	/* } */
	return 0;
}
