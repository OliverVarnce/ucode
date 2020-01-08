#include "libmx.h"

static t_construct *create_struct(int s, int **m, int **d, char **t);

int main(int argc, char **argv) {
    char **file_str, **top;
    int **m, **min_dast, s;
    t_construct *d;

    if (argc != 2) 
        mx_printerrmess(INVALID_ARGS, NULL);
    file_str = mx_filereader(argv);
    mx_check_numofislds(file_str[0]);
    s = mx_atoi(file_str[0]);
    top = mx_read_args(file_str, s);
    m = mx_matrix(top, file_str, s);
    min_dast = mx_floyd_alg(m, s);
    d = create_struct(s, m, min_dast, top);
    mx_result_printer(d);
    free(d);
    return 0;
}

static t_construct *create_struct(int s, int **m, int **d, char **t) {
    t_construct *data= malloc(sizeof(t_construct));
    
    data->size = s;
    data->matrix = m;
    data->dist = d;
    data->top = t;
    return data;
}
