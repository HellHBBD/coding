#include <iostream>
using namespace std;

int main()
{
	char c, *pc1, *pc2 = "parsimonious", Token[] = "lugubrious";
	int i = 0;
	pc1 = &Token[2];
	while (i < 10)
		cout << *(pc2 + i++);
	cout << endl << *pc1++ << endl;
	++*pc1;
	cout << *(pc1++) << endl;
	cout << *++pc1 << endl;
	cout << *pc1++ << endl;
	cout << Token + 2 << endl;
	pc2 = pc1;
	cout << (&pc1 == &pc2) << (pc1 == pc2) << (*pc1 = *pc2) << endl;
	cout << pc2 << endl;
	return 0;
}
