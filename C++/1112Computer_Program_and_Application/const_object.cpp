#include <iostream>
using namespace std;

class Number
{
		public:
		Number();
		void print();
		void printc() const;

		private:
		int x;
};

int main()
{
		Number a;
		const Number b;
		a.print();
		//b.print(); const object must use const function
		cout << endl;
		b.printc();
		return 0;
}

Number::Number()
{
		x = 0;
}

void Number::print()
{
		cout << x;
}

void Number::printc() const
{
		cout << x;
}
