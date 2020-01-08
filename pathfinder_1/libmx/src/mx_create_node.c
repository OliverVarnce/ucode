#include "libmx.h"

 t_list *mx_create_node(void *data){
 	struct s_list *last = (struct s_list*)malloc(sizeof(struct s_list));
 	last->data = data;
 	last->next = NULL;
 	return last;
 }
