#include <stdlib.h>

struct treenode {
	int	val;
	struct treenode *left;
	struct treenode *right;
};

static int *res, p, maxp;

static void add(int v)
{
	if (p >= maxp) {
		maxp += 16;
		res = realloc(res, maxp * sizeof(*res));
	}
	res[p++] = v;
}

static void do_seri(const struct treenode *root)
{
	if (root == NULL) {
		add(-1);
		return;
	}
	add(root->val);
	do_seri(root->left);
	do_seri(root->right);
}

int *serialize(const struct treenode *root, int *len)
{
	if (root == NULL) {
		*len = 0;
		return(NULL);
	};
	maxp = p = 0;
	res = NULL;
	do_seri(root);
	*len = p;
	return(res);
}

int main(void)
{
	return(0);
}
