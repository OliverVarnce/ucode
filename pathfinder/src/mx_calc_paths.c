#include "pathfinder.h"

void mx_calc_paths(t_island *isl, t_result **lst, t_result **res, t_file *file) {
    mx_parse_distance_isl(isl, file);
    for (int i = 0; i < file->count - 1; i++) {
        lst[i] = mx_create_first_itter_list(isl, i);
        res[i] = mx_algorithm(isl, lst[i], file->count, i);
    }
    mx_print_paths(res, isl, file->count);
}
