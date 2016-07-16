#include <stdio.h>

static int cmp(const void *a, const void *b)
{
	return(*(int *)a - *(int *)b);
}

static int shunzi(int *nums)
{
	int i, zerocnt, t, gap;

	qsort(nums, 5, sizeof(nums[0]), cmp);
	zerocnt = 0;
	for (i = 0; i < 5; i++)
		if (nums[i] == 0)
			zerocnt++;
		else
			break;
	if (i > 2)
		return(0);
	gap = 0;
	for (i++; i < 5; i++) {
		t = nums[i] - nums[i - 1] - 1;
		if (t < 0)
			return(0);
		else
			gap += t;
	}
	return(zerocnt >= gap);
}

int main(void)
{
}
