#include "libmx.h"

void mx_firstisld(char *str, char **result, int *n) {
    int end = mx_get_char_index(str, '-');
    char *res = mx_strndup(str, end);
    int i = 0;

    while (i < *n && result[i] != NULL) {
        if (mx_strcmp(result[i], res) == 0) {
            free(res);
            res = NULL;
            break;
        }
        i++;
    }    
    if (res != NULL) {
        result[*n] = res;
        *n++;
    }
}
