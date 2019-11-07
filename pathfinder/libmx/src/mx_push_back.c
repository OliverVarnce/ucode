#include "libmx.h"

void mx_push_back(t_list **list, void *data){
	t_list *node = mx_create_node(data);
	t_list *n = *list;

	while (node -> next != NULL)
		n = n -> next;
		n -> next = node;

}
