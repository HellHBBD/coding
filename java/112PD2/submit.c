#include <stdio.h>
#include <stdlib.h>

char *getMsg(char *arg){
}

int main(int argc, char **argv)
{
	if (argc < 2) {
		fputs("no specified directory", stderr);
		return -1;
	}
	char msg[100] = { 0 };
	sprintf(msg, "scp -P 32024 -r hw%s/*.java H34111122@140.116.246.208:~/hw%s/", argv[1], argv[1]);
	system(msg);
	return 0;
}
