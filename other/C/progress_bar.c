#include <stdio.h>
#define MAX 9999999

void progress_bar(unsigned long long i, unsigned long long max)
{
		if (i == max)
				puts("[====================]100%");
		int percent = i * 100 / MAX;
		printf("\e[?25l[");
		for (int j = 0; j < 20; j++)
				if (j < percent / 5)
						printf("=");
				else
						printf(" ");
		printf("]");
		printf("%3d\%\r\e[?25h", percent);
}

int main()
{
		for (long int i = 0; i < MAX; i++)
				progress_bar(i + 1, MAX);
		return 0;
}
