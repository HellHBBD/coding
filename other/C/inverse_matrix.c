#include <stdio.h>
#include "inverse_matrix.h"

int main()
{
	size_t size;
	/* printf("matrix size: "); */
	scanf("%ld", &size);
	double **matrix = input(size);
	double **result = inverse(matrix, size);
	print(matrix, 3);
	puts("");
	if (result) {
		print(result, 3);
		delete (result, size);
	} else {
		fputs("no inverse matrix\n", stderr);
	}
	delete (matrix, size);
	return 0;
}
