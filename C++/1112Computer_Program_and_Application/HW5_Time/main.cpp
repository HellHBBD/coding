#include "Time.hpp"
#include <iostream>
using namespace std;

int main()
{
	Time t(0, 0, 59);
	t.printStandard('\n');
	t.tick();
	t.printStandard('\n');
	cout << endl;

	t.setTime(11, 59, 59);
	t.printStandard('\n');
	t.tick();
	t.printStandard('\n');
	cout << endl;

	t.setTime(23, 59, 59);
	t.printStandard('\n');
	t.tick();
	t.printStandard('\n');
	cout << endl;
	return 0;
}
