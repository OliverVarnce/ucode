#include "libmx.h"

int **mx_matrixbuilder(t_construct *d, int num) {
    int **paths = malloc(num * sizeof(int *));

    for (int a = 0; a < num; a++) {
        paths[a] = malloc((d->size + 1) * sizeof(int));
        for (int k = 0; k < d->size + 1; k++)
            paths[a][k] = -1;
    }
    return paths;
}
