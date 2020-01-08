#include "libmx.h"

void mx_print_path(t_tool *d) {
    int num, **path;
    
    for (int i = 0; i < d->size; i++){
        for (int j = i + 1; j < d->size; j++) {
            num = mx_count_steps(d, i, j);
            path = mx_general_router(d, num, i, j);
            for (int c = 0; c < num; c++) {
                if (c > 0 && mx_memcmp(path[c - 1], path[c], d->size) == 0)
                    break;
                d->file = mx_file_printer(d, path, c);
                mx_render_out(d, path[c], i, j);
                mx_del_strarr(&d->file);
            }
        }
    }       
}
