#include <bits/stdc++.h>
using namespace std;

long int factorial(int n)
{
	if (n == 1)
		return 1;
	else
		return n * factorial(n - 1);
}

int main()
{
	int n, m;
	cout << "Please input n and m for C(n,m):";
	cin >> n >> m;
	cout << "C(" << n << ", " << m
	     << ")=" << factorial(n) / (factorial(m) * factorial(n - m));
	return 0;
}
