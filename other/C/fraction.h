#ifndef FRACTION_H
#define FRACTION_H

#include <stdio.h>
#define ABS(n) ((n) >= 0 ? (n) : (-n))

struct Fraction {
	int numerator;
	unsigned denominator;
};

struct Fraction fracture(int, int);
struct Fraction simplify(struct Fraction);
int GCD(int, int);
void print(struct Fraction);
struct Fraction add(struct Fraction, struct Fraction);
struct Fraction subtract(struct Fraction, struct Fraction);
struct Fraction multiply(struct Fraction, struct Fraction);
struct Fraction divide(struct Fraction, struct Fraction);

struct Fraction fracture(int n, int d)
{
	int gcd = GCD(ABS(n), ABS(d));
	n = (d >= 0 ? 1 : -1) * n / gcd;
	d = ABS(d / gcd);
	return (struct Fraction){ .numerator = n, .denominator = d };
}

struct Fraction simplify(struct Fraction fraction)
{
	return fracture(fraction.numerator, fraction.denominator);
}

int GCD(int a, int b)
{
	if (a % b == 0)
		return b;
	else
		return GCD(b, a % b);
}

void print(struct Fraction fraction)
{
	if (fraction.denominator != 1) {
		printf("%d/%d", fraction.numerator, fraction.denominator);
	} else {
		printf("%d", fraction.numerator);
	}
}

struct Fraction add(struct Fraction a, struct Fraction b)
{
	return fracture(a.numerator * b.denominator +
				b.numerator * a.denominator,
			a.denominator * b.denominator);
}

struct Fraction subtract(struct Fraction a, struct Fraction b)
{
	return fracture(a.numerator * b.denominator -
				b.numerator * a.denominator,
			a.denominator * b.denominator);
}

struct Fraction multiply(struct Fraction a, struct Fraction b)
{
	return fracture(a.numerator * b.numerator,
			a.denominator * b.denominator);
}

struct Fraction divide(struct Fraction a, struct Fraction b)
{
	return fracture(a.numerator * b.denominator,
			a.denominator * b.numerator);
}

#endif
