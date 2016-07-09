struct TreeNode {
	int	val;
	struct TreeNode *left;
	struct TreeNode *right;
};

static int depth(const struct TreeNode *root)
{
	if (!root)
		return(0);
	int l = depth(root->left);
	int r = depth(root->right);
	return(l > r ? ++l : ++r);
}

int main(void)
{
}
