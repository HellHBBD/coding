#include <iostream>
#include <iomanip>
#include <ctime>
#include <cmath>
using namespace std;

double approxPIsquared_iter(int seriesNumber)
{
	float total = 0.0;
	for (int i = 1; i <= seriesNumber; i++) {
		total += 8 / pow(2 * i - 1, 2);
	}
	return total;
}

double approxPIsquared_recur(int seriesNumber)
{
	if (seriesNumber == 1)
		return 8;
	else
		return 8 / pow(2 * seriesNumber - 1, 2) +
		       approxPIsquared_recur(seriesNumber - 1);
}

int main()
{
	int seriesNumber, iterTime, recurTime;
	clock_t start, end;
	double secs;

	cout << "How many number are in the series?:";
	cin >> seriesNumber;

	start = clock();
	cout << setprecision(12) << "(iterative) By including " << seriesNumber
	     << " numbers in the series, the approximated Pi is "
	     << pow(approxPIsquared_iter(seriesNumber), 0.5) << endl;
	end = clock();
	secs = ((double)(end - start)) / CLOCKS_PER_SEC;
	cout << "It takes " << secs << " secs" << endl;

	start = clock();
	cout << setprecision(12) << "(recursive) By including " << seriesNumber
	     << " numbers in the series, the approximated Pi is "
	     << pow(approxPIsquared_recur(seriesNumber), 0.5) << endl;
	end = clock();
	secs = ((double)(end - start)) / CLOCKS_PER_SEC;
	cout << "It takes " << secs << " secs" << endl;

	return 0;
}
