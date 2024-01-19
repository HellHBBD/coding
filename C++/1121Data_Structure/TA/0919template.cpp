#include <cstdlib>
#include <iostream>
using namespace std;

template <class T>
T minimum(T *array, int arrSize)
{
		T minValue = array[0];
		for (int i = 1; i < arrSize; i++)
				if (array[i] < minValue)
						minValue = array[i];
		return minValue;
}

int main()
{
		int Iarray[5] = {5, 8, 4, 3, 1};
		double Darray[5] = {9.2, 5.4, 7.3, 4.9, 8.1};
		short Sarray[5] = {11, 82, 53, 15, 100};
		cout << "minimum(Iarray) = " << minimum<int>(Iarray, 5) << endl;
		cout << "minimum(Darray) = " << minimum<double>(Darray, 5) << endl;
		cout << "minimum(Sarray) = " << minimum<short>(Sarray, 5) << endl;

		system("pause");
		return 0;
}
