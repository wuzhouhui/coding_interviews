#include <stdlib.h>

struct treenode {
	int	val;
	struct treenode *left;
	struct treenode *right;
};

static struct treenode *do_deser(const int *nums, int *start, int len)
{
	if (*start >= len)
		return(NULL);
	if (nums[*start] < 0) {
		(*start)++;
		return(NULL);
	}
	struct treenode *node = malloc(sizeof(*node));
	node->val = nums[(*start)++];
	node->left = do_deser(nums, start, len);
	node->right = do_deser(nums, start, len);
	return(node);
}

struct treenode *deserialize(const int *nums, int len)
{
	if (nums == NULL || len <= 0)
		return(NULL);
	int start = 0;
	return(do_deser(nums, &start, len));
}

int main(void)
{
	return(0);
}
