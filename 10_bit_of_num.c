#include <stdio.h>

static int bits(int n)
{
	int i = 1, r = 0;
	while (i) {
		if (n & i)
			r++;
		i <<= 1;
	}
	return(r);
}

static int bits2(int n)
{
	int r = 0;
	while (n) {
		r++;
		n &= (n - 1);
	}
	return(r);
}

int main(void)
{
	printf("%d\n", bits(~0));
	printf("%d\n", bits2(~0));
	return(0);
}
