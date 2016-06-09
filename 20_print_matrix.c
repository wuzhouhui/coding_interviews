#include <stdio.h>

void printmat(int **matrix, int row, int col)
{
	int up = 0, left = 0, down = row - 1, right = col - 1;
	int i;
	while (up < down && left < right) {
		for (i = left; i < right; i++)
			printf("%d", matrix[up][i]);
		for (i = up; i < down; i++)
			printf("%d", matrix[i][right]);
		for (i = right; i > left; i--)
			printf("%d", matrix[down][i]);
		for (i = down; i > up; i--)
			printf("%d", matrix[i][left]);
		up++, left++, down--, right--;
	}
	if (up == down && left == right)
		printf("%d", matrix[up][left]);
	else if (up == down)
		for (i = left; i <= right; i++)
			printf("%d", matrix[up][i]);
	else if (left == right)
		for (i = up; i <= down; i++)
			printf("%d", matrix[i][left]);
}

int main(void)
{
}
