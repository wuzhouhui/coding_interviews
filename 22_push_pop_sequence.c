#include <stdlib.h>
#include <stdio.h>

struct stack {
	int	val;
	struct stack *next;
};

static struct stack *stack;

static int empty(void)
{
	return(stack == NULL);
}

static int top(void)
{
	return(stack->val);
}

static int pop(void)
{
	struct stack *t = stack;
	int	v = t->val;
	stack = stack->next;
	free(t);
	return(v);
}

static void push(int v)
{
	struct stack *t = malloc(sizeof(*t));
	t->val = v;
	t->next = stack;
	stack = t;
}

static int valid(const int *pushseq, const int *popseq, int len)
{
	int p1, p2, res;
	p1 = p2 = 0;
	while (1) {
		while (empty() || top() != popseq[p2]) {
			if (p1 >= len) {
				res = 0;
				goto out;
			}
			push(pushseq[p1++]);
		}
		pop();
		if (++p2 >= len) {
			res = 1;
			break;
		}
	}
out:
	while (!empty())
		pop();
	return(res);
}

int main(void)
{
	int a[] = { 1, 2, 3, 4, 5, };
	int b[] = { 4, 5, 3, 2, 1, };
	int c[] = { 4, 3, 5, 1, 2, };
	printf("%d %d\n", valid(a, b, 5), valid(a, c, 5));
	return(0);
}
