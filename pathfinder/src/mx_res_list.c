#include "pathfinder.h"

t_result  *mx_create_result(int *way, int count, int *way_dist, int dist) {
	t_result *res = (t_result*)malloc(sizeof(t_result));

	res->way = (int*)malloc(sizeof(int) * count);
	res->way_dist = (int*)malloc(sizeof(int) * (count - 1));
 	res->way = mx_memcpy(res->way, way, sizeof(int) * count);
	res->way_dist = mx_memcpy(res->way_dist, way_dist
		, sizeof(int) * (count - 1));
	res->dist = dist;
	res->count = count;
	res->next = NULL;
	return res;
}

void mx_pop_front_result(t_result **head) {
	t_result *current = NULL;

	if (head && *head) {
		current = (*head)->next;
		free((*head)->way);
		free((*head)->way_dist);
		free(*head);
		*head = current;
	}
}

void mx_push_back_res(t_result **list, int *way, int count
	, int *way_dist, int dist) {
	if (list) {
		t_result *new = mx_create_result(way, count, way_dist, dist);

		if (*list) { 
			t_result *current = *list;

			while(current->next != NULL) {
				current = current->next;
			}
			current->next = new;
		}
		else 
			*list = new;
	}
}

void mx_push_front_result(t_result **list, int *way, int count
	, int *way_dist, int dist) {
	t_result *new_head = mx_create_result(way, count, way_dist, dist);

	new_head->next = *list;
	*list = new_head;
}

int mx_list_size_res(t_result *list) {
	int i = 0;

	if (list) {
		t_result *tmp = list;

		while (tmp != NULL){
			i++;
			tmp = tmp->next;
		}
	}
	return i;	
}
