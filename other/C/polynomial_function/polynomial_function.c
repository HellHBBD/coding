#include <stdio.h>

int main()
{
	int degree;
	scanf("%d\n", &degree);
	printf("%d\n", degree);
	double coefficientList[degree + 1];
	for (int i = 0; i < degree + 1; i++) {
		scanf("%lf", &coefficientList[i]);
		getchar();
		printf("%lf ", coefficientList[i]);
	}
	system("pause");
	return 0;
}
