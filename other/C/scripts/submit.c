#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *getMsg(char *arg)
{
	const char *str1 = "scp -P 32024 -r hw";
	const char *str2 = "/*.java H34111122@140.116.246.208:~/hw";
	char *msg = malloc(sizeof(char) *
			   (strlen(str1) + strlen(str2) + 2 * strlen(arg) + 1));
	strcpy(msg, str1);
	strcat(msg, arg);
	strcat(msg, str2);
	strcat(msg, arg);
	return msg;
}

int main(int argc, char **argv)
{
	if (argc < 2) {
		fputs("no specified directory", stderr);
		return -1;
	}
	char *msg = getMsg(argv[1]);
	system(msg);
	/* printf("%s\n", msg); */
	free(msg);
	return 0;
}
