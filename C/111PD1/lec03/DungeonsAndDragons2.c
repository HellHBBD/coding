#include <stdio.h>

int diff(int a, int b)
{
		if (a > b)
				return a - b;
		return b - a;
}

int main()
{
		int player = 100, dragon = 100, d1, d2, d3, d4, d5, d6;
		while (1) {
				scanf("%d %d %d %d %d %d", &d1, &d2, &d3, &d4, &d5, &d6);
				if ((d1 + d2 + d3) % 2 != 0) { //player attack
						if (d6 > d5 && d5 > d4)
								dragon -= 25;
						else if ((d4 % 2 == d5 % 2) || (d5 % 2 == d6 % 2))
								dragon -= 5;
				} else { //dragon attack
						if (diff(d4, d5) > d6)
								player -= 15;
						else if (d4 + d5 != d6)
								player -= 5;
				}
				if (player <= 0) {
						printf("Dragon wins");
						break;
				}
				if (dragon <= 0) {
						printf("Player wins");
						break;
				}
		}
		return 0;
}
