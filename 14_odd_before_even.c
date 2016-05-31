#include <stdio.h>

static void odd_before_even(int *num, int len)
{
	int i, j, t;
	if (!num || !len)
		return;
	for (i = j = 0; j < len; j++) {
		if (num[j] & 1) {
			t = num[i];
			num[i] = num[j];
			num[j] = t;
			i++;
		}
	}
}

int main(void)
{
	int i;
	int a[] = { 1, 2, 3, 4, 5, };
	odd_before_even(a, sizeof(a) / sizeof(a[0]));
	for (i = 0; i < sizeof(a) / sizeof(a[0]); i++)
		printf("%d ", a[i]);
	printf("\n");
	return(0);
}
