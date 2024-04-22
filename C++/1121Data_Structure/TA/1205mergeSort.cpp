#include <algorithm> // for max, min
#include <cstdio> // for NULL
#include <cstdlib> // for srand, rand
#include <ctime> // for time
#include <iostream>
#include <vector>
using namespace std;

void merge(int *arr, int size, int left, int right, int end)
{
	// size: 複製 array 要用的，請傳原始的 array 長度進來
	// left: 左邊待排序 subarray 的起始 index; right: 右邊待排序 subarray 的起始 index;
	// end: 右邊待排序 subarray 的結尾 index + 1
	int i = left, j = right;
	int *duplicateArr = new int[size];
	for (int a = 0; a < size; ++a)
		duplicateArr[a] = arr[a];
	for (int k = left; k < end; ++k) {
		if (i < right &&
		    (j >= end || duplicateArr[i] < duplicateArr[j])) {
			arr[k] = duplicateArr[i];
			i++;
		} else {
			arr[k] = duplicateArr[j];
			j++;
		}
	}
	delete[] duplicateArr;
}

void mergeSort(int *arr, int size)
{
	// size: merge 的 finction 中複製 array 要用的，請傳原始的 array 長度進來
	for (int len = 1; len < size; len *= 2) {
		// 從長度為 1 的 subarray 開始 merge，合併之後長度會變成兩倍
		for (int i = 0; i < size; i += len * 2)
			merge(arr, size, i, min(i + len, size),
			      min(i + 2 * len, size));
	}
}

void natural_mergeSort(int *arr, int size)
{
	//find divided index
	vector<int> index;
	vector<int>::iterator it;
	int temp = arr[0];
	index.push_back(0);
	for (int i = 1; i < size; i++)
		if (arr[i] >= temp)
			temp = arr[i];

		else
			index.push_back(i);
	//cout<<"cut index:";
	//for(it=index.begin(); it!=index.end(); ++it) cout << *it << " "; //traverse element
	int num = 0;
	while (index.size() > 1) {
		if (num ==
		    index.size() -
			    1) { //已經指到最後一個，不執行合併，往下個回合執行
			num = 0;
			continue;
		}
		if (num ==
		    index.size() -
			    2) //if dont have next index,end pointer assigned "size"
			merge(arr, size, index[num], index[num + 1], size);

		else //use next index() as "end" pointer
			merge(arr, size, index[num], index[num + 1],
			      index[num + 2]);

		num++;
		it = index.begin() + num; //after merge delete the middle index
		index.erase(it);
	}
}

int main()
{
	int size = 10;
	int arr[10] = { 3, 4, 2, 1, 7, 5, 8, 9, 6, 10 };
	int n_arr[10] = { 3, 4, 2, 1, 7, 5, 8, 9, 6, 10 };
	cout << "\n\nmerge sort:\n";
	mergeSort(arr, size);
	for (int i = 0; i < size; ++i)
		cout << arr[i] << ' ';
	cout << "\n\n";
	cout << "\n\nnatural merge sort:\n";
	natural_mergeSort(n_arr, size);
	for (int i = 0; i < size; ++i)
		cout << n_arr[i] << ' ';
	cout << "\n\n";

	return 0;
}
