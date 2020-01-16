#include "pathfinder.h" 

void mx_parse_dist(t_island *p, char *f, int count, char **str) {
	for (int i = 0; i < count; i++) {
		int k = 0;

		p[i].routes_count = mx_count_substr(f, p[i].name);
		p[i].d = (t_dist *)malloc(sizeof(t_dist) * p[i].routes_count);
		for (int j = 1; str[j]; j++) {
			char **s1 = mx_strsplit(str[j], '-');
			char **s2 = mx_strsplit(s1[1], ',');

			if (mx_strcmp(p[i].name, s1[0]) == 0) {
				p[i].d[k].index_point = mx_index_raw(s2[0], count, p);
				p[i].d[k].point = mx_strdup(p[p[i].d[k].index_point].name);
				p[i].d[k++].dist = mx_atoi(s2[1]);
			}
			if (mx_strcmp(p[i].name, s2[0]) == 0) {
				p[i].d[k].index_point = mx_index_raw(s1[0], count, p);
				p[i].d[k].point = mx_strdup(p[p[i].d[k].index_point].name);
				p[i].d[k++].dist = mx_atoi(s2[1]);
			}
			mx_double_del(s1, s2);
		}
	}
}
