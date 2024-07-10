#include <iostream>
using namespace std;

class Count {
	friend void setX(Count &, int); //not member function
    public:
	Count()
		: x(0)
	{
	}

	void print() const
	{
		cout << x << endl;
	}

    private:
	int x;
};

void setX(Count &self, int x)
{
	self.x = x;
}

int main()
{
	Count c;
	c.print();
	setX(c, 100);
	c.print();
	return 0;
}
