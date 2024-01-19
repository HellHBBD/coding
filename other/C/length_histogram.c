#include <stdio.h>
#include <stdlib.h>
#define isalpha(c) (((c) >= 'a' && (c) <= 'z') || ((c) >= 'A' && (c) <= 'Z'))

char *getfile()
{
		char *result = 0, c;
		int charCount = 0;
		while ((c = getchar()) != EOF) {
				result = realloc(result, (charCount + 1) * sizeof(char));
				result[charCount] = c;
				charCount++;
		}
		result = realloc(result, (charCount + 1) * sizeof(char));
		result[charCount] = '\0';
		return result;
}

int main()
{
		char *string = getfile();
		int lengthMax = 0, length = 0;
		int *lengthCount = 0;
		int *alphabetCount = 0;
		char *word = string, asciiMax = '\0';

		while (*word != '\0') {
				if (isalpha(*word)) {
						length++;
						word++;
				} else {
						if (length > lengthMax) {
								lengthCount = realloc(lengthCount, length * sizeof(int));
								for (int i = lengthMax; i < length; i++)
										lengthCount[i] = 0;
								lengthMax = length;
						}
						if (length != 0)
								lengthCount[length - 1]++;
						length = 0;
						word++;
				}
				if (*word > asciiMax) {
						alphabetCount = realloc(alphabetCount, ((int)*word) * sizeof(int));
						for (char i = asciiMax; i < *word; i++)
								alphabetCount[i] = 0;
						asciiMax = *word;
				}
				alphabetCount[*word]++;
		}

		int *temp = malloc(lengthMax * sizeof(int));
		int max = 0;
		for (int i = 0; i < lengthMax; i++) { //normal list
				temp[i] = lengthCount[i];
				if (lengthCount[i] > max)
						max = lengthCount[i];
				printf("%2d: %d\n", i + 1, lengthCount[i]);
		}

		for (int i = 0; i < lengthMax; i++) {
				for (int j = 0; j < lengthCount[i]; j++) //horizontal histogram
						printf("-");
				puts("");
		}

		for (; max > 0; max--) { //vertical histogram
				for (int i = 0; i < lengthMax; i++) {
						if (temp[i] == max) {
								printf("|");
								temp[i]--;
						} else {
								printf(" ");
						}
						printf(" ");
				}
				puts("");
		}

		for (char i = 0; i < asciiMax; i++) {
				if (alphabetCount[i] == 0)
						continue;
				printf("'%c': %d\n", i, alphabetCount[i]);
		}

		free(alphabetCount);
		free(temp);
		free(lengthCount);
		free(string);
		return 0;
}
