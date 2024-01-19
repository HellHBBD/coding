#include <stdio.h>

int main()
{
		int n, k1, k2, k3;
		scanf("%d %d %d %d", &n, &k1, &k2, &k3);
		printf("%d", n * (k1 + k2 + k3 - (k1 / 3) - (k2 / 3) - (k3 / 3)));
		return 0;
}
