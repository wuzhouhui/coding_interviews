struct ListNode {
	int	val;
	struct ListNode *next;
};

static struct ListNode *findcomm(struct ListNode *h1, struct ListNode *h2)
{
	int l1, l2;
	struct ListNode *p;
	if (h1 == 0 || h2 == 0)
		return(0);
	for (l1 = 0, p = h1; p; p = p->next)
		l1++;
	for (l2 = 0, p = h2; p; p = p->next)
		l2++;
	if (l1 > l2) {
		l1 -= l2;
		while (l1-- > 0)
			h1 = h1->next;
	} else if (l1 < l2) {
		l2 -= l1;
		while (l2-- > 0)
			h2 = h2->next;
	}
	while (h1 != h2) {
		h1 = h1->next;
		h2 = h2->next;
	}
	return(h1);
}

int main(void)
{
}
