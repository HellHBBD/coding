#include <stdio.h>
#define ARR_MAX 1000

void sort_section(int *ptr, int *qtr)
{
	int *start = ptr < qtr ? ptr : qtr;
	int *end = ptr > qtr ? ptr : qtr;
	for (int *i = start; i < end; i++) {
		for (int *j = start; j < end; j++) {
			if (*j > *(j + 1)) {
				*j = *j ^ *(j + 1);
				*(j + 1) = *j ^ *(j + 1);
				*j = *j ^ *(j + 1);
			}
		}
		for (int *j = start; j <= end; j++)
			printf("%d ", *j);
		puts("");
	}
}

int main()
{
	int N, a, b;
	scanf("%d%d%d", &N, &a, &b);
	int arr[ARR_MAX] = { 0 };
	for (int i = 0; i < N; i++)
		scanf("%d", arr + i);
	sort_section(&arr[a], &arr[b]);
	for (int i = 0; i < N; i++)
		printf("%d ", *(arr + i));
}
