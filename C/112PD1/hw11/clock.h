//32-bit
unsigned long long int rdtsc()
{
	unsigned long long int x;
	__asm__ volatile("rdtsc" : "=A"(x));
	return x;
}

//64-bit
unsigned long long int rdtsc_64bits()
{
	unsigned long long int x;
	unsigned a, d;

	__asm__ volatile("rdtsc" : "=a"(a), "=d"(d));

	return ((unsigned long long)a) | (((unsigned long long)d) << 32);
	;
}
