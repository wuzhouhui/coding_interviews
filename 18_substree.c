struct treenode {
	int	val;
	struct treenode *left;
	struct treenode *right;
};

static int do_has(const struct treenode *root1, const struct treenode *root2)
{
	if (!root2)
		return(1);
	if (!root1)
		return(0);
	if (root1->val != root2->val)
		return(0);
	return(do_has(root1->left, root2->left) && do_has(root1->right,
				root2->right));
}

int hassubtree(const struct treenode *root1, const struct treenode *root2)
{
	if (!root1 || !root2)
		return(0);
	int	r = 0;
	if (root1->val == root2->val)
		r = do_has(root1, root2);
	if (!r)
		r = hassubtree(root1->left, root2);
	if (!r)
		r = hassubtree(root1->right, root2);
	return(r);
}

int main(void)
{
}
