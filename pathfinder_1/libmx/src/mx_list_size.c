#include "libmx.h"

int mx_list_size(t_list *list) 
{
    t_list *temp = list;
    int i;

    for (i = 0;temp != NULL; i++)
            temp = temp->next;
    return i;
}
