#include <stdio.h>
#define d1 (n[1] - n[0])
#define d2 (n[2] - n[1])
#define d3 (n[3] - n[2])
#define r1 (n[1] / n[0])
#define r2 (n[2] / n[1])
#define r3 (n[3] / n[2])

int main()
{
	int t, n[4], ans;
	scanf("%d", &t);
	while (t--) {
		for (int i = 0; i < 4; i++)
			scanf("%d", &n[i]);
		if (d1 == d2 && d2 == d3)
			ans = n[3] + d3;
		if (r1 == r2 && r2 == r3)
			ans = n[3] * r3;
		printf("%d %d %d %d %d\n", n[0], n[1], n[2], n[3], ans);
	}
	return 0;
}
