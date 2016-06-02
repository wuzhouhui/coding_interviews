struct listnode {
	int	val;
	struct listnode *next;
};

struct listnode *reverse_list(struct listnode *head)
{
	struct listnode *newhead, *t;
	newhead = 0;
	while (head) {
		t = head;
		head = head->next;
		t->next = newhead;
		newhead = t;
	}
	return(newhead);
}

struct listnode *reverse_list2(struct listnode *head)
{
	if (!head || !head->next)
		return(head);
	struct listnode *newhead = reverse_list2(head->next);
	head->next->next = head;
	head->next = 0;
	return(newhead);
}

int main(void)
{
}
