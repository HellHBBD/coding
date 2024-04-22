#include "fraction.h"

int main()
{
	struct Fraction a =
		add(multiply(divide(fracture(-13, 1), fracture(-14, 1)),
			     fracture(10, 1)),
		    fracture(-11, 1));
	print(a);
	return 0;
}
