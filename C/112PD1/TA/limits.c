#include <limits.h>
#include <stdio.h>

int main()
{
	printf("INT_MIN(2^31-1): %d\nINT_MAX(-2^31): %d\n", INT_MIN, INT_MAX);
	printf("UINT_MAX(2^32-1): %u\n", UINT_MAX);
	printf("LLONG_MIN(2^63-1): %lld\nLLONG_MAX(-2^63): %lld\n", LLONG_MIN,
	       LLONG_MAX);
	/* INT_MIN(2^31-1): -2147483648 */
	/* INT_MAX(-2^31): 2147483647 */
	/* UINT_MAX(2^32-1): 4294967295 */
	/* LLONG_MIN(2^63-1): -9223372036854775808 */
	/* LLONG_MAX(-2^63): 9223372036854775807 */
	return 0;
}
