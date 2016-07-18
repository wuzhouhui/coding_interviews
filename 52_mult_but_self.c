#include <stdio.h>
#include <string.h>

static void mult(int *nums, int len)
{
	if (len < 2)
		return;
	int nums2[len];
	int i;
	nums2[0] = 1;
	for (i = 1; i < len; i++)
		nums2[i] = nums2[i - 1] * nums[i - 1];
	int tmp = 1;
	for (i = len - 1; i >= 0; i--) {
		nums2[i] *= tmp;
		tmp *= nums[i];
	}
	memcpy(nums, nums2, sizeof(nums2));
}

int main(void)
{
	int arr[] = { 1, 2, 3, 4, };
	int i;
	mult(arr, sizeof(arr) / sizeof(arr[0]));
	for (i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
		printf("%d\n", arr[i]);
	return(0);
}
