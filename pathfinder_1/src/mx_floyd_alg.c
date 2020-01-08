#include "libmx.h"

int **mx_floyd_alg(int **matrix, int s) {
    int i, j, k, infinity = 999999999, **dest = mx_create_matrix(s);
    
    for (i = 0; i < s; i++) 
        for (j = 0; j < s; j++)
            dest[i][j] = matrix[i][j];
            
    for (k = 0; k < s; k++) { 
        for (i = 0; i < s; i++) { 
            for (j = 0; j < s; j++) {
                if (dest[i][k] < infinity && dest[i][k] + dest[k][j] < dest[i][j]) {
                    dest[i][j] = dest[i][k] + dest[k][j];
                }
            }
        } 
    }
    return dest;
}
