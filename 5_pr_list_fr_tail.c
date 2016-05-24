#include <stdlib.h>

struct ListNode {
	int	m_nKey;
	struct ListNode *m_pNext;
};

static void print_list_from_tail(struct ListNode *head)
{
	struct ListNode *nhead, *t;

	nhead = 0;
	while (head) {
		t = malloc(sizeof(*t));
		t->m_nKey = head->m_nKey;
		t->m_pNext = nhead;
		nhead = t;
		head = head->m_pNext;
	}
	while (nhead) {
		t = nhead;
		nhead = nhead->m_pNext;
		/*
		 * TODO
		 * print t->val
		 */
		free(t);
	}
}

int main(void)
{
}
