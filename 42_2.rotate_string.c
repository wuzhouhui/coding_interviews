#include <stdio.h>
#include <string.h>

static void reverse(char *s, int l, int r)
{
	char c;
	while (l < r) {
		c = s[l];
		s[l] = s[r];
		s[r] = c;
		l++, r--;
	}
}

static void rotate_str(char *s, int k)
{
	if (s == NULL || s[0] == 0 || k <= 1)
		return;
	int l = strlen(s);

	if ((k %= l) == 0)
		return;
	reverse(s, 0, l - 1);
	reverse(s, 0, k - 1);
	reverse(s, k, l - 1);
}

int main(int argc, char *argv[])
{
	rotate_str(argv[1], 2);
	printf("%s\n", argv[1]);
	return(0);
}
