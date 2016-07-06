#include <stdio.h>

static int num_times(const int *nums, int len, int tgt)
{
	if (len <= 0)
		return(0);

	int l = -1, r = len;
	int mid;

	/*
	 * nums[l] < tgt <= nums[r]
	 */
	while (l + 1 != r) {
		mid = (l + r) / 2;
		if (nums[mid] < tgt)
			l = mid;
		else
			r = mid;
	}
	if (r >= len || nums[r] != tgt)
		return(0);
	l = 0;
	while (r < len && nums[r] == tgt)
		l++, r++;
	return(l);
}

int main(void)
{
	int arr[] = { 1, 2, 3, 3, 3, 3, 4, 5, };
	int i;
	for (i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
		printf("%d\n", num_times(arr, sizeof(arr) / sizeof(arr[0]),
					arr[i]));
	printf("%d\n", num_times(arr, sizeof(arr) / sizeof(arr[0]), 0));
	return(0);
}
