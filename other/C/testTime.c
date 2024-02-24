#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

char *concat(char *filename)
{
	char *result = malloc(sizeof(char) * (strlen(filename) + 3));
	strcpy(result, "./");
	strcat(result, filename);
	return result;
}

int main(int argc, char **argv)
{
	char *msg = concat(argv[1]);
	clock_t start_clk = clock();
	system(msg);
	printf("Processor time used by program: %Lg sec.\n",
	       (clock() - start_clk) / (long double)CLOCKS_PER_SEC);
	free(msg);
	return 0;
}
