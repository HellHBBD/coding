#include <stdio.h>
#define N 100

int read_line(char str[], int n)
{
		int ch, i = 0;

		while ((ch = getchar()) != '\n')
				if (i < n)
						str[i++] = ch;
		str[i] = '\0'; /* terminates string */
		return i;	   /* number of characters stored */
}

int match(const char *s1, const char *s2)
{
		if (s1[1] == '\0' || s2[1] == '\0')
				return s1[0] == s2[0];
		if (s1[0] == s2[0])
				return match(s1 + 1, s2 + 1);
		else
				return 0;
}

int CutString(char **substr, char *str, const char *cut)
{
		int index = 0;
		substr[0] = str;
		for (char *s = str; *s; s++) {
				if (match(s, cut)) {
						for (int i = 0; cut[i]; i++)
								*s++ = '\0';
						index++;
						substr[index] = s;
				}
		}
		return ++index;
}

int main()
{
		char str[N];
		char cut[N];
		char *substr[N];

		read_line(str, N);
		read_line(cut, N);

		int n = CutString(substr, str, cut);

		for (int i = 0; i < n; i++)
				printf("%s\n", substr[i]);

		return 0;
}
