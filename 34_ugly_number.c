#include <stdio.h>

static inline int min(int a, int b)
{
	return(a < b ? a : b);
}

static int nth_ugly(int n)
{
	if (n <= 0)
		return(0);
	int uglies[n];
	int i, t2, t3, t5, i2, i3, i5;

	uglies[0] = 1;
	i2 = i3 = i5 = 0;
	for (i = 1; i < n; i++) {
		t2 = uglies[i2] * 2;
		t3 = uglies[i3] * 3;
		t5 = uglies[i5] * 5;
		uglies[i] = min(t2, min(t3, t5));
		if (uglies[i] == t2)
			i2++;
		if (uglies[i] == t3)
			i3++;
		if (uglies[i] == t5)
			i5++;
	}
	return(uglies[n - 1]);
}

int main(void)
{
	printf("%d\n", nth_ugly(1500));
	return(0);
}
