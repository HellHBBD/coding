#include <iostream>
using namespace std;

int main() {
	int word = 0;
	int letter[26] = {0};

	enum Status { w,
				  p };

	Status status;
	string line;
	getline(cin, line);
	char *c = &line[0];
	while (1) {
		if (*c == '\0') {
			if (status == w)
				word++;
			break;
		}
		if (*c == ' ' && status == w) {
			word++;
			status = p;
			c++;
			continue;
		}
		if (*c == ',' && status == w) {
			word++;
			status = p;
			c++;
			continue;
		}
		if (*c == '.' && status == w) {
			word++;
			status = p;
			c++;
			continue;
		}
		if (*c <= 'Z') {
			letter[*c - 'A']++;
			status = w;
		} else {
			letter[*c - 'a']++;
			status = w;
		}
		c++;
	}
	cout << word << " words" << endl;
	for (int i = 0; i < 26; i++)
		if (letter[i] != 0)
			cout << letter[i] << " " << (char)('a' + i) << endl;
	return 0;
}
