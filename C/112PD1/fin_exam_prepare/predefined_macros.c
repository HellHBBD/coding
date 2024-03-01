#include <stdio.h>

int main()
{
	printf("Date: %s\n", __DATE__);
	printf("Time: %s\n", __TIME__);
	printf("Line: %d\n", __LINE__);
	printf("Function: %s\n", __func__);
	printf("File: %s\n", __FILE__);
	/* CHECK_ZERO(4); */
	printf("is standard: %d\n", __STDC__);
	/* printf("is hosted implementation: %d\n",__STDC__HOSTED__); */
	/* printf("Standard version: %s\n",__STDC__VERSION__); */
#define TEST(condition, ...) \
	((condition) ? printf("Pass test: %s\n", #condition) : printf(__VA_ARGS__))
	TEST(3 < 4, "not pass at line %d\n", __LINE__);
	TEST(3 > 4, "not pass at line %d\n", __LINE__);
#if defined(_WIN32)
	puts("System: Windows");
#elif defined(__linux__)
	puts("System: Linux");
#endif
/* #if 3<4 */
/* #error wtf */
#line 10 "bar.c"
	printf("Line: %d\n", __LINE__);
	printf("File: %s\n", __FILE__);
	/* #pragma data(heap_size = > 1000, stack_size = > 2000) */
	return 0;
}
