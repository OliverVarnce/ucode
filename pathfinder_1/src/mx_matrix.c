#include "libmx.h"

int **mx_matrix(char **top, char **str, int s) {
    int i = 0, j = 0;
    int **matrix = mx_create_matrix(s);

    for (int line = 1; str[line] != NULL; line++) {
        i = 0;
        j = 0;
        while (i < s) {
            if (mx_memcmp(str[line], top[i], mx_strlen(top[i])) == 0)
                break;
            i++;
        }
        char *isl2 = mx_memchr(str[line], '-', mx_strlen(str[line]));
        while (j < s) {
            if (mx_memcmp(isl2 + 1, top[j], mx_strlen(top[j])) == 0)
                break;
            j++;
        }
        matrix[i][j] = mx_get_num_cpl(str[line]);
        matrix[j][i] = matrix[i][j];
    }
    return matrix;
}
