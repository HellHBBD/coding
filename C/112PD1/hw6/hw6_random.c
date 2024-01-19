#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define swap(a, b) ((a) ^= (b) ^= (a) ^= (b))

void Homework6_1()
{
		int N;
		N = rand() % 195001 + 5000;
		printf("%d\n", N);
		int array[N];
		array[0] = rand() % (1 << 28) + 1;
		printf("%d", array[0]);
		for (int i = 1; i < N; i++) {
				array[i] = rand() % (1 << 28) + 1;
				printf(" %d", array[i]);
		}
		puts("");
		printf("%d", array[N - 1]);
		for (int i = N - 2; i >= 0; i--)
				printf(" %d", array[i]);
}

void Homework6_2()
{
		int N;
		N = rand() % 195001 + 5000;
		printf("%d\n", N);
		int array[N];
		for (int i = 0; i < N; i++)
				array[i] = i + 1;
		for (int i = 0; i < 10; i++) {
				int index1 = rand() % N;
				int index2 = rand() % N;
				swap(array[index1], array[index2]);
		}
		printf("%d", array[0]);
		for (int i = 1; i < N - 1; i++)
				printf(" %d", array[i]);
		puts("");
		printf("%d", array[N - 1]);
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

void Homework6_3()
{
		int N;
		N = rand() % 50001 + 50000;
		printf("%d\n", N);
		int array[N];
		long brray[N];
		array[0] = rand() % 1000000000;
		printf("%d", array[0]);
		brray[0] = array[0];
		for (int i = 1; i < N; i++) {
				array[i] = rand() % 1000000000;
				printf(" %d", array[i]);
				brray[i] = brray[i - 1] + array[i];
		}
		puts("");
		int queryTime;
		queryTime = rand() % 50001 + 50000;
		printf("%d\n", queryTime);
		long result[queryTime];
		for (int i = 0; i < queryTime; i++) {
				int left = rand() % N + 1, right = rand() % N + 1;
				if (left > right)
						swap(left, right);
				printf("%d %d\n", left, right);
				long lvalue, rvalue;
				if (left == 1)
						lvalue = 0;
				else
						lvalue = brray[left - 2];
				rvalue = brray[right - 1];
				result[i] = rvalue - lvalue;
		}
		for (int i = 0; i < queryTime; i++)
				if (i == queryTime - 1)
						printf("%ld", result[i]);
				else
						printf("%ld\n", result[i]);
}

void Homework6_4()
{
		/* int m = rand()%6+5,n = rand()%6+5; */
		int m = rand() % 501 + 500, n = rand() % 501 + 500;
		printf("%d %d\n", n, m);
		int array[n][m];
		for (int i = 0; i < n; i++) {
				array[i][0] = rand() % 1000 + 1;
				printf("%d", array[i][0]);
				for (int j = 1; j < m; j++) {
						array[i][j] = rand() % 1000 + 1;
						printf(" %d", array[i][j]);
				}
				puts("");
		}
		/* int swapList[5][4]; */
		/* for (int i = 0;i < 5;i++){ */
		/* 	scanf("%d%d%d%d",&swapList[i][0],&swapList[i][1],&swapList[i][2],&swapList[i][3]); */
		/* } */
		for (int i = 0; i < 5; i++) {
				int x1 = rand() % n + 1, y1 = rand() % m + 1, x2 = rand() % n + 1, y2 = rand() % m + 1;
				printf("%d %d %d %d\n", x1, y1, x2, y2);
				swap(array[x1 - 1][y1 - 1], array[x2 - 1][y2 - 1]);
		}
		printf("%d", array[0][0]);
		for (int j = 1; j < m; j++)
				printf(" %d", array[0][j]);
		for (int i = 1; i < n; i++) {
				puts("");
				printf("%d", array[i][0]);
				for (int j = 1; j < m; j++)
						printf(" %d", array[i][j]);
		}
}

int main()
{
		srand(time(0));
		int option;
		scanf("%d", &option);
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
