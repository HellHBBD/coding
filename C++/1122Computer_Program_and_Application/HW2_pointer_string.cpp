#include <iostream>
using std::cout;
using std::endl;

void analyzeText(const char text[])
{
	int word = 0;
	int sentence = 0;
	const char table[] = "aeiou";
	int vowel[5] = { 0 };
	for (const char *c = text; *c; c++) {
		switch (*c) {
		case ' ':
			word++;
			break;
		case '.':
		case '?':
		case '!':
			sentence++;
			break;
		case 'A':
		case 'a':
			vowel[0]++;
			break;
		case 'E':
		case 'e':
			vowel[1]++;
			break;
		case 'I':
		case 'i':
			vowel[2]++;
			break;
		case 'O':
		case 'o':
			vowel[3]++;
			break;
		case 'U':
		case 'u':
			vowel[4]++;
		}
	}
	word++;
	cout << sentence << " sentences" << endl;
	cout << "Average " << word / sentence << " words per sentence" << endl;
	for (int i = 0; i < 5; i++) {
		if (vowel[i] != 0) {
			cout << vowel[i] << " " << table[i] << endl;
		}
	}
}

int main()
{
	const char paragraph[] =
		"Hello, world! I am learning C++. Isn't it exciting?";
	analyzeText(paragraph);
	return 0;
}
