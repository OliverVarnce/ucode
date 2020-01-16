#include "pathfinder.h"

t_result *mx_sort_list_result(t_result *lst) {
	int i = 0;
	int size = mx_list_size_res(lst);
	t_result *new = lst;

	if (i != size - 1) {
		while (i < size) {
			if (lst->dist > lst->next->dist)
                mx_swap_islds(lst);
			lst = lst->next;
			i++;
			if (i == size - 1) {
				lst = new;
				i = 0;
				size--;
			}
		}
	}
	return new;
}

static void mx_check(t_result *lst) {
	int j = 0;

	if (lst->way[lst->count - 1]
		== lst->next->way[lst->next->count - 1]) {
		while (lst->way[j] == lst->next->way[j])
			j++;
		if (lst->way[j] > lst->next->way[j])
            mx_swap_islds(lst);
	}
}

void mx_sort_paths_by_size(t_result *lst) {
	int i = 0;
	int size = mx_list_size_res(lst);
	t_result *new = lst;

	if (i != size - 1)
		while (i < size) {
			mx_check(lst);
			lst = lst->next;
			i++;
			if (i == size - 1) {
				lst = new;
				i = 0;
				size--;
			}
		}
}


void mx_sort_paths_by_bounces(t_result *lst) {
	int i = 0;
	int size = mx_list_size_res(lst);
	t_result *new = lst;

	if (i != size - 1) {
		while (i < size) {
			if (lst->way[lst->count - 1]
				> lst->next->way[lst->next->count - 1])
                mx_swap_islds(lst);
			lst = lst->next;
			i++;
			if (i == size - 1) {
				lst = new;
				i = 0;
				size--;
			}
		}
	}
}

void mx_sort_paths_by_fifo(t_result *lst) {
	int i = 0;
	int size = mx_list_size_res(lst);
	t_result *new = lst;

	if (i != size - 1) {
		while (i < size) {
			if (lst->way[lst->count - 1]
				== lst->next->way[lst->next->count - 1])
				if (lst->count < lst->next->count) 
					mx_swap_islds(lst);
			lst = lst->next;
			i++;
			if (i == size - 1) {
				lst = new;
				i = 0;
				size--;
			}
		}
	}
}
