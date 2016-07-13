#include <stdio.h>
#include <string.h>

static void reverse(char *s, int l, int r)
{
	char t;
	while (l < r) {
		t = s[l];
		s[l] = s[r];
		s[r] = t;
		l++, r--;
	}
}

static void reverse_words(char *s)
{
	int start, end;

	if (s == NULL)
		return;
	reverse(s, 0, strlen(s) - 1);
	start = 0;
	while (1) {
		while (s[start] == ' ')
			start++;
		if (s[start] == 0)
			break;
		end = start + 1;
		while (s[end] && s[end] != ' ')
			end++;
		reverse(s, start, end - 1);
		start = end;
	}
}

int main(int argc, char *argv[])
{
	reverse_words(argv[1]);
	printf("%s\n", argv[1]);
	return(0);
}
