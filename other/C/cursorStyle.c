#include <stdio.h>
#include <unistd.h>
#define SIZE 8

#define SET(x, y) printf("\033[%d;%dH", x, y)
		/*  y--> */
		/* x     */
		/* |     */
		/* v     */

int main()
{
		for (int i = 0; i < 110; i++) {
				printf("\033[0m");
				printf("\033[%dm%3d ", i, i);
				if ((i + 1) % 10 == 0)
						puts("");
		}
		printf("\033[0m");
		const char *styleTable[] = {
		  "Default",
		  "Bar (blinking)",
		  "Block (blinking)",
		  "Block (steady)",
		  "Underline (blinking)",
		  "Underline (steady)",
		  "Bar (blinking)",
		  "Bar (steady)"};

		for (int i = 0; i < 8; i++) {
				printf("%d %s\n\e[%d q", i, styleTable[i], i);
				sleep(2);
				puts("");
		}
		return 0;
}
