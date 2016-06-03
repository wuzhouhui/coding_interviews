struct listnode {
	int	val;
	struct listnode *next;
};

struct listnode *mergelist(struct listnode *head1, struct listnode *head2)
{
	struct listnode *merged, *t, **prep;

	merged = 0;
	prep = &merged;
	while (head1 && head2) {
		if (head1->val < head2->val) {
			t = head1;
			head1 = head1->next;
		} else {
			t = head2;
			head2 = head2->next;
		}
		t->next = 0;
		*prep = t;
		prep = &t->next;
	}
	if (head1)
		*prep = head1;
	if (head2)
		*prep = head2;
	return(merged);
}

int main(void)
{
}
