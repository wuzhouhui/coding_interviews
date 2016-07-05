#include <stdio.h>

static int revpair(const int *nums, int len)
{
	int r = 0, i, j;
	for (i = 0; i < len; i++)
		for (j = i + 1; j < len; j++)
			if (nums[i] > nums[j])
				r++;
	return(r);
}

int main(void)
{
	int a[] = { 7, 5, 6, 4, };
	printf("%d\n", revpair(a, sizeof(a) / sizeof(a[0])));
	return(0);
}
