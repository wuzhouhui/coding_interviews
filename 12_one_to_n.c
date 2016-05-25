#include <stdio.h>
#include <string.h>
#include <stdlib.h>

static inline void prnum(const char *s)
{
	printf("%s\n", s);
}

static void one_to_n(int n)
{
	if (n <= 0)
		return;

	char num[n + 1];
	int c, i, highest;

	memset(num, '0', sizeof(num));
	num[n] = 0;
	highest = n - 1;
	while (1) {
		c = 1;
		for (i = n - 1; i >= 0 && c; i--) {
			num[i] += c;
			c = 0;
			if (num[i] > '9') {
				num[i] -= 10;
				c = 1;
			}
			if (i < highest)
				highest = i;
		}
		if (c)
			break;
		prnum(num + highest);
	}
}

int main(int argc, char *argv[])
{
	if (argc != 2)
		one_to_n(2);
	else
		one_to_n(atoi(argv[1]));
	return(0);
}
