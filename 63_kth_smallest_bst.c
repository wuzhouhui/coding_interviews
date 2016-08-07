struct treenode {
	int	val;
	struct treenode *left;
	struct treenode *right;
};

static struct treenode *do_kth(struct treenode *root, int *k)
{
	if (root == 0)
		return(0);
	struct treenode *t = do_kth(root->left, k);
	if (t)
		return(t);
	if (--(*k) == 0)
		return(root);
	return(do_kth(root->right, k));
}

struct treenode *kth_node(struct treenode *root, int k)
{
	if (root == 0 || k <= 0)
		return(0);
	return(do_kth(root, &k));
}

int main(void)
{
}
