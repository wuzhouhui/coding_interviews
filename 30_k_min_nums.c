#include <stdlib.h>
#include <stdio.h>

static void swap(int *a, int *b)
{
	int t = *a;
	*a = *b;
	*b = t;
}

/*
 * heap[1...i]
 */
static void siftup(int *heap, int i)
{
	int p;

	while (1) {
		p = i / 2;
		if (i <= 1 || heap[p] >= heap[i])
			break;
		swap(&heap[p], &heap[i]);
		i = p;
	}
}

/*
 * heap[1...i]
 */
static void siftdown(int *heap, int n)
{
	int c, p;

	p = 1;
	while (1) {
		c = p * 2;
		if (c > n)
			break;
		if (c + 1 <= n && heap[c + 1] > heap[c])
			c++;
		if (heap[c] <= heap[p])
			break;
		swap(&heap[c], &heap[p]);
		p = c;
	}
}

static void k_min_nums2(int *nums, int len, int k)
{
	int heap[k + 1];
	int i;

	for (i = 0; i < len; i++) {
		if (i < k) {
			heap[i + 1] = nums[i];
			siftup(heap, i + 1);
		} else if (nums[i] >= heap[1]) {
			continue;
		} else {
			heap[1] = nums[i];
			siftdown(heap, k);
		}
	}
	while (k > 0)
		printf("%d ", heap[k--]);
	printf("\n");
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
		k_min_nums2(x, 6, i);
	return(0);
}
