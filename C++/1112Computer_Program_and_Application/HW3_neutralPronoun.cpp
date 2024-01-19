#include <cstring>
#include <iostream>
using namespace std;

char *strConcat(const char *str1, const char *str2)
{
		size_t len1 = strlen(str1);
		size_t len2 = strlen(str2);
		char *result = new char[len1 + len2 + 1];
		strcpy(result, str1);
		strcat(result, str2);
		return result;
}

string strConcat(string str1, string str2)
{
		int len1 = str1.length();
		int len2 = str2.length();
		string result = str1.append(str2);
		return result;
}

int main()
{
		char sentence[100], *c = sentence;
		char init, *finalStr = &init;
		char temp;
		cin.getline(sentence, sizeof(sentence));
		while (*c != '\0') {
				if (!isalpha(*(c - 1)) && *c == 'h' && *(c + 1) == 'e' && !isalpha(*(c + 2))) {
						finalStr = strConcat(finalStr, "she or he");
						c += 2;
				} else if (!isalpha(*(c - 1)) && *c == 'H' && *(c + 1) == 'e' && !isalpha(*(c + 2))) {
						finalStr = strConcat(finalStr, "She or he");
						c += 2;
				} else if (!isalpha(*(c - 1)) && *c == 'h' && *(c + 1) == 'i' && *(c + 2) == 's' && !isalpha(*(c + 3))) {
						finalStr = strConcat(finalStr, "her(s) or his");
						c += 3;
				} else if (!isalpha(*(c - 1)) && *c == 'H' && *(c + 1) == 'i' && *(c + 2) == 's' && !isalpha(*(c + 3))) {
						finalStr = strConcat(finalStr, "Her(s) or his");
						c += 3;
				} else if (!isalpha(*(c - 1)) && *c == 'h' && *(c + 1) == 'i' && *(c + 2) == 'm' && !isalpha(*(c + 3))) {
						finalStr = strConcat(finalStr, "her or him");
						c += 3;
				} else if (!isalpha(*(c - 1)) && *c == 'H' && *(c + 1) == 'i' && *(c + 2) == 'm' && !isalpha(*(c + 3))) {
						finalStr = strConcat(finalStr, "Her or him");
						c += 3;
				} else {
						temp = *c;
						finalStr = strConcat(finalStr, &temp);
						c++;
				}
		}
		cout << finalStr << endl;
		delete[] finalStr;
		return 0;
}
