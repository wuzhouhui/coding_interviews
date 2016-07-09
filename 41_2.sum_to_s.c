#include <stdio.h>

static void printans(const int *nums, int start, int end)
{
	while (start <= end)
		printf("%d ", nums[start++]);
	printf("\n");
}

static void sum2s(const int *nums, int len, int sum)
{
	if (nums == NULL || len < 2)
		return;
	int l, r, t;

	l = 0;
	r = 1;
	t = nums[0] + nums[1];
	while (r < len) {
		while (t < sum && ++r < len)
			t += nums[r];
		if (r >= len)
			break;
		while (t > sum && l + 1 < r)
			t -= nums[l++];
		if (t == sum)
			printans(nums, l, r);
		r++;
		if (r < len)
			t += nums[r];
	}
}

int main(void)
{
	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, };
	sum2s(arr, sizeof(arr) / sizeof(arr[0]), 15);
	return(0);
}
