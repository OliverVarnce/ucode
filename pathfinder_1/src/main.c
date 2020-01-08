#include "libmx.h"

static t_tool *inicialize_struct(int s, int **m, int **d, char **t);

int main(int argc, char **argv) {
    char **file_str;
    int size;
    char **top;
    int **m;
    int **min_dast;
    t_tool *d;

    if (argc != 2) 
        mx_printerrmess(INVALID_ARGS, NULL);
    
    file_str = mx_filereader(argv);
    size = atoi(file_str[0]); //pomenyat potom (segfoltit)
    top = mx_read_args(file_str, size);
    m = mx_matrix(top, file_str, size);
    min_dast = mx_floyd_alg(m, size);
    d = inicialize_struct(size, m, min_dast, top);
    mx_result_printer(d);
    free(d);
    return 0;
}

static t_tool *inicialize_struct(int s, int **m, int **d, char **t) {
    t_tool *data= malloc(sizeof(t_tool));
    
    data->size = s;
    data->matrix = m;
    data->dist = d;
    data->top = t;
    return data;
}
