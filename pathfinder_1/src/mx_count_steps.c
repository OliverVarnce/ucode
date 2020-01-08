#include "libmx.h"

int mx_count_steps(t_construct *d, int a, int b) {
    int weight = d->dist[b][a], c =  0, tmp;

    for (int i = 0; i < d->size; i++) {
        if (d->matrix[b][i] != 0 && d->matrix[b][i] != 200000000) {
            tmp = weight - d->matrix[b][i]; 
            if (tmp == d->dist[i][a])
                c++;
        }
    }
    b--;
    if (a < b)
        c = c + (mx_count_steps(d, a, b) - 1);
    return c;
}
