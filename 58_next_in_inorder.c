struct ListNode {
	int	val;
	struct ListNode *par;
	struct ListNode *left;
	struct ListNode *right;
};

static struct ListNode *findnext(struct ListNode *root, struct ListNode *node)
{
	if (!node || !root)
		return(0);
	if (node->right) {
		node = node->right;
		while (node->left)
			node = node->left;
		return(node);
	}
	while (node->par) {
		if (node->par->left == node)
			return(node->par);
		else
			node = node->par;
	}
	return(0);
}

main(){}
