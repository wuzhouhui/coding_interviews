#include <stdio.h>

static void occur_once(const int *nums, int len, int *res)
{
	int i, t;
	if (len < 2)
		return;
	for (t = i = 0; i < len; i++)
		t ^= nums[i];
	for (i = 1; (t & i) == 0; i <<= 1)
		;
	t = i;
	res[0] = res[1] = 0;
	for (i = 0; i < len; i++) {
		if (nums[i] & t)
			res[0] ^= nums[i];
		else
			res[1] ^= nums[i];
	}
}

int main(void)
{
	int arr[] = { 2, 4, 3, 6, 3, 2, 5, 5, };
	int res[2];
	occur_once(arr, sizeof(arr) / sizeof(arr[0]), res);
	printf("%d %d\n", res[0], res[1]);
	return(0);
}
