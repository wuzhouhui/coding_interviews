#include <stdlib.h>
#include <stdio.h>

static void swap(int *a, int *b)
{
	int t = *a;
	*a = *b;
	*b = t;
}

static void k_min_nums(int *nums, int len, int k)
{
	if (k < 1 || k > len)
		return;
	int left, right;
	int i, j;

	i = left = 0;
	right = len - 1;
	while (i + 1 != k) {
		i = left;
		for (j = left + 1; j <= right; j++) {
			if (nums[j] >= nums[left])
				continue;
			swap(&nums[++i], &nums[j]);
		}
		swap(&nums[i], &nums[left]);
		if (i + 1 < k)
			left = i + 1;
		else if (i + 1 > k)
			right = i - 1;
	}
	while (i >= 0)
		printf("%d ", nums[i--]);
	printf("\n");
}

int main(void)
{
	int x[6], i;
	for (i = 0; i < 6; i++)
		x[i] = rand() % 6;
	for (i = 1; i <= 6; i++)
		k_min_nums(x, 6, i);
	return(0);
}
