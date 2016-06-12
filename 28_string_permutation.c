#include <string.h>
#include <stdio.h>

static void inline swap(char *a, char *b)
{
	char c = *a;
	*a = *b;
	*b = c;
}

static const char *str;

static void do_perm(char *s, int len)
{
	int i;
	if (len <= 0) {
		printf("%s\n", str);
		return;
	}
	for (i = 0; i < len; i++) {
		swap(&s[0], &s[i]);
		do_perm(s + 1, len - 1);
		swap(&s[0], &s[i]);
	}
}

void perm(char *s)
{
	str = s;
	do_perm(s, strlen(s));
}

int main(int argc, char *argv[])
{
	perm(argv[1]);
	return(0);
}

/*
 * 扩展题
 */
#include <string.h>
#include <stdio.h>

static char buf[32];
static int p;

static void do_comb(const char *s, int m, int n)
{
	if (n <= 0) {
		printf("%s\n", buf);
		return;
	}
	buf[p++] = *s++;
	do_comb(s, m - 1, n - 1);
	buf[--p] = 0;
	do_comb(s, m, n - 1);
}

static void combination(const char *s)
{
	int l = strlen(s);
	do_comb(s, l, l);
}

int main(int argc, char *argv[])
{
	combination(argv[1]);
	return(0);
}
