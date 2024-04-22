#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#define abs(a, b) ((a) > (b) ? (a) - (b) : (b) - (a))

struct File {
	int name;
	int size;
};

struct FileList {
	struct File *disk[21];
	int count;
};

int Cnr(int n, int r)
{
	int result = 1;
	for (int i = r; i <= n; i++)
		result *= i;
	for (int i = 1; i <= (n - r); i++)
		result /= i;
	return result;
}

void optimizeDelete(struct File **disk, const int n, const int r,
		    int expectSize, struct FileList *currentChoice, int *index,
		    int currentSize, struct FileList *bestChoice, int *bestSize)
{
	if (r == 1) {
		for (int i = 0; i < n; i++) {
			currentSize += disk[i]->size;
			currentChoice->disk[*index] = disk[i];
			(*index)++;

			if (abs(expectSize, currentSize) <
				    abs(expectSize, *bestSize) ||
			    *bestSize == 0) {
				*bestSize = currentSize;
				*bestChoice = *currentChoice;
			}

			currentSize -= disk[i]->size;
			(*index)--;
		}
		return;
	}
	for (int i = r - 1; i < n; i++) {
		currentSize += disk[i]->size;
		currentChoice->disk[*index] = disk[i];
		(*index)++;
		optimizeDelete(disk, i, r - 1, expectSize, currentChoice, index,
			       currentSize, bestChoice, bestSize);
		currentSize -= disk[i]->size;
		(*index)--;
	}
}

void add(struct FileList *fileList)
{
	int i = 0;
	for (; i < 21; i++) {
		if (fileList->disk[i] == 0) {
			fileList->disk[i] = malloc(sizeof(struct File));
			printf("Please input file name and file size: ");
			scanf("%d%d", &fileList->disk[i]->name,
			      &fileList->disk[i]->size);
			fileList->count++;
			break;
		}
	}
	if (fileList->count == 21) {
		int fileCount, fileSize;
		printf("Hard drive exceeds its capacity, please enter the number of files to be deleted: ");
		scanf("%d%d", &fileCount, &fileSize);
		struct FileList currentChoice = { .disk = {},
						  .count = fileCount };
		struct FileList bestChoice = { .disk = {}, .count = fileCount };
		int index = 0, bestSize = 0;
		optimizeDelete(fileList->disk, 21, fileCount, fileSize,
			       &currentChoice, &index, 0, &bestChoice,
			       &bestSize);
		for (int i = 0; i < fileCount; i++)
			if (i == 0)
				printf("%d", bestChoice.disk[i]->name);
			else
				printf(" %d", bestChoice.disk[i]->name);
		puts("");
		for (int i = 0; i < fileList->count; i++) {
			bool allDelete = true;
			for (int j = 0; j < fileCount; j++) {
				if (bestChoice.disk[j] != 0) {
					allDelete = false;
					if (bestChoice.disk[j] ==
					    fileList->disk[i]) {
						free(fileList->disk[i]);
						bestChoice.disk[j] =
							fileList->disk[i] = 0;
					}
				}
			}
			if (allDelete)
				break;
		}
		fileList->count -= fileCount;
	}
}

void query(const struct FileList *fileList)
{
	int fileName;
	printf("Please input the file name: ");
	scanf("%d", &fileName);
	for (int i = 0; i < 21; i++) {
		if (fileList->disk[i] == 0)
			continue;
		if (fileList->disk[i]->name == fileName) {
			puts("YES");
			return;
		}
	}
	puts("NO");
}

void delete(struct FileList *fileList)
{
	for (int i = 0; i < 21; i++) {
		if (fileList->disk[i] != 0) {
			free(fileList->disk[i]);
			fileList->disk[i] = 0;
		}
	}
	fileList->count = 0;
}

int main()
{
	struct FileList fileList = { .disk = {}, .count = 0 };
	while (1) {
		int option;
		printf("Options: ");
		scanf("%d", &option);
		switch (option) {
		case 1:
			add(&fileList);
			break;
		case 2:
			query(&fileList);
			break;
		case 3:
			delete (&fileList);
			return 0;
		}
	}
}
