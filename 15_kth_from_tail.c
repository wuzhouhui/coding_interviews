struct listnode {
	int	val;
	struct listnode *next;
};

struct listnode *kth_from_tail(struct listnode *head, int k)
{
	if (k <= 0 || !head)
		return(0);
	struct listnode *p1, *p2;
	int	i;
	p2 = head;
	for (i = 1; i < k; i++)
		if (p2)
			p2 = p2->next;
		else
			break;
	if (!p2)
		return(0);
	p1 = head;
	while (p2->next) {
		p2 = p2->next;
		p1 = p1->next;
	}
	return(p1);
}

int main(void)
{
}
