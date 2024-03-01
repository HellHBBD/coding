#include <stdio.h>
#include "progress_bar.h"
#define MAX 9999999

int main()
{
	for (long int i = 0; i < MAX; i++)
		progress_bar(i + 1, MAX);
	return 0;
}
