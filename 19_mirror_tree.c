struct treenode {
	int	val;
	struct treenode *left;
	struct treenode *right;
};

void mirror(struct treenode *root)
{
	if (!root)
		return;
	struct treenode *t = root->left;
	root->left = root->right;
	root->right = t;
	mirror(root->left);
	mirror(root->right);
}

int main(void)
{
}
