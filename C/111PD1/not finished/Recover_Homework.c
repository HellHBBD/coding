#include <ctype.h>
#include <stdio.h>
#include <string.h>

#define MAX_LEN 4096

void recovery(char *result)
{
	char *word, homework[MAX_LEN + 1];
	int charCount = 0, length = strlen(result) - 1;
	for (int i = 0; i < length; i++)
		homework[i] = result[i];
	homework[length] = '\0';
	word = strtok(homework, " ");
	while (1) {
		if (word == NULL) {
			result[charCount] = '\0';
			break;
		}

		typedef enum { true = 1, false = 0 } bool;

		bool cat = false;
		for (int i = 0; i < strlen(word); i++) {
			char c = word[i];
			if (isalpha(c))
				continue;
			else if ((c == ',' || c == '.' || c == '?' ||
				  c == '!')) {
				if (i == 0)
					cat = true;
				else if (i == (strlen(word) - 1))
					continue;
				else
					cat = true;
			} else {
				cat = true;
			}
		}
		if (cat) {
			word = strtok(NULL, " ");
			continue;
		}
		for (int i = 0; i < strlen(word); i++) {
			result[charCount] = word[i];
			charCount++;
		}
		result[charCount] = ' ';
		charCount++;
		word = strtok(NULL, " ");
	}
}

int main()
{
	char homework[MAX_LEN + 1];

	// Get the homework content.
	fgets(homework, MAX_LEN, stdin);
	recovery(homework);

	// Print the recovered homework.
	fputs(homework, stdout);

	return 0;
}
