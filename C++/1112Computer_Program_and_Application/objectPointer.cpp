#include <iostream>
using namespace std;

class Count
{
		public:
		void setX(int);
		void print();

		private:
		int x;
};

int main()
{
		Count counter;
		Count *counterPtr = &counter;
		Count &counterRef = counter;

		counter.setX(1);
		cout << "set counter to 1 : ";
		counter.print();

		counterRef.setX(2);
		cout << "set counter reference to 2 : ";
		counterRef.print();

		counterPtr->setX(3); //(*counterPtr).setX(3);
		cout << "set counter pointer to 3 : ";
		counterPtr->print();
		return 0;
}

void Count::setX(int value)
{
		x = value;
}

void Count::print()
{
		cout << x << endl;
}
