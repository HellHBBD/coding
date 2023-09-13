#include <iostream>
using namespace std;

class Increment{
	public:
		Increment(int = 0,int = 1);
		void addIncrement();
		void print() const;
	private:
		int count;
		const int increment;
};

int main(){
	//const int c; const variable must initialize
	return 0;
}

Increment::Increment(int c,int i):count(c),increment(i) //const member data must use initializer
{
}

void Increment::addIncrement(){
	count += increment;
}

void Increment::print() const{
	cout << "count = " << count << ", increment = " << increment << endl;
}

