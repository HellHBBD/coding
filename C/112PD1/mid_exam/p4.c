#include <stdio.h>

int pureRecursive(int n){
	if (n <= 2)
		return n;
	else
		return pureRecursive(n-1)+pureRecursive(n-2)+pureRecursive(n-3);
}

int main(){
	return 0;
}
