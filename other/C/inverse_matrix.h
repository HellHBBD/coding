#ifndef INVERSE_MATRIX_H
#define INVERSE_MATRIX_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swap(void *, void *, const size_t);
double **input(size_t);
double **inverse(double **, const size_t);
void print(double **, const size_t);
void delete (double **, const size_t);

void swap(void *a, void *b, const size_t size)
{
	void *temp = malloc(size);
	memcpy(temp, a, size);
	memcpy(a, b, size);
	memcpy(b, temp, size);
	free(temp);
}

double **input(size_t size)
{
	double **matrix = malloc(sizeof(double *) * size);
	for (int i = 0; i < size; i++) {
		matrix[i] = malloc(sizeof(double) * size);
		for (int j = 0; j < size; j++) {
			scanf("%lf", &matrix[i][j]);
		}
	}
	return matrix;
}

double **inverse(double **matrix, const size_t size)
{
	/* init */
	double **copy = malloc(sizeof(double *) * size);
	double **result = malloc(sizeof(double *) * size);
	for (int i = 0; i < size; i++) {
		copy[i] = malloc(sizeof(double) * size);
		result[i] = malloc(sizeof(double) * size);
		for (int j = 0; j < size; j++) {
			copy[i][j] = matrix[i][j];
			result[i][j] = (i == j);
		}
	}
	for (int i = 0; i < size; i++) {
		/* find pivot */
		if (!copy[i][i]) {
			for (int j = i; j < size; j++) {
				if (copy[j][i]) {
					swap(&copy[i], &copy[j], sizeof(double *));
					swap(&result[i], &result[j], sizeof(double *));
					goto find;
				}
			}
			delete (copy, size);
			delete (result, size);
			return 0;
		}
find:
		/* divide */
		double temp = copy[i][i];
		for (int j = 0; j < size; j++) {
			copy[i][j] /= temp;
			result[i][j] /= temp;
		}
		/* subtract */
		for (int j = 0; j < size; j++) {
			if (i == j)
				continue;
			temp = copy[j][i];
			for (int k = 0; k < size; k++) {
				copy[j][k] -= (temp * copy[i][k]);
				result[j][k] -= (temp * result[i][k]);
			}
		}
	}
	delete (copy, size);
	return result;
}

void print(double **matrix, const size_t size)
{
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			printf("%10lf ", matrix[i][j]);
		}
		puts("");
	}
}

void delete (double **matrix, const size_t size)
{
	for (int i = 0; i < size; i++) {
		free(matrix[i]);
	}
	free(matrix);
}

#endif
