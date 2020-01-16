#include "pathfinder.h"

static void init(bool *active_islands, int count, int i);

t_result *mx_create_first_itter_list(t_island *p, int i) {
    t_result *lst;
    int way[2];
	int way_dist[1];
	unsigned int dist = 0;

	for (int k = 0; k < p[i].routes_count; k++) {
		way[0] = p[i].index_name;
		way[1] = p[i].d[k].index_point;
		way_dist[0] = p[i].d[k].dist;
		dist = p[i].d[k].dist;
		if (k == 0)
			lst = mx_create_result(way, 2, way_dist, p[i].d[k].dist);
		else
			mx_push_back_res(&lst, way, 2, way_dist, p[i].d[k].dist);
	}
	return lst;
}

void mx_create_res_active_island(t_result *lst, t_island p,
	bool *active_islands) {
	for (int k = 0; k < p.routes_count; k++) {
		if (active_islands[p.d[k].index_point]) {
			int *way = (int *)malloc(sizeof(int) * (lst->count + 1));
			int *way_dist = (int *)malloc(sizeof(int) * (lst->count));
			unsigned int dist = lst->dist + p.d[k].dist;
		
			way = mx_memcpy(way, lst->way, sizeof(int) * lst->count);
			way[lst->count] = p.d[k].index_point;
			way_dist = mx_memcpy(way_dist, lst->way_dist
				, sizeof(int) * (lst->count - 1));
			way_dist[lst->count - 1] = p.d[k].dist;
			mx_push_back_res(&lst, way, lst->count + 1, way_dist, dist);
			free(way);
			free(way_dist);
		}
	}
}

void mx_res_empty(t_result *res) {
	res = (t_result *)malloc(sizeof(t_result));
	mx_memset(res, 0, sizeof(res));
}

t_result *mx_algorithm(t_island *p, t_result *l, int count, int itter) {
	bool active_islands[count];
	t_result *res = NULL;

	init(active_islands, count, itter);
	for (int k = 0; l; k++) {
		l = mx_sort_list_result(l);
		int i = l->way[l->count - 1];

		mx_create_res_active_island(l, p[i], active_islands);
		if (l->count == 2 && k == 0 && l->way[0] < l->way[l->count - 1])
			res = mx_create_result(l->way, l->count, l->way_dist, l->dist);
		else if (l->way[0] < l->way[l->count - 1])
			mx_push_back_res(&res, l->way, l->count, l->way_dist, l->dist);
		mx_pop_elem_of_list(l);
		mx_pop_front_result(&l);
		active_islands[i] = false;
	}
	if (!res)
		mx_res_empty(res);
	return res;
}

static void init(bool *active_islands, int count, int i) {
	for (int it = 0; it < count; it++)
		active_islands[it] = true;
	active_islands[i] = false;
}
