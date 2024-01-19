#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char **argv)
{
		srand(time(0));
		int n = atoi(argv[1]);
		int min = atoi(argv[2]);
		int max = atoi(argv[3]);
		for (int i = 0; i < n; i++)
				printf("%d ", rand() % (max - min + 1) + min);
		puts("");
		return 0;
}
