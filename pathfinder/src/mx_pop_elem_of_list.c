#include "pathfinder.h"

int mx_find_dex(t_result *lst) {
	int i = 0;

	if (!lst)
		return -1;
	for (t_result *tmp1 = lst; tmp1; tmp1 = tmp1->next) {
		i = 0;
		for (t_result *tmp2 = lst; tmp2; tmp2 = tmp2->next) {
			if ((tmp1->way[tmp1->count - 1] == tmp2->way[tmp2->count - 1])
				&& tmp2->dist > tmp1->dist)
				return i;
			i++;
		}
	}
	return -1;
}

void mx_pop_back_res(t_result **head) {
	t_result *temp = NULL;

	if (head && *head && (*head)->next) {
		temp = *head;

		while (temp->next->next)
			temp = temp->next;
		free(temp->next->way);
		free(temp->next->way_dist);
		free(temp->next);
		temp->next = NULL;
	}
	else if (head && *head) {
		free((*head)->way);
		free((*head)->way_dist);
		free(*head);
		*head = NULL;
	}
}

void del_el_list(t_result *tmp) {
	free(tmp->way);
	free(tmp->way_dist);
	free(tmp);
}

void mx_pop_elem_of_list(t_result *lst) {
	if (lst) {
		t_result *tmp = lst;
		t_result *prv;

		while (mx_find_dex(lst) != -1) {
			tmp = lst;
			if (mx_find_dex(lst) == 0)
				mx_pop_front_result(&lst);
			else if (mx_find_dex(lst) == mx_list_size_res(lst) - 1)
				mx_pop_back_res(&lst);
			else {
				for (int i = 0; i < mx_find_dex(lst); i++) {
					prv = tmp; 
         			tmp = tmp->next; 
				}
				prv->next = tmp->next; 
				del_el_list(tmp);
			}
		}
	}
}
