#include <stdlib.h>

struct ListNode {
	int	m_nValue;
	struct ListNode *m_pNext;
};

static struct ListNode *DeleteNode(struct ListNode *head, struct ListNode *p)
{
	if (!head || !p)
		return;
	struct ListNode *t, **pp;
	if (p->m_pNext) {
		p->m_nValue = p->m_pNext->m_nValue;
		t = p->m_pNext;
		p->m_pNext = t->m_pNext;
		free(t);
		return(head);
	}

	pp = &head;
	while (*pp != p)
		pp = &(*pp)->m_pNext;
	*pp = NULL;
	free(p);
	return(head);
}

int main(void)
{
}
