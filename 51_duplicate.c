#include <stdio.h>

static int duplicate(int *nums, int len)
{
	if (len <= 1)
		return(0);
	int i;
	for (i = 0; i < len; ) {
		if (nums[i] == i) {
			i++;
			continue;
		}
		while (nums[i] != i) {
			if (nums[nums[i]] == nums[i])
				return(nums[i]);
			int t = nums[i];
			nums[i] = nums[t];
			nums[t] = t;
		}
	}
}

int main(void)
{
	int arr[] = { 2, 3, 1, 0, 2, 5, 3, };
	printf("%d\n", duplicate(arr, sizeof(arr) / sizeof(arr[0])));
	return(0);
}
