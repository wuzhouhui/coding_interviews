#include <stdlib.h>

struct RandomListNode {
	int	label;
	struct RandomListNode *next;
	struct RandomListNode *random;
};

static void clonenext(struct RandomListNode *head)
{
	struct RandomListNode *p;
	while (head) {
		p = malloc(sizeof(*p));
		p->label = head->label;
		p->next = head->next;
		head->next = p;
		head = p->next;
	}
}

static void clonerandom(struct RandomListNode *head)
{
	struct RandomListNode *p;
	while (head) {
		p = head->next;
		p->random = head->random ? head->random->next : NULL;
		head = p->next;
	}
}

static struct RandomListNode *splitlist(struct RandomListNode *head)
{
	struct RandomListNode *newhead = NULL;
	struct RandomListNode **prep = &newhead;
	while (head) {
		*prep = head->next;
		prep = &(*prep)->next;
		head->next = *prep;
		head = *prep;
	}
	return(newhead);
}

struct RandomListNode *copyRandomList(struct RandomListNode *head)
{
	if (!head)
		return(0);
	struct RandomListNode *newhead;

	clonenext(head);
	clonerandom(head);
	newhead = splitlist(head);
	return(newhead);
}

main(){}
