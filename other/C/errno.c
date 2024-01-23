#include <errno.h>
#include <stdio.h>
#include <string.h>

#define NUM 135

extern int errno;

int main()
{
		int *p;
		*p = 0;
		printf("%s\n", strerror(errno));
		return 0;
}
