#include <stdlib.h>
#include <stdio.h>

struct BinaryTreeNode {
	int	m_nValue;
	struct BinaryTreeNode *m_pLeft;
	struct BinaryTreeNode *m_pRight;
};

static void trav_tree(const struct BinaryTreeNode *root)
{
	if (!root)
		return;
	trav_tree(root->m_pLeft);
	printf("%d\n", root->m_nValue);
	trav_tree(root->m_pRight);
}

static struct BinaryTreeNode *
reconst_tree(const int *preorder, const int *inorder, int len)
{
	int	i;
	struct BinaryTreeNode *root;

	if (len <= 0)
		return(NULL);
	root = malloc(sizeof(*root));
	root->m_nValue = preorder[0];
	for (i = 0; i < len; i++)
		if (inorder[i] == root->m_nValue)
			break;
	root->m_pLeft = reconst_tree(preorder + 1, inorder, i);
	root->m_pRight = reconst_tree(preorder + 1 + i, inorder + i + 1,
			len - i - 1);
	return(root);
}

int main(void)
{
	int pre[] = { 1, 2, 4, 7, 3, 5, 6, 8, };
	int in[] = {4, 7, 2, 1, 5, 3, 8, 6, };
	struct BinaryTreeNode *root =
		reconst_tree(pre, in, sizeof(pre) / sizeof(pre[0]));
	trav_tree(root);
	return(0);
}
