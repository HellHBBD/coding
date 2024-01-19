#include <iostream>
using namespace std;

class Rational
{
		public:
		Rational(int = 0, int = 1);
		void set(int = 0, int = 1);
		void add(Rational, Rational);
		void subtract(Rational, Rational);
		void multiply(Rational, Rational);
		void divide(Rational, Rational);
		void printFraction(char = '\0');
		void printFloat(char = '\0');
		int getNumerator();
		int getDenominator();

		private:
		int numerator, denominator;
		void simplify();
};

int main()
{
		Rational a(3, 0), b(2, 4), result;

		a.printFraction();
		cout << " + ";
		b.printFraction();
		cout << " = ";
		result.add(a, b);
		result.printFraction();
		cout << " = ";
		result.printFloat('\n');

		a.set(-4, -6);
		a.printFraction();
		cout << " - ";
		b.printFraction();
		cout << " = ";
		result.subtract(a, b);
		result.printFraction();
		cout << " = ";
		result.printFloat('\n');

		b.set(24, -10);
		a.printFraction();
		cout << " * ";
		b.printFraction();
		cout << " = ";
		result.multiply(a, b);
		result.printFraction();
		cout << " = ";
		result.printFloat('\n');

		b.printFraction();
		cout << " / ";
		a.printFraction();
		cout << " = ";
		result.divide(b, a);
		result.printFraction();
		cout << " = ";
		result.printFloat('\n');
		return 0;
}

Rational::Rational(int a, int b)
{
		set(a, b);
}

void Rational::set(int a, int b)
{
		numerator = a;
		if (b == 0)
				denominator = 1;
		else
				denominator = b;
		simplify();
}

void Rational::add(Rational a, Rational b)
{
		numerator = a.numerator * b.denominator + b.numerator * a.denominator;
		denominator = a.denominator * b.denominator;
		simplify();
}

void Rational::subtract(Rational a, Rational b)
{
		numerator = a.numerator * b.denominator - b.numerator * a.denominator;
		denominator = a.denominator * b.denominator;
		simplify();
}

void Rational::multiply(Rational a, Rational b)
{
		numerator = a.numerator * b.numerator;
		denominator = a.denominator * b.denominator;
		simplify();
}

void Rational::divide(Rational a, Rational b)
{
		numerator = a.numerator * b.denominator;
		denominator = a.denominator * b.numerator;
		simplify();
}

void Rational::printFraction(char display)
{
		cout << numerator << "/" << denominator << display;
}

void Rational::printFloat(char display)
{
		cout << (float)numerator / denominator << display;
}

int Rational::getNumerator()
{
		return numerator;
}

int Rational::getDenominator()
{
		return denominator;
}

void Rational::simplify()
{
		int flag = (numerator * denominator > 0) * 2 - 1;
		numerator = (numerator > 0) ? numerator : -numerator;
		denominator = (denominator > 0) ? denominator : -denominator;
		int min = (numerator > denominator) ? denominator : numerator;
		int factor = 1;
		for (int i = min; i > 0; i--) {
				if (numerator % i == 0 && denominator % i == 0) {
						factor = i;
						break;
				}
		}
		numerator = numerator / factor * flag;
		denominator = denominator / factor;
}
