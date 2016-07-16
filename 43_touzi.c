#include <stdio.h>
#include <string.h>
#include <math.h>

static do_touzi(int cursum, int left, int *prob)
{
	int i;

	if (left <= 0) {
		prob[cursum]++;
		return;
	}
	left--;
	for (i = 1; i <= 6; i++) {
		cursum++;
		do_touzi(cursum, left, prob);
	}
}

static void touzi(int num)
{
	if (num <= 0)
		return;
	int prob[6 * num + 1];
	double total = pow(6, num);
	int i;

	memset(prob, 0, sizeof(prob));
	do_touzi(0, num, prob);
	for (i = num; i <= 6 * num; i++)
		printf("%d: %f\n", i, prob[i] / total);
}

static void touzi2(int num)
{
	if (num <= 0)
		return;
	int prob[2][num * 6 + 1];
	int flag = 0;
	int i, j, k;
	double total = pow(6, num);

	memset(prob, 0, sizeof(prob));
	for (i = 1; i <= 6; i++)
		prob[flag][i] = 1;
	for (i = 2; i <= num; i++) {
		for (j = 1; j < i; j++)
			prob[1 - flag][j] = 0;
		for (j = i; j <= i * 6; j++) {
			prob[1 - flag][j] = 0;
			for (k = 1; k < j && k <= 6; k++)
				prob[1 - flag][j] += prob[flag][j - k];
		}
		flag = 1 - flag;
	}
	for (i = num; i <= num * 6; i++)
		printf("%d: %f\n", i, prob[flag][i] / total);
}

int main(void)
{
	touzi(3);
	touzi2(3);
	return(0);
}
