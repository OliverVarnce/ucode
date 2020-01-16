#include "pathfinder.h"

void mx_swap_el_int(int **s1, int **s2) {
	int *tmp;

	tmp = *s1;
	*s1 = *s2;
	*s2 = tmp;
}


void mx_swap_int(int *a, int *b) {
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void mx_swap_islds(t_result *lst) {
	mx_swap_int(&(lst->dist), &(lst->next->dist));
	mx_swap_int(&(lst->count), &(lst->next->count));
	mx_swap_el_int(&(lst->way_dist), &(lst->next->way_dist));
	mx_swap_el_int(&(lst->way), &(lst->next->way));
}
