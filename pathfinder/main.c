#include "libmx.h"

int main(int argc, char **argv) {
    /*char **arr_islands = NULL;*/
    char *f_totext = NULL;
    /*int cnt_islands = 0;
    int *matrix;*/

    if (argc != 2)
        mx_printerrmess(INVALID_ARGS, NULL);
    f_totext = mx_file_to_str(*(argv + 1));
    mx_parse_text(f_totext);
    /*arr_islands = mx_parse_text_value(f_totext);
    matrix = mx_get_matrix(arr_islands, f_totext);
    cnt_islands = mx_arr_size(arr_islands);
    t_graph *graph = mx_get_graph_matrix(matrix, cnt_islands);
    t_list *all_paths = mx_create_node(".");
    for (int i = 0; i < islands_count; i++) {
        for (int j = 0; j < islands_count; j++)
            mx_push_back(&all_paths, mx_get_path_bt_islands(graph, i, j, islands_count));
    }
    mx_sort_lists(all_paths);
    mx_print_shortest_path(all_paths, matrix, cnt_islands, arr_islands);*/
}
