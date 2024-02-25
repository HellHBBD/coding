int **arr = malloc(sizeof(int *) * 3);
for (int i = 0; i < 3; i++)
	arr[i] = malloc(sizeof(int) * 5);

for (int i = 0; i < 3; i++)
	free(arr[i]);
free(arr);
