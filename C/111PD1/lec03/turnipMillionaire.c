#include <stdio.h>

float hf(float x, float h)
{
	return 0.9 * x + 0.1 * h - 51;
}

float y(float h)
{
	return -0.98 * h + 153;
}

int main()
{
	float x, h = 0;
	scanf("%f", &x);
	for (int i = 0; i < 5; i++) {
		h = hf(x, h);
		x = y(h);
		printf("%.1f ", x);
	}
	return 0;
}
