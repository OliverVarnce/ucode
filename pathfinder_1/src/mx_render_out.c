#include "libmx.h"

void mx_render_out(t_tool *d, int *path, int i, int j) {
    mx_printstr("========================");
    mx_printstr("================\nPath: ");
    mx_printstr(d->top[i]);
    mx_printstr(" -> ");
    mx_printstr(d->top[j]);
    mx_printstr("\nRoute: ");
    mx_print_strarr(d->file, " -> ");
    mx_printstr("Distance: ");
    if(mx_arr_size(d->file) == 2)
        mx_printint(d->dist[i][j]);
    else 
        mx_distance_out(d, path, i, j);
    mx_printstr("\n====================");
    mx_printstr("====================\n");
}
