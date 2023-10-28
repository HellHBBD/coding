#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

void Homework6_1(){
	int N;
	N = rand()%195001+5000;
	printf("%d\n",N);
	int array[N];
	array[0] = rand()%(1<<28)+1;
	printf("%d",array[0]);
	for (int i = 1;i < N;i++){
		array[i] = rand()%(1<<28)+1;
		printf(" %d",array[i]);
	}
	puts("");
	printf("%d",array[N-1]);
	for (int i = N-2;i >= 0;i--)
		printf(" %d",array[i]);
}

void swap(int *a,int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

void Homework6_2(){
	int N;
	N = rand()%195001+5000;
	printf("%d\n",N);
	int array[N];
	for (int i = 0;i < N;i++)
		array[i] = i+1;
	for (int i = 0;i < rand();i++)
		swap(&array[rand()%N],&array[rand()%N]);
	printf("%d",array[0]);
	for (int i = 1;i < N-1;i++){
		printf(" %d",array[i]);
	}
	puts("");
	printf("%d",array[N-1]);
	/* bool exist[N]; */
	/* for (int i = 0;i < N-1;i++) */
	/* 	exist[array[i]-1] = true; */
	/* for (int i = 0;i < N;i++){ */
	/* 	if (!exist[i]){ */
	/* 		printf("%d",i+1); */
	/* 		break; */
	/* 	} */
	/* } */
}

void Homework6_3(){
}

void Homework6_4(){
}

int main(){
	srand(time(0));
	int option;
	scanf("%d",&option);
	if (option == 1)
		Homework6_1();
	else if (option == 2)
		Homework6_2();
	else if (option == 3)
		Homework6_3();
	else if (option == 4)
		Homework6_4();
	return 0;
}
