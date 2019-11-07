#include "libmx.h"

void mx_pop_back(t_list **list) {
	 if (list != NULL) {
       t_list *tmp = *list;
       while (tmp->next->next != NULL)
           tmp = tmp->next;
       free(tmp->next->data);
       free(tmp->next);
       tmp->next = NULL;
   }
}
