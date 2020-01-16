#include "pathfinder.h"

int main(int argc, char **argv) {
    t_main *main = (t_main *)malloc(sizeof(t_main));
    main->argc = argc;
    main->argv = argv;
	if (mx_check_file(main)) {
        t_file *file = malloc(sizeof(t_file));
        file->file = mx_file_to_str(argv[1]);
        file->str = mx_strsplit(file->file, '\n');
        file->count = mx_atoi(file->file);
        mx_check_fillin(file);
        t_result **lst = (t_result **) malloc(sizeof(t_result * ) * (file->count - 1));
        t_result **result = (t_result **) malloc(sizeof(t_result * ) * (file->count - 1));
        t_island *isl = (t_island *) malloc(sizeof(t_island) * (file->count));
        mx_calc_paths(isl, lst, result, file);
    }
	return 0;
}
