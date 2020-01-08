#include "libmx.h"

static int next_top(t_tool *data, int from, int to, int paths);
static int previos_top(t_tool *data, int from, int to);

int **mx_general_router(t_tool *d, int num, int from, int to) {
    int **paths, k = 1, end, tmp;

    paths = mx_matrixbuilder(d, num);
    for (int a = 0; a < num; a++) {
        end = to;
        paths[a][k - 1] = to;
        while(end != from) {
            paths[a][k] = previos_top(d, from, end);
            if (a > 0 && paths[a][k] == paths[a - 1][k]) {
                tmp = next_top(d, from, end, paths[a][k] + 1);
                if (tmp != -2)
                    paths[a][k] = tmp;
            }
            end = paths[a][k];
            k++;
        } 
        k = 1;
    }
    return paths;
}

static int next_top(t_tool *data, int from, int to, int paths) {
    int weight, temp;
    
    weight = data->dist[to][from];
    for (int i = paths; i < data->size; i++) {
        if (data->matrix[to][i] != 0 && data->matrix[to][i] != 999999999) {
            temp = weight - data->matrix[to][i];
            if (temp == data->dist[i][from])
                return i;
        }
    }
    return -2;
}

static int previos_top(t_tool *data, int from, int to) {
    int weight, temp;

    weight = data->dist[to][from];
    for (int i = 0; i < data->size; i++) {
        if (data->matrix[to][i] != 0 && data->matrix[to][i] != 999999999) {
            temp = weight - data->matrix[to][i];
            if (temp == data->dist[i][from])
                return i;
        }
    }
    return -2;
}
