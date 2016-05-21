#include <stdio.h>

static int min_in_rotated(const int *arr, int right)
{
	if (!arr || right <= 0)
		return(0);

	int	left, mid;
	left = 0;
	right--;
	mid = 0;
	while (left < right && arr[left] >= arr[right]) {
		if (left + 1 == right) {
			mid = right;
			break;
		}
		mid = (left + right) / 2;
		if (arr[left] == arr[mid] && arr[mid] == arr[right]) {
			left++;
			continue;
		}
		if (arr[mid] >= arr[left])
			left = mid;
		else
			right = mid;
	}
	return(arr[mid]);
}

int main(void)
{
	int arr[] = { 3, 4, 5, 1, 2, };
	printf("%d\n", min_in_rotated(arr, sizeof(arr) / sizeof(arr[0])));
	return(0);
}
