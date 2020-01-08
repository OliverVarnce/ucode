#include "libmx.h"

int **mx_create_matrix(int s) {
    int infinity = 200000000;
    int **result = (int**) malloc(sizeof(int*) * s);

    for(int i = 0; i < s; i++) {
        result[i] = (int*)malloc(sizeof(int) * s);
        for(int j = 0; j < s; j++)
            result[i][j] = infinity;
    }
    for(int i = 0; i < s; i++)
        result[i][i] = 0;
    return result;
}
