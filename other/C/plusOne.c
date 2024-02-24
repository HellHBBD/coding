#include <stdio.h>
#include <stdlib.h>

int *plusOne(int *digits, int digitsSize, int *returnSize)
{
	int nineCount = 0;
	int *result;
	for (int i = 0; i < digitsSize; i++) {
		if (digits[i] != 9)
			break;
		nineCount++;
	}
	if (nineCount == digitsSize) {
		result = malloc((digitsSize + 1) * sizeof(int));
		result[0] = 1;
		for (int i = 0; i < digitsSize; i++)
			result[i + 1] = 0;
		*returnSize = digitsSize + 1;
		return result;
	} else {
		int curr = digitsSize - 1;
		while (curr >= 0) {
			if (digits[curr] != 9) {
				digits[curr]++;
				break;
			} else {
				digits[curr] = 0;
			}
			curr--;
		}
		*returnSize = digitsSize;
		return digits;
	}
}

int main()
{
	int array[] = { 9, 9, 9, 9, 9, 9, 9 };
	int size;
	int *result = plusOne(array, 7, &size);
	for (int i = 0; i < size; i++) {
		printf("%d ", result[i]);
	}
	free(result);
	return 0;
}
