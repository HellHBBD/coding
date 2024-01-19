#include <stdio.h>

int main()
{
		int m, d;
		scanf("%d %d", &m, &d);
		int s = (m * 2 + d) % 3;
		switch (s) {
		case 0:
				puts("普通");
				break;
		case 1:
				puts("吉");
				break;
		case 2:
				puts("大吉");
				break;
		}
		return 0;
}
