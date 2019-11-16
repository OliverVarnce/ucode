#include "libmx.h"
t_list *mx_create_node(void *data);

void mx_push_back(t_list **list, void *data){
	t_list *n = *list;

	if (*list == NULL)
		return;

	while (n -> next)
		n = n -> next;
		
	n->next = mx_create_node(data);
}
