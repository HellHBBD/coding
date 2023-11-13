#include <iostream>
using namespace std;

class Score {
	public:
		Score(int C = 0, int E = 0, int M = 0) {
			Chinese = C;
			English = E;
			Math = M;
		}

		void getScore() {
			cout << "Chinese:" << Chinese << endl;
			cout << "English:" << English << endl;
			cout << "Math:" << Math << endl;
		}

	private:
		int Chinese, English, Math;
};

int main() {
	Score Paul(80, 70, 100);
	Score Jim(60);
	cout << "Paul's score:" << endl;
	Paul.getScore();
	cout << "\nJim's score:" << endl;
	Jim.getScore();
	return 0;
}
