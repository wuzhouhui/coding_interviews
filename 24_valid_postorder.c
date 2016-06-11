#include <stdio.h>
#define ARRSIZE(a) (sizeof(a) / sizeof(a[0]))
typedef int bool;

enum {
	true = 1,
	false = 0,
};

bool valid_postorder(const int *nums, int len)
{
	if (len <= 1)
		return(true);
	int k, i;

	k = 0;
	while (k < len && nums[k] < nums[len - 1])
		k++;
	for (i = k; i < len - 1; i++)
		if (nums[i] <= nums[len - 1])
			return(false);
	return(valid_postorder(nums, k) &&
			valid_postorder(nums + k, len - 1 - k));
}

int main(void)
{
	int a[] = { 5, 7, 6, 9, 11, 10, 8, };
	int b[] = { 7, 4, 6, 5, };
	printf("%d %d\n", valid_postorder(a, ARRSIZE(a)),
				valid_postorder(b, ARRSIZE(b)));
	return(0);
}
