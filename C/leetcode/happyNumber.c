#include <stdio.h>
#include <stdbool.h>

bool isHappy(unsigned n)
{
	const int notHappyList[] = {37, 58, 89, 142, 42, 20, 4, 16};
	int total = 0;
	while (n != 0) {
		int digit = n % 10;
		n /= 10;
		total += (digit * digit);
	}
	if (total == 1)
		return true;

	for (int i = 0;i < 8;i++) {
		if (total == notHappyList[i]) {
			return false;
		}
	}

	return isHappy(total);
}

int main()
{
	printf("%d\n", isHappy(19));
	return 0;
}
