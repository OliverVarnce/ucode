#include "libmx.h"

void mx_start_isld(char *str, char **result, int *num) {
    int end = mx_get_char_index(str, '-');
    char *res = mx_strndup(str, end);
    int index = 0;

    while (index < *num && result[index] != NULL) {
        if (mx_strcmp(result[index], res) == 0) {
            free(res);
            res = NULL;
            break;
        }
        index++;
    }    
    if (res != NULL) {
        result[*num] = res;
        (*num)++;
    }
}
