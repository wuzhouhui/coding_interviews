#include <stdio.h>

static int max_sum(int *nums, int len)
{
	if (len <= 0)
		return(0);

	int i, cur, max, t;
	cur = max = nums[0];
	for (i = 1; i < len; i++) {
		if ((t = cur + nums[i]) > nums[i])
			cur = t;
		else
			cur = nums[i];
		if (cur > max)
			max = cur;
	}
	return(max);
}

int main(void)
{
	int a[] = { 1, -2, 3, 10, -4, 7, 2, -5, };
	printf("%d\n", max_sum(a, sizeof(a) / sizeof(a[0])));
	return(0);
}
