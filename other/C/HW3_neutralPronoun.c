#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *strConcat(char *str1, char *str2)
{
		char *result = malloc(strlen(str1) + strlen(str2) + 1);
		char *r = result, *p1 = str1, *p2 = str2;
		for (int i = 0; i < strlen(str1); i++) {
				*r = *p1;
				r++;
				p1++;
		}
		for (int i = 0; i < strlen(str2); i++) {
				*r = *p2;
				r++;
				p2++;
		}
		*r = '\0';
		return result;
}

char *charConcat(char *str1, char str2)
{
		char *result = malloc(strlen(str1) + 2);
		char *r = result, *p1 = str1;
		for (int i = 0; i < strlen(str1); i++) {
				*r = *p1;
				r++;
				p1++;
		}
		*(r++) = str2;
		*r = '\0';
		return result;
}

void clear(char *str)
{
		for (int i = 0; i < strlen(str); i++)
				*(str++) = '\0';
}

int main()
{
		char c, *result, *buffer, she[] = "she or ", her[] = "her or ";
		c = getchar();
		buffer = charConcat(buffer, c);
		printf("%s", buffer);
		clear(buffer);
		//while (1){
		//	c = getchar();
		//	if (c == '\0')
		//		break;
		//	if (c >= 'a' && c <= 'z'){
		//		buffer = charConcat(buffer,c);
		//	}
		//}
		return 0;
}
