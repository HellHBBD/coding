#include <iostream>
using namespace std;

int *firstNeg(int a[],int n){
	for (int i=0;i<n;i++){
		if (a[i] < 0)
			return &a[i];
	}
	return 0;
}

int main(){
	int a[5];
	for (int i=0;i<5;i++)
		cin >> a[i];
	int *p = firstNeg(a,5);
	if (p != 0)
		cout << *p << " " << p-a;
	else
		cout << "no negative number";
	return 0;
}
