#include <stdlib.h>
#include <string.h>
#include <stdio.h>

static char *replace_space(char *s)
{
	int	i, len, space, last;

	len = space = 0;
	for (i = 0; s[i]; i++) {
		len++;
		if (s[i] == ' ')
			space++;
	}
	last = len + space * 2;
	while (len >= 0) {
		if (s[len] != ' ')
			s[last--] = s[len--];
		else {
			s[last--] = '0';
			s[last--] = '2';
			s[last--] = '%';
			len--;
		}
	}
	return(s);
}

static int cnt_space(const char *s)
{
	int	n = 0;
	while (*s) {
		if (*s++ == ' ')
			n++;
	}
	return(n);
}

int main(int argc, char *argv[])
{
	int	i, l;
	char	*s;

	for (i = 1; i < argc; i++) {
		l = strlen(argv[i]) + cnt_space(argv[i]) * 2 + 1;
		s = malloc(l * sizeof(s[0]));
		strcpy(s, argv[i]);
		printf("%s\n", replace_space(s));
		free(s);
	}
	return(0);
}
