#include "prototype.h"

struct LinkedList *find(struct LinkedList *head, char target[20]) {
	if (head == 0)
		return 0;
	else if (strcmp(head->name, target) == 0)
		return head;
	else {
		struct LinkedList *b = find(head->back_head, target);
		struct LinkedList *n = find(head->next, target);
		return b ? b : (n ? n : 0);
	}
}
