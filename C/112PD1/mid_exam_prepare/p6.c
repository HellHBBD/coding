#include <stdio.h>

int main()
{
		int x = 0; //a
		if (x = 1)
				printf("%d\n", x);

		x = (3 < 2) ? 3 : (2 > 1) ? 2 //b
								  : 1;
		printf("%d\n", x);

		x = 1; //c
		printf("%d\n", x);
		{
				int x = 2, y = 3;
				printf("%d %d\n", x, y);
		}
		/* printf("%d %d\n", x, y); */

		//d
		/* for (x = 2;x = 1;x = 0) */
		/* 	printf("%d\n", x); */

		//e
		/* int i = 0; */
		while (i < 10) {
				i++;
				break;
		}
		printf("%d\n", i);
		return 0;
}
