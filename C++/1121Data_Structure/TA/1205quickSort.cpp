#include <ctime>
#include <iostream>
using namespace std;
#define num 11

void swap(int *a, int *b)
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

void PrintArray(int *arr)
{
	for (int i = 0; i < num; i++)
		cout << arr[i] << " ";
	cout << endl;
}

void quickSort(int *arr, int left, int right)
{
	if (left < right) {
		int pivot = arr[left]; //���]pivot�b�Ĥ@�Ӫ���m
		//cout<<pivot<<endl;
		int l = left;
		int r = right + 1;

		while (1) {
			while (l < right && arr[++l] < pivot)
				; //�V�k��p��pivot���ƭȪ���m
			while (r > 0 && arr[--r] > pivot)
				; //�V����j��pivot���ƭȪ���m

			if (l >= r) //�d��pivot�k��S����pivot�p����,�Ϥ���M
				break;
			//code
			swap(&arr[l], &arr[r]);
		}
		//code
		swap(&arr[left], &arr[r]);

		quickSort(arr, left, r - 1); //���l�ƦC�����j
		quickSort(arr, r + 1, right); //�k�l�ƦC�����j
	}
}

int main()
{
	int arr[num] = { 6, 2, 8, 5, 11, 10, 4, 1, 9, 7, 3 };

	cout << "before sorting" << endl;
	PrintArray(arr);
	quickSort(arr, 0, num - 1);
	cout << endl;
	cout << "after sorting:" << endl;
	PrintArray(arr);
	cout << endl;
	return 0;
}
