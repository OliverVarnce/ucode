#include "pathfinder.h"

void mx_parse_distance_isl(t_island *isl, t_file *file) {
    mx_parse_islands(isl, file->str, file->count);
    mx_parse_dist(isl, file->file, file->count, file->str);
   // mx_del_strarr(str);
    free(file->file);
}
