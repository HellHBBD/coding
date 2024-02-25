#include <stdio.h>

int answer[8], used = 0;

void permutation(int cnt)
{
	/* printf("%d call\n",cnt); */
	if (cnt == 8) {
		for (int i = 0; i < 8; i++)
			printf("%d ", answer[i]);
		puts("");
		/* printf("%d return\n",cnt); */
		return;
	}
	for (int i = 1; i <= 8; i++) {
		if (~used & (1 << (i - 1))) {
			answer[cnt] = i;
			used |= (1 << (i - 1));
			permutation(cnt + 1);
			used &= ~(1 << (i - 1));
		}
	}
}

int main()
{
	permutation(0);
	return 0;
}
