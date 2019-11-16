#include "libmx.h"

void mx_del_strarr(char ***arr) {
    int i = 0;
    char **array = *arr;
    while (array[i] != NULL) {
        mx_strdel(&array[i]);
        i++;
    }
    *arr = NULL;
}
