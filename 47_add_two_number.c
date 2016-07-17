#include <stdio.h>

static int add(int a, int b)
{
	int sum, carry;
	do {
		sum = a ^ b;
		carry = (a & b) << 1;
		a = sum;
		b = carry;
	} while (b);
	return(a);
}

int main(void)
{
	printf("%d\n", add(3, 6));
	return(0);
}
