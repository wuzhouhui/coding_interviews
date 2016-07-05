#include <stdio.h>

static char occur_once(const char *s)
{
	if (s == NULL)
		return(0);
	char map[256] = { 0 };
	int i;

	while (*s) {
		if (map[*s] < 2)
			map[*s]++;
		s++;
	}
	for (i = 0; i < 256; i++)
		if (map[i] == 1)
			return(i);
	return(0);
}

int main(int argc, char *argv[])
{
	printf("%c\n", occur_once(argv[1]));
	return(0);
}
