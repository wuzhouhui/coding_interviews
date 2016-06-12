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
