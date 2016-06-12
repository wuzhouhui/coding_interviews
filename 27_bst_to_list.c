struct treenode {
	int	val;
	struct treenode *left;
	struct treenode *right;
};

static struct treenode *head, *last;

static void do_conv(struct treenode *root)
{
	if (!root)
		return;
	do_conv(root->left);
	if (!head) {
		head = last = root;
		root->left = 0;
	} else {
		last->right = root;
		root->left = last;
		last = root;
	}
	do_conv(root->right);
}

struct treenode *conv_bst2list(struct treenode *root)
{
	head = 0;
	do_conv(root);
	return(head);
}

main(){}
