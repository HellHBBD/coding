#include <stdio.h>

int main()
{
	char c = getchar();
	getchar();
	unsigned address = 0;
	int byte[4] = { 0 };
	if (c == 'a') {
		scanf("%d.%d.%d.%d", &byte[0], &byte[1], &byte[2], &byte[3]);
		/* address |= (byte[0] << 24); */
		/* address |= (byte[1] << 16); */
		/* address |= (byte[2] << 8); */
		/* address |= byte[3]; */
		for (int i = 0; i < 4; i++)
			address |= (byte[i] << (24 - 8 * i));
		for (int i = 0; i < 32; i++)
			if (address & (1 << (31 - i)))
				putchar('1');
			else
				putchar('0');
		puts("");
	}

	if (c == 'b') {
		for (int i = 0; i < 32; i++) {
			char bit = getchar();
			if (bit - '0')
				address |= (1 << (31 - i));
		}
		/** for (int i = 0; i < 4; i++) */
		/** 	byte[i] = (address >> (24 - 8 * i)) & 255; */
		for (int i = 0; i < 4; i++) {
			byte[3 - i] = address & 255;
			address >>= 8;
		}
		printf("%d.%d.%d.%d\n", byte[0], byte[1], byte[2], byte[3]);
	}
	return 0;
}
