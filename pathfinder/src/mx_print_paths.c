#include "pathfinder.h"

void mx_print_route(t_result *lst, t_island *p, int count, int i) {
	mx_printstr("Route: ");
	mx_printstr(p[i].name);
	mx_printstr(" -> ");
	for (int k = 1; k < lst->count; k++) {
		for (int l = 0; l < count; l++) {
			if (lst->way[k] == p[l].index_name) {
				mx_printstr(p[l].name);
				if (k != lst->count - 1) 
					mx_printstr(" -> ");
				else
					mx_printchar('\n');
			}
		}
	}
}

void mx_print_num(t_result *lst) {
	char *itoa = mx_itoa(lst->dist);

	mx_printstr(itoa);
	free(itoa);
}

void mx_print_dist(t_result *lst) {
	mx_printstr("Distance: ");
	if (lst->count == 2)
		mx_print_num(lst);
	else {
		for (int n = 0; n < lst->count - 1; n++) {
			char *itoa = mx_itoa(lst->way_dist[n]);

			mx_printstr(itoa);
			free(itoa);
			if (n != lst->count - 2)
				mx_printstr(" + ");
			else {
				mx_printstr(" = ");
				mx_print_num(lst);
			}
		}
	}
	mx_printchar('\n');
}

void mx_print_result(t_result *lst, t_island *p, int count) {
	while (lst) {
		for (int i = 0; i < count; i++) {
			if (lst->way[0] == p[i].index_name) {
                mx_print_ends();
				mx_printstr("Path: ");
				mx_printstr(p[i].name);
				mx_printstr(" -> ");
				for (int j = 0; j < count; j++) {
					if (lst->way[lst->count - 1] == p[j].index_name) {
						mx_printstr(p[j].name);
						mx_printchar('\n');
					}
				}
				mx_print_route(lst, p, count, i);
				mx_print_dist(lst);
                mx_print_ends();
			}
		}
		lst = lst->next;
	}
}

void mx_print_paths(t_result **res, t_island *p, int count) {
    for (int j = 0; j < count - 1; j++) {
        if (res[j]->dist != 0) {
            mx_sort_paths_by_bounces(res[j]);
            mx_sort_paths_by_fifo(res[j]);
            mx_sort_paths_by_size(res[j]);
            mx_print_result(res[j], p, count);
        }
    }
}
