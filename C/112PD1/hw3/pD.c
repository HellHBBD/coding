#include <stdio.h>
#include <limits.h>

int main(){
    long long a,b;
    scanf("%lld%lld",&a,&b);
	if ((a > 0 && b < 0) || (a < 0 && b > 0))
		printf("No");
	else if (a > LLONG_MAX-b || a < LLONG_MIN-b)
		printf("Yes");
	else
		printf("No");
    return 0;
}
