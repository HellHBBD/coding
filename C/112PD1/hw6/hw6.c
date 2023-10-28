#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

void Homework6_1(){
	int N;
	scanf("%d",&N);
	int array[N];
	for (int i = 0;i < N;i++)
		scanf("%d",&array[i]);
	printf("%d",array[N-1]);
	for (int i = N-2;i >= 0;i--)
		printf(" %d",array[i]);
	puts("");
}

int main(){
	int option;
	scanf("%d",&option);
	if (option == 1)
		Homework6_1();
	/* else if (option == 2) */
	/* 	Homework6_2(); */
	/* else if (option == 3) */
	/* 	Homework6_3(); */
	/* else if (option == 4) */
	/* 	Homework6_4(); */
	return 0;
}
