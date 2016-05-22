#include <stdio.h>

static int fibonaci(int n)
{
	if (n <= 0)
		return(0);
	if (n == 1)
		return(1);

	int	f1 = 0, f2 = 1, r;
	int	i;
	for (i = 2; i <= n; i++) {
		r = f1 + f2;
		f1 = f2;
		f2 = r;
	}
	return(r);
}

int main(void)
{
	int	i;
	for (i = -1; i < 10; i++)
		printf("%d\n", fibonaci(i));
	return(0);
}
