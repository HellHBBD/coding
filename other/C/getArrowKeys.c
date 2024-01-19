#include <stdio.h>
#include <string.h>
#define KEY_UP 65
#define KEY_DOWN 66
#define KEY_RIGHT 67
#define KEY_LEFT 68
#define ESC 0

int main()
{
		/* for (int i = 0; i < 4; i++) { */
		while (1) {
				char s[8] = {0};
				scanf("%s", s);

				/* for (int j = 0; j < strlen(s); j++) */
				/* 	printf("%d ", s[j]); */
				/* puts(""); */

				switch (s[2]) {
				case KEY_UP:
						puts("up");
						break;
				case KEY_DOWN:
						puts("down");
						break;
				case KEY_LEFT:
						puts("left");
						break;
				case KEY_RIGHT:
						puts("right");
						break;
				case ESC:
						puts("esc");
						goto exit;
				}
		}
exit:
		return 0;
}
