#include <stdio.h>

static void sum2s(const int *nums, int len, int sum, int *res)
{
	if (nums == NULL || len < 2)
		return;

	int l, r, t;

	for (l = 0, r = len - 1; l < r;) {
		t = nums[l] + nums[r];
		if (t == sum) {
			*res++ = nums[l];
			*res = nums[r];
			return;
		} else if (t > sum)
			r--;
		else
			l++;
	}
}

int main(void)
{
	int arr[] = { 1, 2, 4, 7, 11, 15, };
	int res[2];
	sum2s(arr, sizeof(arr) / sizeof(arr[0]), 15, res);
	printf("%d %d\n", res[0], res[1]);
	return(0);
}
