#include <iostream>
using namespace std;

class People {
	public:
		People(int);
		People();
		People(const People &);
		~People();
		int getAge() const;

	private:
		int Age;
};

int main() {
	People p1(18), p2;
	cout << "p1:" << p1.getAge() << endl;
	p2 = p1;
	cout << "p2:" << p2.getAge() << endl;
	People p3 = p1;
	cout << "p3:" << p3.getAge() << endl;
	People p4(p1);
	cout << "p4:" << p4.getAge() << endl;
	return 0;
}

People::People(int age) : //construct with parameter
						  Age(age) {
	cout << "construct" << endl;
}

People::People() { //construct with no parameter
	Age = 0;
	cout << "construct" << endl;
}

People::People(const People &p) {
	cout << "copy construct" << endl;
	Age = p.Age;
}

People::~People() {
	cout << "destruct" << endl;
}

int People::getAge() const {
	return Age;
}
