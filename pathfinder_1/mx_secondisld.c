#include "libmx.h"

void mx_secondisld(char *str, char **result, int *n) {
    int start = mx_get_char_index(str, '-');
    int end = mx_get_char_index(str, ',');
    char *res = mx_strndup(&str[start + 1], end - start - 1);
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
        (*n)++;
    }
}
