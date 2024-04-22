#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <iostream>
using namespace std;

void randomArray(int array[], int length)
{
	for (int i = 0; i < length; i++)
		array[i] = (rand() % 100);
}

void cinArray(int array[], int length)
{
	for (int i = 0; i < length; i++)
		cin >> array[i];
}

void printArray(int array[], int length, int itemInRow)
{
	for (int i = 0; i < length; i++) {
		cout << setw(3) << array[i] << " ";
		if ((i + 1) % itemInRow == 0)
			cout << endl;
	}
}

void insertionSort(int array[], int length)
{
	int currentItemIndex, insertItem;
	for (int insertItemIndex = 1; insertItemIndex < length;
	     insertItemIndex++) {
		insertItem = array[insertItemIndex];
		cout << "insert item: " << insertItem << endl;
		for (currentItemIndex = insertItemIndex; currentItemIndex >= 0;
		     currentItemIndex--) {
			if ((array[currentItemIndex - 1] < insertItem) or
			    currentItemIndex == 0) {
				array[currentItemIndex] = insertItem;
				printArray(array, length, 10);
				break;
			}
			array[currentItemIndex] = array[currentItemIndex - 1];
			printArray(array, length, 10);
		}
		cout << endl;
	}
}

void bubbleSort(int array[], int length)
{
	int bubbleItem;
	for (int surface = length; surface > 0; surface--) {
		for (int bubble = 0; bubble < surface - 1; bubble++) {
			bubbleItem = array[bubble];
			if (bubbleItem > array[bubble + 1]) {
				array[bubble] = array[bubble + 1];
				array[bubble + 1] = bubbleItem;
			}
			printArray(array, length, 10);
		}
		cout << endl;
	}
}

void merge(int array[], int left, int mid, int right)
{
	int leftArray[mid - left + 1], rightArray[right - mid + 1];
	for (int i = left; i <= mid; i++)
		leftArray[i] = array[i];
	for (int i = mid + 1; i <= right; i++)
		rightArray[i - (mid - left + 1)] = array[i];
	int leftIndex = 0, rightIndex = 0;
	for (int i = left; i < right; i++) {
		if (leftArray[leftIndex] <= rightArray[rightIndex]) {
			array[i] = leftArray[leftIndex];
			leftIndex++;
		} else {
			array[i] = rightArray[rightIndex];
			rightIndex++;
		}
	}
}

void mergeSort(int array[], int start, int end)
{ //not done
	int mid = end / 2;
	mergeSort(array, start, mid);
	mergeSort(array, mid, end);
	merge(array, start, mid, end);
}

int main()
{
	srand(time(0));
	const int itemInRow = 10;
	int arraySize;
	cout << "array size: ";
	cin >> arraySize;
	int array[arraySize];

	randomArray(array, arraySize);
	cout << "before sort:" << endl;
	printArray(array, arraySize, itemInRow);
	cout << endl;

	insertionSort(array, arraySize);
	// bubbleSort(array,arraySize);
	//mergeSort(array,0,arraySize);

	// cout << "after sort:" << endl;
	// printArray(array,arraySize,itemInRow);

	return 0;
}
