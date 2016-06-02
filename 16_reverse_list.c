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

int main(void)
{
}
