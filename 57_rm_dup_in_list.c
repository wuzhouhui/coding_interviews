#include <stdlib.h>

struct ListNode {
	int	val;
	struct ListNode *next;
};

static struct ListNode *rmdup(struct ListNode *head)
{
	struct ListNode *newhead;
	struct ListNode **pprev = &newhead;
	while (head) {
		struct ListNode *next = head;
		head = head->next;
		int flag = 1;
		while (head && head->val == next->val) {
			struct ListNode *t = head;
			head = head->next;
			free(t);
			flag = 0;
		}
		if (flag) {
			*pprev = next;
			pprev = &next->next;
		} else {
			free(next);
		}
	}
	*pprev = 0;
	return(newhead);
}
main(){}
