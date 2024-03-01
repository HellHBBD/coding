#include <iostream>
using namespace std;

int maximum(int *arr, int size)
{
	int max = *arr;
	int *p = arr + 1;
	for (int i = 1; i < size; i++) {
		if (*p > max)
			max = *p;
		p++;
	}
	return max;
}

int *expand(int *arr, int size)
{
	int *array = new int[2 * size];
	for (int i = 0; i < size; i++) {
		*array = *arr;
		array++;
		arr++;
	}
	for (int i = 0; i < size; i++) {
		*array = -1;
		array++;
	}
	return array;
}

int *concatenate(int *arr1, int *arr2, int size1, int size2)
{
	int *array = new int[size1 + size2];
	int *p = array;
	for (int i = 0; i < size1; i++) {
		*p = *arr1;
		p++;
		arr1++;
	}
	for (int i = 0; i < size2; i++) {
		*p = *arr2;
		p++;
		arr2++;
	}
	return array;
}

int main()
{
	int size1, size2;
	cin >> size1 >> size2;
	int arr1[size1], arr2[size2], element;
	for (int i = 0; i < size1; i++) {
		cin >> element;
		arr1[i] = element;
	}
	for (int i = 0; i < size2; i++) {
		cin >> element;
		arr2[i] = element;
	}

	cout << maximum(arr1, size1) << endl;
	cout << maximum(arr2, size2) << endl;

	int *arr3 = expand(arr1, size1);
	for (int i = 0; i < size1 * 2; i++)
		if (i < size1 * 2 - 1)
			cout << arr3[i] << " ";
		else
			cout << arr3[i];
	cout << endl;

	int *arr4 = concatenate(arr1, arr2, size1, size2);
	for (int i = 0; i < size1 + size2; i++)
		if (i < size1 + size2 - 1)
			cout << arr4[i] << " ";
		else
			cout << arr4[i];
	cout << endl;
}
