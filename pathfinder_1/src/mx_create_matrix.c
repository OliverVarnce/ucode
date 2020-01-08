#include "libmx.h"

int **mx_create_matrix(int s) {
    int max = 99999999;
    int **result = (int**)malloc(sizeof(int*) * s);

    for(int i = 0; i < s; i++) {
        result[i] = (int*)malloc(sizeof(int) * s);
        for(int j = 0; j < s; j++)
            result[i][j] = max;
    }
    for(int i = 0; i < s; i++)
        result[i][i] = 0;
    return result;
}
