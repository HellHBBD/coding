#include <iostream>
using namespace std;

class total {
	public:
		static int score;

		int add(int *a, int *b) {
			*a = *b + 5;
			*b = *a + 5;
			score = score + *a + *b;
		}

		int sub(int i, int j) {
			i = j - 10;
			j = i - 10;
			score = score + i + j;
		}
};

int total::score = 0;

int main() {
	total s1, s2;
	int x = 10, y = 20;
	s1.add(&x, &y);
	s2.sub(x, y);
	cout << x << endl;
	cout << y << endl;
	cout << s1.score << endl;
	cout << s2.score << endl;
	return 0;
}
