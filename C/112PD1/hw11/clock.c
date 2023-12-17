#include <stdio.h>
#include <stdlib.h>

unsigned long long int begin, end;

//32-bit
inline unsigned long long int rdtsc() {
	unsigned long long int x;
	__asm__ volatile("rdtsc"
					 : "=A"(x));
	return x;
}

//64-bit
inline unsigned long long int rdtsc_64bits() {
	unsigned long long int x;
	unsigned a, d;

	__asm__ volatile("rdtsc"
					 : "=a"(a), "=d"(d));

	return ((unsigned long long)a) | (((unsigned long long)d) << 32);
	;
}

int main() {

	begin = rdtsc();
	/*---------------------------
	your function
	---------------------------*/
	end = rdtsc();

	printf("Execute cycles %llu \n", (end - begin));
}
