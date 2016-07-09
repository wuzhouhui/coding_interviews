struct TreeNode {
	int	val;
	struct TreeNode *left;
	struct TreeNode *right;
};

static int do_bala(const struct TreeNode *root, int *h)
{
	if (root == 0) {
		*h = 0;
		return(1);
	}
	int hl, hr;
	if (!do_bala(root->left, &hl))
		return(0);
	if (!do_bala(root->right, &hr))
		return(0);
	if (hl - hr < -1 || hl - hr > 1)
		return(0);
	*h = (hl > hr ? hl : hr) + 1;
	return(1);
}

static int is_balanced(const struct TreeNode *root)
{
	int h;
	return(do_bala(root, &h));
}

int main(void)
{
}
