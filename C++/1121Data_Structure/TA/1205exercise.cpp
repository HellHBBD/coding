#include <iostream>
#include <ctime>
using namespace std;
#define num 11

void swap(int *a, int *b)
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}


void PrintArray(int *arr){
    for (int i = 0; i < num; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void quickSort(int *arr, int left, int right)
{
	if (left < right)
	{
		int pivot = arr[left];//假設pivot在第一個的位置
		//cout<<pivot<<endl;
		int l = left;
		int r = right + 1;

		while (1)
		{
			while (l < right && arr[++l] < pivot);//向右找小於pivot的數值的位置
			while (r > 0 && arr[--r] > pivot);//向左找大於pivot的數值的位置

			if (l >= r)//範圍內pivot右邊沒有比pivot小的數,反之亦然
			{
				break;
			}
            //比pivot大的數移到右邊，比pivot小的數換到左邊
			//code


		}
		//將pivot移到中間
    	//code

		quickSort(arr, left, r - 1);//左子數列做遞迴
		quickSort(arr, r + 1, right);//右子數列做遞迴
       
	}
}





int main()
{
	int arr[num] = {6,2,8,5,11,10,4,1,9,7,3};

	cout << "before sorting" << endl;
	PrintArray(arr);
	quickSort(arr, 0, num - 1);
	cout << endl;
	cout << "after sorting:" << endl;
	PrintArray(arr);
	cout << endl;
	return 0;
}
